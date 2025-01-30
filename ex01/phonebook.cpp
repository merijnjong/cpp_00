/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:11:15 by mjong             #+#    #+#             */
/*   Updated: 2025/01/30 18:07:43 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook() : contactCount(0)
{
}

Contact PhoneBook::getContact(int index)
{
	if (index >= 0 && index < contactCount)
	{
		return (contacts[index]);
	}
	else
		return (Contact());
}

void	PhoneBook::addContact(std::string &firstName)
{
	if (contactCount >= 8)
	{
		std::cout << "\033[33m\nThe phonebook is full! The oldest contact will be replaced.\nProceed?\n| YES | NO |\n\033[0m" << std::endl;
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
				std::cout << "\033[31m\nWrong command, enter:\033[0m\n\033[33m| YES | NO |\033[0m" << std::endl;
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

int	PhoneBook::getContactCount(void)
{
	return (contactCount);
}

void	displaySingleContact(PhoneBook &phonebook, int index)
{
	Contact		contacts = phonebook.getContact(index - 1);
	std::string	firstName = contacts.getFirstName();
	std::string	lastName = contacts.getLastName();
	std::string	nickName = contacts.getNickName();
	std::string	phoneNumber = contacts.getPhoneNumber();

	std::cout << "________________________________________________________"  << std::endl;
	std::cout << "|  Index   |First Name|Last Name | Nickname |Phone Nmbr|"  << std::endl;
	std::cout << "|----------|----------|----------|----------|----------|"  << std::endl;
	std::cout << "|" << std::setw(10) << std::right << index << "|"
			  << std::setw(10) << std::right << longerThanTen(firstName) << "|"
			  << std::setw(10) << std::right << longerThanTen(lastName) << "|"
			  << std::setw(10) << std::right << longerThanTen(nickName) << "|"
			  << std::setw(10) << std::right << longerThanTen(phoneNumber) << "|" << std::endl;
	std::cout << " ⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻ " << std::endl;
}

void	PhoneBook::searchContact(PhoneBook &phonebook, std::string &contactIndex)
{
	bool isValid = true;

	for (char c : contactIndex)
	{
		if (!isdigit(c))
		{
			isValid = false;
			break ;
		}
	}
	if (isValid)
	{
		int	index = stoi(contactIndex);
		if (index >= 1 && index <= 8)
		{
			displaySingleContact(phonebook, index);
		}
		else
			std::cout << "\033[31m\nInvalid input! You should enter a number between 1 and 8\n\033[0m" << std::endl;
	}
	else
		std::cout << "\033[31m\nInvalid input! You should enter a number between 1 and 8\n\033[0m" << std::endl;
}
