/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <mansargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:58:20 by mansargs          #+#    #+#             */
/*   Updated: 2025/12/16 16:15:41 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main () {
	int N = 10;
	std::string name = "Foo";

	Zombie *horde = zombieHorde(N, name);
	if (!horde) {
		std::cout << "Memory allocation failed" << std::endl;
		return 1;
	}
	for (int i = 0; i < N; ++i) {
		horde[i].announce();
	}
	delete[] horde;
	return 0;
}
