/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:52:35 by okraus            #+#    #+#             */
/*   Updated: 2024/05/05 17:05:51 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int main(void)
{
	std::string name1 = "Zombie";
	std::string name2 = "HordeZombie";
	int			n = 7;
	Zombie zombie(name1);
	zombie.announce();
	Zombie *ptrZombie = zombieHorde(n, name2);
	for (int i = 0; i < n; ++i)
		ptrZombie[i].announce();
	delete [] ptrZombie;
}
