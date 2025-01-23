/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:26:12 by mjong             #+#    #+#             */
/*   Updated: 2025/01/23 18:19:51 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	Contact::setContact(std::string firstName, int index)
{
	setFirstName(firstName);
	std::cout << "\nAdded first name: " << firstName << std::endl;

	std::cout << "\033[33m\n| SET LAST NAME |\n\033[0m" << std::endl;
	std::string lastName;
	std::getline(std::cin, lastName);
	setLastName(lastName);
	std::cout << "\nAdded last name: " << lastName << std::endl;

	std::cout << "\033[33m\n| SET NICKNAME |\n\033[0m" << std::endl;
	std::string nickName;	
	std::getline(std::cin, nickName);
	setNickName(nickName);
	std::cout << "\nAdded nickname: " << nickName << std::endl;

	setIndex(index);
    std::cout << "\nContact index set to: " << index << std::endl;
}
