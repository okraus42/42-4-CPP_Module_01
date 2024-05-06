/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:30:55 by okraus            #+#    #+#             */
/*   Updated: 2024/05/06 13:48:30 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

void Harl::debug(void)
{
	std::cout << "Debug:" << std::endl;
}

void Harl::info(void)
{
	std::cout << "Info:" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "Warning:" << std::endl;
}

void Harl::error(void)
{
	std::cout << "Error:" << std::endl;
}

void Harl::other(void)
{
	std::cout << "Other:" << std::endl;
}

void Harl::complain(std::string level)
{
	std::string		str[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::	*ptr[5])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error, &Harl::other};
	int				i = -1;

	while (++i < 4 && level != str[i]);
	switch (i)
	{
		case 0:
			(this->*ptr[0])();
			// fall through
		case 1:
			(this->*ptr[1])();
			// fall through
		case 2:
			(this->*ptr[2])();
			// fall through
		case 3:
			(this->*ptr[3])();
			break;
		case 4:
			(this->*ptr[4])();
	}
}

