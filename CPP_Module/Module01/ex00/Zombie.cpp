/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <mansargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:13:25 by mansargs          #+#    #+#             */
/*   Updated: 2025/12/16 15:35:38 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(const std::string &s) : name(s) {}

Zombie::~Zombie() { std::cout << "Destructor " << name << std::endl; }

void Zombie::announce() const { std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl; }

