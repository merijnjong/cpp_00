/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:26:12 by mjong             #+#    #+#             */
/*   Updated: 2025/01/30 16:45:47 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	Contact::setContact(std::string firstName, int index)
{
	setFirstName(firstName);
	std::cout << "\nAdded first name: " << firstName << std::endl;

	std::string lastName;
	std::cout << "\033[33m\n| SET LAST NAME |\n\033[0m" << std::endl;
	do
		std::getline(std::cin, lastName);
	while (lastName.empty());
	setLastName(lastName);
	std::cout << "\nAdded last name: " << lastName << std::endl;

	std::string nickName;
	std::cout << "\033[33m\n| SET NICKNAME |\n\033[0m" << std::endl;
	do
		std::getline(std::cin, nickName);
	while (nickName.empty());
	setNickName(nickName);
	std::cout << "\nAdded nickname: " << nickName << std::endl;

	std::string phoneNumber;
	std::cout << "\033[33m\n| SET PHONE NUMBER |\n\033[0m" << std::endl;
	bool validPhoneNumber = false;
	do {
		std::getline(std::cin, phoneNumber);
		validPhoneNumber = (setPhoneNumber(phoneNumber) == 0);
	} while (phoneNumber.empty() || !validPhoneNumber);
	std::cout << "\nAdded phone number: " << phoneNumber << std::endl;

	std::string darkestSecret;
	std::cout << "\033[33m\n| SET DARKEST SECRET |\n\033[0m" << std::endl;
	do
		std::getline(std::cin, darkestSecret);
	while (darkestSecret.empty());
	setDarkestSecret(darkestSecret);
	std::cout << "\nAdded darkest secret: " << darkestSecret << std::endl;

	setIndex(index);
	std::cout << "\nContact can be found on index: " << index << std::endl;
}
