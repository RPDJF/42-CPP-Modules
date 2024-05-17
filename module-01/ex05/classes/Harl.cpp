#include "Harl.hpp"

void	Harl::debug() {
	std::cout << "\"DEBUG\" level: Debug messages contain contextual information. They are mostly used for problem diagnosis.\nExample: \"I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\"" << std::endl;
}

void	Harl::info() {
	std::cout << "\"INFO\" level: These messages contain extensive information. They are helpful for tracing program execution in a production environment.\nExample: \"I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\"" << std::endl;
}

void Harl::warning() {
	std::cout << "\"WARNING\" level: Warning messages indicate a potential issue in the system.\nHowever, it can be handled or ignored.\nExample: \"I think I deserve to have some extra bacon for free. I’ve been coming foryears whereas you started working here since last month.\"" << std::endl;
}


void Harl::error() {
	std::cout << "\"ERROR\" level: These messages indicate an unrecoverable error has occurred.\nThis is usually a critical issue that requires manual intervention.\nExample: \"This is unacceptable! I want to speak to the manager now.\"" << std::endl;
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
	std::cout << "There is no such thing !" << std::endl;
}