/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <mansargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:53:45 by mansargs          #+#    #+#             */
/*   Updated: 2025/12/16 16:10:04 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name) {
	if (N <= 0)
		return NULL;
	Zombie *horde =  new (std::nothrow) Zombie[N];
	if (!horde)
		return NULL;
	for (int i = 0; i < N; ++i) {
		horde[i].setName(name);
	}
	return horde;
}
