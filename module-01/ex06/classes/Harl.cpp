#include "Harl.hpp"

void	Harl::debug() {
	std::cout << "[ DEBUG ]\n"
		<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n"
		<< std::endl;
}

void	Harl::info() {
	std::cout << "[ INFO ]\n"
		<< "I cannot believe adding extra bacon costs more money.\n"
		<< "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n"
		<< std::endl;
}

void Harl::warning() {
	std::cout << "[ WARNING ]\n"
		<< "I think I deserve to have some extra bacon for free.\n"
		<< "I’ve been coming foryears whereas you started working here since last month.\n"
		<< std::endl;
}


void Harl::error() {
	std::cout << "[ ERROR ]\n"
		<< "This is unacceptable, I want to speak to the manager now.\n"
		<< std::endl;
}

void	Harl::complain(std::string level) {
	int	idx = -1;
	std::string levels[] = {"debug", "info", "warning", "error", ""};

	for (int i = 0; levels[i] != ""; i++)
		if (levels[i] == level)
			idx = i;
		
	switch(idx) {
		case 0:
			this->debug();
		case 1:
			this->info();
		case 2:
			this->warning();
		case 3:
			this->error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n"
				<< std::endl;
	}
}