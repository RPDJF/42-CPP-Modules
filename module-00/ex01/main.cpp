#include "main.hpp"

#include "utils/to_string.hpp"

static void	print_propertie(std::string property)
{
	if (property.size() > 10) {
		property.resize(9);
		property.resize(10, '.');
	}
	else if (property.size() < 10)
		property = std::string(10 - property.size(), ' ') + property;
	std::cout << property;
}

static void	print_contacts(PhoneBook &phonebook) {
	std::cout << "     index|first name| last name|  nickname\n";
	std::cout << std::string(43, '-') << "\n";
	for (int i = 0; i < phonebook.getSize(); i++) {
		Contact contact;
		std::string	tmp;
	
		contact = phonebook.getContacts()[i];
		print_propertie(to_string(i));
		std::cout << tmp << "|";
		print_propertie(contact.getFirstname());
		std::cout << tmp << "|";
		print_propertie(contact.getLastname());
		std::cout << tmp << "|";
		print_propertie(contact.getNickname());
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

static void	search_contact(PhoneBook &phonebook) {
	int	idx;
	std::string	prompt;

	if (!phonebook.getSize()) {
		std::cout << ERR_NO_CONTACTS << std::endl;
		return ;
	}
	prompt.append("select a contact index (0 - ");
	prompt.append(to_string(phonebook.getSize() - 1));
	prompt.append(") : ");
	std::cout << "\n";
	print_contacts(phonebook);
	while (true)
	{
		std::string	input;
		if (readline(prompt, input) < 0)
			exit (0);
		if (input.empty())
			continue;
		std::istringstream	is_string(input);
		is_string >> idx;
		if (!is_string)
			std::cout << ERR_NOT_AN_IDX << input << "\n" << std::endl;
		else if (idx < 0)
			std::cout << ERR_LOW_IDX << input << "\n" << std::endl;
		else if (idx >= phonebook.getSize())
			std::cout << ERR_HIGH_IDX << input << "\n" << std::endl;
		else
			break;
	}
	std::cout << "\n";
	phonebook.getContacts()[idx % phonebook.getSize()].printContact();
}

int	main()
{
	PhoneBook	phonebook;
	Contact		contact;

	while (true)
	{
		std::string	input;

		if (readline(PROMPT, input) < 0)
			exit (0);
		if (input == "ADD")
		{
			contact.init();
			if (contact.is_empty()) {
				std::cout << ERR_EMPTY_FIELD << std::endl;
				continue;
			}
			phonebook.addContact(contact);
			std::cout << std::endl;
		}
		else if (input == "SEARCH")
			search_contact(phonebook);
		else if (input == "EXIT")
			exit (0);
		else if (input.size())
			std::cout << ERR_WRONG_USAGE << std::endl;
	}
}