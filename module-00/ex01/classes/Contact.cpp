#include "Contact.hpp"

// getters definitions

std::string	Contact::getFirstname() {
	return this->firstname_;
}

std::string Contact::getLastname() {
	return this->lastname_;
}

std::string Contact::getNickname() {
	return this->nickname_;
}

std::string Contact::getPhoneNumber() {
	return this->phone_number_;
}

bool	Contact::is_empty() {
	return this->is_empty_;
}

// initialization

void Contact::init()
{
	this->is_empty_ = true;
	if (readline("First name: ", this->firstname_) < 0)
		exit(0);
	if (this->firstname_.empty())
		return;
	if (readline("Last name: ", this->lastname_) < 0)
		exit(0);
	if (this->lastname_.empty())
		return;
	if (readline("Nickname: ", this->nickname_) < 0)
		exit(0);
	if (this->nickname_.empty())
		return;
	if (readline("Phone number: ", this->phone_number_) < 0)
		exit(0);
	if (this->phone_number_.empty())
		return;
	if (readline("Darkest secret: ", this->darkest_secret_) < 0)
		exit(0);
	if (this->darkest_secret_.empty())
		return;
	this->is_empty_ = false;
}

// functions

void	Contact::printContact() {
	std::cout << "first name     : " << this->firstname_ << "\n";
	std::cout << "last name      : " << this->lastname_ << "\n";
	std::cout << "nickname       : " << this->nickname_ << "\n";
	std::cout << "phone number   : " << this->phone_number_ << "\n";
	std::cout << "darkest secret : " << this->darkest_secret_ << "\n";
	std::cout << std::endl;
}