/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:38:44 by mjong             #+#    #+#             */
/*   Updated: 2025/01/30 16:19:33 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	addWindow(PhoneBook &phonebook)
{
	std::cout << ADD_CONTACT_PROMPT << std::endl;
	while (1)
	{
		std::string command;	
		std::getline(std::cin, command);
		if (command == "EXIT" || command == "exit")
		{
			std::cout << EXITING_PROMPT << std::endl;
			break ;
		}
		else if (!command.empty())
		{
			phonebook.addContact(command);
		}
		else if (command == "")
			continue ;
	}
}

std::string longerThanTen(std::string &str)
{
	if (str.length() > 10)
	{
		str = str.substr(0, 9);
		str += '.';
	}
	return (str);
}

void	displayPhoneBook(PhoneBook &phonebook)
{
	Contact		contacts;
	std::string	index;
	std::string	firstName;
	std::string	lastName;
	// std::string darkestSecret;
	std::string	nickName;

	std::cout << "_____________________________________________"  << std::endl;
	std::cout << "|  Index   |First Name|Last Name | Nickname |"  << std::endl;
	std::cout << "|----------|----------|----------|----------|"  << std::endl;
	for (int i = 0; i < 8; i++)
	{
		contacts = phonebook.getContact(i);
		firstName = contacts.getFirstName();
		lastName = contacts.getLastName();
		nickName = contacts.getNickName();
		std::cout << "|" << std::setw(10) << std::right << i + 1 << "|"
				  << std::setw(10) << std::right << longerThanTen(firstName) << "|"
				  << std::setw(10) << std::right << longerThanTen(lastName) << "|"
				  << std::setw(10) << std::right << longerThanTen(nickName) << "|" << std::endl;
	}
	std::cout << " ⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻ " << std::endl;
}

void	searchWindow(PhoneBook &phonebook)
{
	int		contactCount;

	contactCount = phonebook.getContactCount();
	if (contactCount == 0)
	{
		std::cout << "\033[31m\nNo contact added yet, please add a contact\033[0m" << std::endl;
		return ;
	}
	displayPhoneBook(phonebook);
	std::cout << SEARCH_CONTACT_PROMPT << std::endl;
	while (1)
	{
		std::string command;	
		std::getline(std::cin, command);
		if (command == "EXIT" || command == "exit")
		{
			std::cout << EXITING_PROMPT << std::endl;
			break ;
		}
		else if (!command.empty())
		{
			phonebook.searchContact(command);
		}
		else if (command == "")
			continue ;
	}
}

int main(int argc, char **argv)
{
	(void)argv;
	
	if (argc == 1)
	{
		PhoneBook	phonebook;
		bool		showHomeScreen = true;
		while (1)
		{
			if (showHomeScreen)
			{
				std::cout << HOMESCREEN_PROMPT << std::endl;
				showHomeScreen = false;
			}
			std::string command;	
			std::getline(std::cin, command);
			if (command == "ADD" || command == "add")
			{
				addWindow(phonebook);
				showHomeScreen = true;
			}
			else if (command == "SEARCH" || command == "search")
			{
				searchWindow(phonebook);
				showHomeScreen = true;
			}
			else if (command == "EXIT" || command == "exit")
			{
				std::cout << EXITING_PROMPT << std::endl;
				break ;
			}
			else if (command == "")
				continue ;
			else
				std::cout << "\033[31m\nWrong command, enter:\033[0m\n\033[33m| ADD | SEARCH | EXIT |\033[0m" << std::endl;
		}
	}
	else
		std::cout << "Usage: ./phonebook" << std::endl;
	return (0);
}
