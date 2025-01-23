/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:11:15 by mjong             #+#    #+#             */
/*   Updated: 2025/01/23 18:23:56 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook() : contactCount(0) {}

void	PhoneBook::addContact(std::string &firstName)
{
	if (contactCount >= 8)
	{
		std::cout << "The phonebook is full! The oldest contact will be replaced.\nProceed?\n| YES | NO |" << std::endl;
		while (1)
		{
			std::string proceed;	
			std::getline(std::cin, proceed);
			if (proceed == "YES" || proceed == "yes")
			{
				contacts[contactCount % 8].setContact(firstName, (contactCount % 8) + 1);
				std::cout << "\nAdded contact: " << contacts[contactCount % 8].getFirstName()
						  << " " << contacts[contactCount % 8].getLastName() << std::endl;
				std::cout << ADD_CONTACT_PROMPT << std::endl;
				return ;
			}
			else if (proceed == "NO" || proceed == "no")
			{
				std::cout << EXITING_PROMPT << std::endl;
				std::cout << ADD_CONTACT_PROMPT << std::endl;
				return ;
			}
			else
				std::cout << "Wrong command, enter:\n| YES | NO |" << std::endl;
		}
	}
	else
	{
		contacts[contactCount].setContact(firstName, contactCount + 1);
		std::cout << "\nAdded contact: " << contacts[contactCount].getFirstName()
				  << " " << contacts[contactCount].getLastName() << std::endl;
		contactCount++;
		std::cout << ADD_CONTACT_PROMPT << std::endl;
	}
}

void	PhoneBook::searchContact(std::string &contactName)
{
	std::cout << "searching" << contactName << std::endl;
}
