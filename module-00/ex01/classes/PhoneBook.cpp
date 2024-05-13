#include "PhoneBook.hpp"

// constructors declarations

PhoneBook::PhoneBook() {
	this->size_ = 0;
	this->cursor_ = 0;
}

// getters declarations

int	PhoneBook::getSize() {
	return this->size_;
}

Contact *PhoneBook::getContacts() {
	return this->arr_contacts_;
}

// public functions declarations

void	PhoneBook::addContact(Contact contact) {
	this->arr_contacts_[this->cursor_] = contact;
	this->cursor_ = (this->cursor_ + 1)	% MAX_CONTACTS_SIZE;
	if (this->size_ < MAX_CONTACTS_SIZE)
		this->size_++;
}