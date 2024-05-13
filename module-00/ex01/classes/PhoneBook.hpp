#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define MAX_CONTACTS_SIZE 8

class PhoneBook {
	private:
		int		cursor_;
		int		size_;
		Contact	arr_contacts_[MAX_CONTACTS_SIZE];
	public:
		PhoneBook();
		int		getSize();
		Contact	*getContacts();
		void	addContact(Contact contact);
};

#endif