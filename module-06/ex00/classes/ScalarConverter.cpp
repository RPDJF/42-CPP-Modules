#include "./ScalarConverter.hpp"

static bool formatChecker(const std::string &param) {
	size_t i = 0;
	bool decimalOverflow = false;
	bool floatOverflow = false;
	const char *str = param.c_str();

	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '+' || str[i] == '-')
		return false;
	while (str[i] && ((str[i] >= '0' && str[i] <= '9') || str[i] == '.' || str[i] == 'f')) {
		if ((str[i] == '.' || str[i] == 'f') && (i == 0 || (str[0] < '0' || str[0] > '9'))) {
			return false;
		}
		else if (str[i] == '.') {
			if (decimalOverflow) return false;
			else decimalOverflow = true;
		}
		else if (str[i] == 'f') {
			if (floatOverflow) return false;
			else floatOverflow = true;
		}
		i++;
	}
	if (str[i]) {
		char *endptr;
		std::strtod(param.c_str(), &endptr);
		if (*endptr)
			return false;
	}
	return true;
}

// 0: char
// 1: int
// 2: float
// 3: double
// 4: nan
// 5: impossible
static int typeDetector(const std::string &param) {
	if (param.length() == 1 && (param.at(0) < '0' || param.at(0) > '9')) {
		return 0;
	}
	if (param == "nan") return 4;
	else if (!formatChecker(param))
		return 5;
	else if (param.find('f') != std::string::npos)
		return 2;
	else if (param.find('.') != std::string::npos)
		return 3;
	else {
		std::stringstream ss(param);
		double f;
		ss >> f;
		if (f > INT_MAX || f < INT_MIN) {
			if (f > FLT_MAX || f < FLT_MIN)
				return 3;
			return 2;
		}
		return 1;
	}
}

static void convertChar(char c) {
	char str[4] = {'\'', c, '\'', 0};
	std::string coutput = std::isprint(c) ? str : "Non displayable";
	std::cout	<< "char: " << coutput << std::endl
				<< "int: " << static_cast<int>(c) << std::endl
				<< "float: " << static_cast<float>(c) << ".0f" << std::endl
				<< "double: " << static_cast<double>(c)  << ".0" << std::endl;
}

static void convertInt(int i) {
	char str[4] = {'\'', static_cast<char>(i), '\'', 0};
	std::string coutput = std::isprint(static_cast<char>(i)) ? str : "Non displayable";
	std::cout	<< "char: " << coutput << std::endl
				<< "int: " << i << std::endl
				<< "float: " << static_cast<float>(i) << ".0f" << std::endl
				<< "double: " << static_cast<double>(i)  << ".0" << std::endl;
}

static bool isFloatInteger(float f) {
	if (!(f - static_cast<int>(f)))
		return true;
	return false;
}

static void convertFloat(float f) {
	bool isInteger = isFloatInteger(f);
	char str[4] = {'\'', static_cast<char>(f), '\'', 0};
	std::string coutput = std::isprint(static_cast<char>(f)) ? str : "Non displayable";
	std::cout	<< "char: " << coutput << std::endl;
				if (f > INT_MIN && f < INT_MAX) std::cout << "int: " << static_cast<int>(f) << std::endl;
				else std::cout << "int: impossible" << std::endl;
				std::cout << "float: " << f;
				if (isInteger) std::cout << ".0f" << std::endl;
				else std::cout << "f" << std::endl;
	std::cout	<< "double: " << static_cast<double>(f);
				if (isInteger) std::cout << ".0" << std::endl;
				else std::cout << std::endl;
}

static bool isDoubleInteger(double d) {
	if (!(d - static_cast<int>(d)))
		return true;
	return false;
}

static void convertDouble(double d) {
	bool isInteger = isDoubleInteger(d);
	char str[4] = {'\'', static_cast<char>(d), '\'', 0};
	std::string coutput = std::isprint(static_cast<char>(d)) ? str : "Non displayable";
	std::cout	<< "char: " << coutput << std::endl;
				if (d > INT_MIN && d < INT_MAX) std::cout << "int: " << static_cast<int>(d) << std::endl;
				else std::cout << "int: impossible" << std::endl;
				std::cout << "float: " << static_cast<float>(d);
				if (isInteger) std::cout << ".0f" << std::endl;
				else std::cout << "f" << std::endl;
	std::cout	<< "double: " << d;
				if (isInteger) std::cout << ".0" << std::endl;
				else std::cout << std::endl;
}

static void convertNan() {
	std::cout	<< "char: " << "impossible" << std::endl
				<< "int: " << "impossible" << std::endl
				<< "float: nanf" << std::endl
				<< "double: nan" << std::endl;
}

static void convertDefault() {
	std::cout	<< "char: " << "impossible" << std::endl
				<< "int: " << "impossible" << std::endl
				<< "float: " << "impossible" << std::endl
				<< "double: " << "impossible" << std::endl;
}

void ScalarConverter::convert(const std::string& param) {
	int type = typeDetector(param);
	std::cout << C_YELLOW << "type: " << type << " (";
	std::stringstream ss(param);

	switch (type) {
		case 0:
			std::cout << "char)" << C_RESET << std::endl;
			char c;
			ss >> c;
			convertChar(c);
			break;
		case 1:
			std::cout << "int)" << C_RESET << std::endl;
			int i;
			ss >> i;
			convertInt(i);
			break;
		case 2:
			std::cout << "float)" << C_RESET << std::endl;
			float f;
			ss >> f;
			convertFloat(f);
			break;
		case 3:
			std::cout << "double)" << C_RESET << std::endl;
			double d;
			ss >> d;
			convertDouble(d);
			break;
		case 4:
			std::cout << "nan)" << C_RESET << std::endl;
			convertNan();
			break;
		default:
			std::cout << "impossible)" << C_RESET << std::endl;
			convertDefault();
			break;

	}
}