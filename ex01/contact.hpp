/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:26:09 by mjong             #+#    #+#             */
/*   Updated: 2025/01/22 16:40:07 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CONTACT_HPP
# define CONTACT_HPP

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <iostream>
# include <string>
# include <cctype>
# include "phonebook.hpp"

class Contact {
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		int		index;

	public:
};

#endif