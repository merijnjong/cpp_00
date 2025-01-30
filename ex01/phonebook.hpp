/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:11:50 by mjong             #+#    #+#             */
/*   Updated: 2025/01/30 15:06:11 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <cctype>
# include <iomanip>
# include <iostream>
# include <limits>
# include "contact.hpp"

# define HOMESCREEN_PROMPT "\033[33m\n| HOMESCREEN |\n\nWhat would you like to do:\n| ADD | SEARCH | EXIT |\n\033[0m"
# define ADD_CONTACT_PROMPT "\033[33m\n| ADD A CONTACT |\n\nWhat would you like to do:\n| SET FIRST NAME | EXIT |\n\033[0m"
# define SEARCH_CONTACT_PROMPT "\033[33m\n| SEARCH A CONTACT |\n\nWhat would you like to do:\n| ENTER INDEX | EXIT |\n\033[0m"
# define EXITING_PROMPT "\033[33m\n| EXITING |\033[0m"

class PhoneBook {
	public:
		PhoneBook();
		
		void	addContact(std::string &firstName);
		int		getContactCount(void);
		Contact	getContact(int index);
		void	searchContact(std::string &firstName);

	private:
		Contact	contacts[8];
        int		contactCount;
};

#endif