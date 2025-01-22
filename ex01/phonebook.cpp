/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:11:15 by mjong             #+#    #+#             */
/*   Updated: 2025/01/22 17:24:15 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	searchContact()
{
	std::cout << "\n| SEARCH A CONTACT |\n\nEnter a contact name to search or:\n| EXIT TO HOMESCREEN |" << std::endl;
	while (1)
	{
		std::string command;	
		std::getline(std::cin, command);
		if (command == "EXIT" || command == "exit")
			break ;
		else if (!command.empty())
		{
			std::cout << "Searched contact: " << command << std::endl;
		}
		else if (command == "")
			continue ;
	}
}

void	addContact()
{
	std::cout << "\n| ADD A CONTACT |\n\nEnter a contact name to add or:\n| EXIT TO HOMESCREEN |" << std::endl;
	while (1)
	{
		std::string command;	
		std::getline(std::cin, command);
		if (command == "EXIT" || command == "exit")
			break ;
		else if (!command.empty())
		{
			std::cout << "Added contact: " << command << std::endl;
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
		bool showHomeScreen = true;
		while (1)
		{
			if (showHomeScreen)
			{
				std::cout << "\n| HOMESCREEN |\n\nWhat would you like to do:\n| ADD | SEARCH | EXIT |" << std::endl;
				showHomeScreen = false;
			}
			std::string command;	
			std::getline(std::cin, command);
			if (command == "ADD" || command == "add")
			{
				addContact();
				showHomeScreen = true;
			}
			else if (command == "SEARCH" || command == "search")
			{
				searchContact();
				showHomeScreen = true;
			}
			else if (command == "EXIT" || command == "exit")
				break ;
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
