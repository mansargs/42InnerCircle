/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <mansargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:30:30 by mansargs          #+#    #+#             */
/*   Updated: 2025/12/16 15:35:49 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main(void)
{
	std::cout << "=== randomChump (stack) ===" << std::endl;
	randomChump("StackZombie");

	std::cout << "\n=== newZombie (heap) ===" << std::endl;
	Zombie *z = newZombie("HeapZombie");
	z->announce();

	delete z;
	return 0;
}
