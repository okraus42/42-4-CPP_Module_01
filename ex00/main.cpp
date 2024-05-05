/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:52:35 by okraus            #+#    #+#             */
/*   Updated: 2024/05/05 18:02:43 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int main(void)
{
	std::string name1 = "Zombie";
	std::string name2 = "NewZombie";
	std::string name3 = "RandomZombie";
	Zombie zombie(name1);
	zombie.announce();
	Zombie *ptrZombie = newZombie(name2);
	ptrZombie->announce();
	delete ptrZombie;
	randomChump(name3);
	return (0);
}
