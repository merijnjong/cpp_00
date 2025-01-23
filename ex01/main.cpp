/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:38:44 by mjong             #+#    #+#             */
/*   Updated: 2025/01/23 17:58:05 by mjong            ###   ########.fr       */
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

void	searchWindow(PhoneBook &phonebook)
{
	std::cout << "\n| SEARCH A CONTACT |\n\nEnter a contact name to search or:\n| EXIT |" << std::endl;
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
				std::cout << "Wrong command, enter:\n| ADD | SEARCH | EXIT |" << std::endl;
		}
	}
	else
		std::cout << "Usage: ./phonebook" << std::endl;
	return (0);
}
