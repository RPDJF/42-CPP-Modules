#include "./BitcoinExchange.hpp"

static void fillDb(std::map<std::string, double>& db, const std::string& data) {
	std::ifstream db_file(data.c_str());
	if (!db_file.good())
		throw std::runtime_error("couldn't open '" + data + "' data file");
	std::string line;
	std::string key;
	std::string strvalue;
	double value;
	size_t sep;
	std::getline(db_file, line); // ignore firstline

	while (std::getline(db_file, line)) {
		sep = line.find(',');
		if (sep == std::string::npos) {
			std::cerr << C_RED << "Error (data input): " << "not a valid line => " << line << C_RESET << std::endl;
			continue;
		}
		key = line.substr(0, sep);
		if (!BitcoinExchange::dateChecker(key)) {
			std::cerr << C_RED << "Error (data input): " << "not a valid date => " << key << C_RESET << std::endl;
			continue;
		}
		strvalue = line.substr(key.size() + 1, line.size() - key.size() - 1);
		std::stringstream ss(strvalue);
		ss >> value;
		if (ss.fail()) {
			std::cerr << C_RED << "Error (data input): " << "failed parsing value in => " << line << C_RESET << std::endl;
			continue;
		}
		db[key] = value;
	}
}

BitcoinExchange::BitcoinExchange(const std::string& data) {
	fillDb(this->db_, data);
	if(this->db_.empty()) {
		this->smallest_year_ = -1;
		return;
	}
	std::stringstream ss(this->db_.begin()->first);
	ss >> this->smallest_year_;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy):
	db_(copy.db_),
	smallest_year_(copy.smallest_year_) {}

const BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& assign) {
	if(this == &assign)
		return *this;
	this->db_ = assign.db_;
	this->smallest_year_ = assign.smallest_year_;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {
	this->db_.clear();
}

// i think it may be the worst function i ever wrote on my whole life
// but hey, it works
static std::string getPreviousDate(const std::string& refDate, int smallestYear) {
	t_date date;
	std::string year;
	std::string month;
	std::string day;
	std::stringstream ss;
	size_t pos;

	// loading str date to t_date structure
	pos = refDate.find('-');
	year = refDate.substr(0, pos);
	ss.clear();
	ss.str(year);
	ss >> date.year;

	pos = refDate.find('-', pos + 1);
	month = refDate.substr(year.size() + 1, pos - (year.size() + 1));
	ss.clear();
	ss.str(month);
	ss >> date.month;

	pos = refDate.size() - year.size() - month.size();
	day = refDate.substr(year.size() + 1 + month.size() + 1);
	ss.clear();
	ss.str(day);
	ss >> date.day;

	// manually decrementing t_date structure
	if (date.day <= 1) {
		if (date.month <= 1) {
			if (date.year <= smallestYear) {
				return "";
			}
			date.year--;
			date.month = 12;
		}
		else
			date.month--;
		date.day = 31;
	} else {
		date.day--;
	}

	// building new date string
	ss.str("");
	ss.clear();
	ss << date.year;
	year = ss.str();
	ss.str("");
	ss.clear();
	ss << date.month;
	month = ss.str();
	if (month.length() == 1) month = "0" + month;
	ss.str("");
	ss.clear();
	ss << date.day;
	day = ss.str();
	if (day.length() == 1) day = "0" + day;
	return year + "-" + month + "-" + day;
}

const std::map<std::string, double>::const_iterator BitcoinExchange::retrieveData(const std::string& key) const {
	std::string q = key;

	if (this->db_.find(key) != this->db_.end()) return this->db_.find(key);
	while (!q.empty()) {
		for(std::map<std::string, double>::const_iterator date = this->db_.begin(); date != this->db_.end(); date++) {
			if (date->first.find(q) != std::string::npos) {
				return date;
			}
		}
		q = getPreviousDate(q, this->smallest_year_);
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
	std::stringstream ss;
	size_t pos;

	// loading str date to t_date structure
	pos = key.find('-');
	if (pos == std::string::npos) return false;
	year = key.substr(0, pos);
	ss.clear();
	ss.str(year);
	ss >> date.year;
	if (ss.fail()) return false;
	if (date.year < 1900) return false;

	pos = key.find('-', pos + 1);
	if (pos == std::string::npos) return false;
	month = key.substr(year.size() + 1, pos - (year.size() + 1));
	if(month.length() < 2) return false;
	ss.clear();
	ss.str(month);
	ss >> date.month;
	if (ss.fail()) return false;

	pos = key.size() - year.size() - month.size();
	day = key.substr(year.size() + 1 + month.size() + 1);
	if(day.length() < 2) return false;
	ss.clear();
	ss.str(day);
	ss >> date.day;
	if (ss.fail()) return false;

	// checking if valid str values
	for(size_t i = 0; i < year.length(); i++) {
		if(year[i] < '0' || year[i] > '9')
			return false;
	}
	for(size_t i = 0; i < month.length(); i++) {
		if(month[i] < '0' || month[i] > '9')
			return false;
	}
	for(size_t i = 0; i < day.length(); i++) {
		if(day[i] < '0' || day[i] > '9')
			return false;
	}

	// checking leap year
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