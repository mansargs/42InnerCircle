#include "PhoneBook.hpp"
#include <iomanip>
#include <cstdlib>

PhoneBook::PhoneBook() : size(0), next(0) {}

bool PhoneBook::validateNames(const std::string &name)
{
	for (size_t i = 0; i < name.length(); ++i)
	{
		if (std::isalpha(static_cast<unsigned char>(name[i]))
			|| name[i] == ' ')
				continue ;
		std::cout << "Field must contain only letters or spaces\n";
		return false;
	}
	return true;
}

bool PhoneBook::validateNickname(const std::string &nickname)
{
	for (size_t i = 0; i < nickname.length(); ++i)
	{
		if (std::isalnum(static_cast<unsigned char>(nickname[i]))
			|| nickname[i] == '_')
				continue ;
		std::cout << "Field must contain only letters, numbers or underscore\n";
		return false;
	}
	return true;
}

bool PhoneBook::validatePhoneNumber(const std::string &phone)
{
	size_t i = 0;
	if (!phone.empty())
	{
		if (phone[i] == '+')
			++i;
	}
	for (; i < phone.length(); ++i)
	{
		if (std::isdigit(static_cast<unsigned char>(phone[i])))
				continue ;
		std::cout << "Field must contain only digits\n";
		return false;
	}
	return true;
}

std::string PhoneBook::trim_spaces_nonprintable(const std::string &s)
{
	size_t start = 0;
	while (start < s.length() && (std::isspace(static_cast<unsigned char>(s[start]))
			|| !std::isprint(static_cast<unsigned char>(s[start]))))
		++start;
	if (start == s.length())
		return "";
	size_t end = s.length() - 1;
	while (end > start && (std::isspace(static_cast<unsigned char>(s[end]))
			|| !std::isprint(static_cast<unsigned char>(s[end]))))
		--end;
	return s.substr(start, end - start + 1);
}

std::string PhoneBook::formattedText(const std::string &field)
{
	if (field.length() > 10)
		return field.substr(0, 9) + ".";
	return field;
}

std::string PhoneBook::readLine(const std::string &prompt, bool (*check)(const std::string &))
{
	std::string input;
	while (true)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, input))
		{
			if (std::cin.eof()) {
				std::cout << "\nEOF detected. Exiting...\n";
				std::exit(0);
			} else {
				std::cout << "\nStream has failed\n";
				std::exit(1);
			}
		}
		input = trim_spaces_nonprintable(input);
		if (input.empty())
		{
			std::cout << "Invalid field try again. Field can't be empty, nonprintable symbols or all spaces\n";
			continue;
		}
		if (!check || check(input))
			break;
	}
	return input;
}

void PhoneBook::displayAllContacts() const
{
	std::cout << std::setw(10) << "Index" << '|'
		  << std::setw(10) << "First Name" << '|'
		  << std::setw(10) << "Last Name" << '|'
		  << std::setw(10) << "Nickname" << '\n';
	for (size_t i = 0; i < size; ++i)
	{
		std::cout << std::setw(10) << i + 1 << '|'
		<< std::setw(10) << formattedText(contactsData[i].getFirstName()) << '|'
		<< std::setw(10) << formattedText(contactsData[i].getLastName()) << '|'
		<< std::setw(10) << formattedText(contactsData[i].getNickname()) << '\n';
	}
}

void PhoneBook::displayContact(int index) const
{
	std::cout << "Firstname: " << contactsData[index].getFirstName() << '\n'
			  << "Lastname: " << contactsData[index].getLastName() << '\n'
			  << "Nickname: " << contactsData[index].getNickname() << '\n'
			  << "Phone number: " << contactsData[index].getPhoneNumber() << '\n'
			  << "Darkest Secret: " << contactsData[index].getDarkestSecret() << '\n';
}

void PhoneBook::addContact()
{
	Contact newContact;

	newContact.setFirstName(readLine("Enter Firstname: ", PhoneBook::validateNames));
	newContact.setLastName(readLine("Enter Lastname: ", PhoneBook::validateNames));
	newContact.setNickname(readLine("Enter Nickname: ", PhoneBook::validateNickname));
	newContact.setPhoneNumber(readLine("Enter Phone number: ", PhoneBook::validatePhoneNumber));
	newContact.setDarkestSecret(readLine("Enter Darkest secret: ", NULL));

	contactsData[next] = newContact;
	next = (next + 1) % max_size;
	if (size < max_size)
		++size;
}

void PhoneBook::searchContact()
{
	if (size == 0)
	{
		std::cout << "Phonebook is empty\n";
		return;
	}
	while (true)
	{
		displayAllContacts();
		std::string choice = readLine("Enter the index of the contact: ", NULL);
		char *endptr;
		long index = std::strtol(choice.c_str(), &endptr, 10);
		if (endptr == choice.c_str() || *endptr != '\0' ||
			index < 1 || index > static_cast<long>(size))
		{
			std::cout << "Invalid index\n";
			continue;
		}
		displayContact(static_cast<int>(index - 1));
		while (true)
		{
			choice = readLine("Search again (Y/N): ", NULL);
			if (choice.length() == 1 && (choice[0] == 'Y' || choice[0] == 'y' || choice[0] == 'N' || choice[0] == 'n'))
				break;
		}
		if (choice == "N" || choice == "n")
			break;
	}
}

void PhoneBook::run()
{
	while (true)
	{
		std::string command = readLine("Enter the command (ADD, SEARCH, EXIT) : ", NULL);

		if (command == "ADD")
			addContact();
		else if (command == "SEARCH")
			searchContact();
		else if (command == "EXIT")
			std::exit(0);
	}
}
