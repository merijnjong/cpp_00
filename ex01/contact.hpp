/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:26:09 by mjong             #+#    #+#             */
/*   Updated: 2025/01/30 18:06:50 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CONTACT_HPP
# define CONTACT_HPP

# include <cctype>
# include <string>
# include <iomanip>
# include <iostream>
# include <limits>
# include "phonebook.hpp"

class Contact {
	public:
		void setContact(std::string firstName, int index);
		void setFirstName(std::string &firstName) {
			this->firstName = firstName;
		}
		void setLastName(std::string &lastName) {
			this->lastName = lastName;
		}
		void setNickName(std::string &nickName) {
			this->nickName = nickName;
		}
		int	setPhoneNumber(std::string &phoneNumber)
		{
			bool isValid = true;

			for (char c : phoneNumber)
			{
				if (!isdigit(c))
				{
					isValid = false;
					break ;
				}
			}
			if (isValid)
			{
				this->phoneNumber = phoneNumber;
				return (0);
			}
			else
				std::cout << "\033[31m\nInvalid phone number! It should be formatted like this: 000000000000\n\033[0m" << std::endl;
			return (1);
		}
		void setDarkestSecret(std::string &darkestSecret) {
			this->darkestSecret = darkestSecret;
		}
		void setIndex(int index) {
			this->index = index;
		}

		std::string getFirstName() {
			return (firstName);
		}
		std::string getLastName() {
			return (lastName);
		}
		std::string getNickName() {
			return (nickName);
		}
		std::string getPhoneNumber() {
			return (phoneNumber);
		}
		int getIndex() {
			return (index);
		}

	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string darkestSecret;
		int			index;
};

#endif