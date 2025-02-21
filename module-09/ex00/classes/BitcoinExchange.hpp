#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <map>
# include <sstream>
# include <climits>
# include <fstream>
# include <iostream>
# include <algorithm>
# include "../utils/colors.h"

typedef struct s_date {
	int year;
	int month;
	int day;
} t_date;

class BitcoinExchange {
	private:
		std::map<std::string, double> db_;
	public:
		BitcoinExchange(const std::string& data);
		BitcoinExchange(const BitcoinExchange&);
		const BitcoinExchange& operator=(const BitcoinExchange&);
		~BitcoinExchange();
		const std::map<std::string, double>::const_iterator retrieveData(const std::string&) const;
		const std::map<std::string, double>::const_iterator end() const;
		static bool dateChecker(const std::string&);
};

#endif