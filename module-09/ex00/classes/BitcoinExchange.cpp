#include "./BitcoinExchange.hpp"

static void fillDb(std::map<std::string, double>& db, const std::string& data) {
	std::ifstream db_file(data.c_str());
	if (!db_file.good())
		throw std::runtime_error("couldn't open '" + data + "' data file");
	std::string line;
	std::string key;
	std::string strvalue;
	double value;
	std::getline(db_file, line); // ignore firstline

	while (std::getline(db_file, line)) {
		key = line.substr(0, line.find(','));
		strvalue = line.substr(key.size() + 1, line.size() - key.size() - 1);
		std::stringstream ss(strvalue);
		ss >> value;
		if (ss.fail())
			throw std::runtime_error("failed parsing value: " + strvalue);
		db[key] = value;
	}
}

BitcoinExchange::BitcoinExchange(const std::string& data) {
	fillDb(this->db_, data);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy):
	db_(copy.db_) {}

const BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& assign) {
	if(this == &assign)
		return *this;
	this->db_ = assign.db_;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {
	this->db_.clear();
}

static const std::map<std::string, double>::const_iterator findClosest(const std::string& base, const std::map<std::string, double>::const_iterator it1, const std::map<std::string, double>::const_iterator it2) {
	int base_int;
	int index1_int;
	int index2_int;
	{
		std::string base_index = base.substr(base.find_last_of('-') + 1, base.size() - base.find_last_of('-') - 1);
		std::string index1 = it1->first.substr(it1->first.find_last_of('-') + 1, it1->first.size() - it1->first.find_last_of('-') - 1);
		std::string index2 = it2->first.substr(it2->first.find_last_of('-') + 1, it2->first.size() - it2->first.find_last_of('-') - 1);
		std::stringstream ss(base_index);
		ss >> base_int;
		ss.clear();
		ss.str(index1);
		ss >> index1_int;
		ss.clear();
		ss.str(index2);
		ss << index2;
		ss >> index2_int;
	}
	index1_int -= base_int;
	index2_int -= base_int;
	index1_int = std::abs(index1_int);
	index2_int = std::abs(index2_int);
	if (index1_int < index2_int)
		return it1;
	return it2;
}

const std::map<std::string, double>::const_iterator BitcoinExchange::retrieveData(const std::string& data) const {
	std::map<std::string, double>::const_iterator it = this->db_.begin();
	std::string q = data;

	while (!q.empty()) {
		for(std::map<std::string, double>::const_iterator date = this->db_.begin(); date != this->db_.end(); date++) {
			if (date->first.find(q) != std::string::npos) {
				if (it == this->db_.begin())
					it = date;
				else
					it = findClosest(data, it, date);
			}
		}
		if (it != this->db_.begin())
			return it;
		q = q.substr(0, q.size() - 1);
	}
	return this->db_.end();
}

const std::map<std::string, double>::const_iterator BitcoinExchange::end() const {
	return this->db_.end();
}

static bool isLeapYear(int year) {
	if (year % 4)
		return false;
	if (year % 100)
		return true;
	if (year % 400)
		return false;
	return true;
}

bool BitcoinExchange::dateChecker(const std::string& key) {
	t_date date;
	std::string year;
	std::string month;
	std::string day;

	size_t pos;

	pos = key.find('-');
	if (pos == std::string::npos) return false;
	year = key.substr(0, pos);
	{
		std::stringstream ss(key.substr(0, pos));
		ss >> date.year;
	}

	pos = key.find('-', pos + 1);
	if (pos == std::string::npos) return false;
	month = key.substr(year.size() + 1, pos - (year.size() + 1));
	{
		std::stringstream ss(month);
		ss >> date.month;
	}

	pos = key.size() - year.size() - month.size();
	day = key.substr(year.size() + 1 + month.size() + 1);
	{
		std::stringstream ss(day);
		ss >> date.day;
	}

	if (date.year < 1 || date.month < 1 || date.day < 1 || date.month > 12)
		return false;
	if (date.month == 2) {
		if (isLeapYear(date.year) && date.day > 29)
			return false;
		else if (!isLeapYear(date.year) && date.day > 28)
			return false;
	} else if (date.month == 4 || date.month == 6 || date.month == 9 ||date.month == 11) {
		if (date.day > 30)
			return false;
	} else {
		if (date.day > 31)
			return false;
	}
	return true;
}