#include "Harl.hpp"

void	Harl::debug() {
	std::cout << "[ DEBUG ]\n"
		<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
		<< std::endl;
}

void	Harl::info() {
	std::cout << "[ INFO ]\n"
		<< "I cannot believe adding extra bacon costs more money.\n"
		<< "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
		<< std::endl;
}

void Harl::warning() {
	std::cout << "[ WARNING ]\n"
		<< "I think I deserve to have some extra bacon for free.\n"
		<< "I’ve been coming foryears whereas you started working here since last month."
		<< std::endl;
}


void Harl::error() {
	std::cout << "[ ERROR ]\n"
		<< "This is unacceptable, I want to speak to the manager now."
		<< std::endl;
}

void	Harl::complain(std::string level) {
	std::string levels[] = {"debug", "info", "warning", "error", ""};
	f p_levels[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error, 0};

	for (int i = 0; levels[i] != ""; i++) {
		if (levels[i] == level) {
			(this->*p_levels[i])();
			return;
		}
	}
	std::cout << "[ IDIOT DETECTED ]\n"
		<< "There is no such thing !"
		<< std::endl;
}