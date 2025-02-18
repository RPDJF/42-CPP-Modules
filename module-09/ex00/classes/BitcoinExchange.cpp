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

const std::map<std::string, double>::const_iterator BitcoinExchange::retrieveData(const std::string& data) const {
	return this->db_.find(data);
}

const std::map<std::string, double>::const_iterator BitcoinExchange::end() const {
	return this->db_.end();
}

bool BitcoinExchange::dateChecker(const std::string& key) {
	t_date date;
	std::string year;
	std::string month;
	std::string day;

	size_t pos;

	std::cout << "checking: " << key << std::endl;
	pos = key.find('-');
	if (pos == std::string::npos) return false;
	year = key.substr(0, pos);
	//std::cout << "year: '" << year << '\'' << std::endl;
	{
		std::stringstream ss(year);
		ss >> date.year;
	}

	pos = key.find('-', pos + 1);
	if (pos == std::string::npos) return false;
	month = key.substr(year.size() + 1, pos - (year.size() + 1));
	//std::cout << "month: '" << month << '\'' << std::endl;
	{
		std::stringstream ss(month);
		ss >> date.month;
	}

	pos = key.size() - year.size() - month.size();
	day = key.substr(year.size() + 1 + month.size() + 1);
	//std::cout << "day: '" << day << '\'' << std::endl;
	{
		std::stringstream ss(day);
		ss >> date.day;
	}

	std::cout << "date: '" << year << "-" << month << "-" << day << std::endl << std::endl;
	if (date.month < 1 || date.month > 12)
		return false;
	else if (date.year < 1)
		return false;
	if (date.month == 2) {
		if (date.year % 4 == 0) {
			if (date.year % 100 == 0 && date.year % 400) {
				// pas bisextile
			}
			// bisextile
		}
	}
	return true;
}