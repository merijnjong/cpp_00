/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:21:32 by mjong             #+#    #+#             */
/*   Updated: 2025/01/22 15:21:56 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <cctype>

std::string makeWordUpperCase(const std::string &input)
{
    std::string result;
    for (char c : input)
	{
        result += std::toupper(c);
    }
    return (result);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else
	{
		std::string sentence;
		for (int i = 1; i < argc; i++)
		{
			sentence += makeWordUpperCase(argv[i]); // works like strjoin
		}
		std::cout << sentence << std::endl;
	}
	return (0);
}
