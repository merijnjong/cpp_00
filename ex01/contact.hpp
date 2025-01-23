/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:26:09 by mjong             #+#    #+#             */
/*   Updated: 2025/01/23 18:20:09 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <cctype>
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
		int getIndex() {
			return (index);
		}

	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		int			index;
};

#endif