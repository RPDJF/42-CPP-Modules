#include "utils/colors.h"
#include "classes/BitcoinExchange.hpp"
#include <iostream>
#include <stdexcept>
#include <climits>

static bool isValidValue(const std::string& valueRef) {
	bool isDecimal = false;
	for(size_t i = 0; i < valueRef.length(); i++) {
		if (valueRef[i] == '.') {
			if (isDecimal)
				return false;
			isDecimal = true;
		}
		else if (valueRef[i] < '0' || valueRef[i] > '9')
			return false;
	}
	return true;
}

static void runRoutine(char *file, BitcoinExchange& bitcoinExchange) {
	std::ifstream input_file(file);
	if (!input_file.good())
		throw std::runtime_error("couldn't open '" + std::string(file) + "' input file");
	std::string line;
	std::string key;
	std::string strvalue;
	double value;
	size_t sep;

	std::stringstream ss;
	while(std::getline(input_file, line)) {
		if (line.find("date | value") != std::string::npos)
			continue;
		sep = line.find(" | ");
		if (sep == std::string::npos) {
			std::cerr << C_RED << "Error: " << "bad input => " << C_RESET << line << std::endl;
			continue;
		}
		key = line.substr(0, sep);
		if (!BitcoinExchange::dateChecker(key)) {
			std::cerr << C_RED << "Error: " << "not a valid date => " << C_RESET << key << std::endl;
			continue;
		}
		strvalue = line.substr(key.size() + 3, line.size() - key.size() - 3);
		ss.clear();
		ss.str(strvalue);
		ss >> value;
		if (value < 0) {
			std::cerr << C_RED << "Error: " << "not a positive number." << C_RESET << std::endl;
			continue;
		} else if (value > 1000) {
			std::cerr << C_RED << "Error: " << "too large a number." << C_RESET << std::endl;
			continue;
		}
		if (!isValidValue(strvalue)) {
			std::cerr << C_RED << "Error: " << "not a valid value => " << C_RESET << line << std::endl;
			continue;
		}
		std::map<std::string, double>::const_iterator it = bitcoinExchange.retrieveData(key);
		if (it != bitcoinExchange.end()) {
			std::cout << key << " => " << value << " = " << it->second * value << std::endl;
		} else {
			std::cout << key << " => " << "not found" << std::endl;
		}
	}	
}

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << C_RED << "./btc <input.txt>" << C_RESET << std::endl;
		return 1;
	}
	try {
		BitcoinExchange bitcoinExchange("data.csv");
		runRoutine(argv[1], bitcoinExchange);
	} catch(const std::exception& e) {
		std::cerr << C_RED << "Error: " << e.what() << C_RESET << std::endl;
	}
}