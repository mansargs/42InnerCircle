/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <mansargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:48:09 by mansargs          #+#    #+#             */
/*   Updated: 2025/12/16 17:59:57 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string &n, Weapon *w) : name(n), weapon(w) {}

void HumanB::setWeapon(Weapon &w) { weapon = &w; }

void HumanB::attack() const {
	if (!weapon)
		std::cout << name << " attacks with their bare hands\n";
	else
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}
