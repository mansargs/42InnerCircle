/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <mansargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:47:40 by mansargs          #+#    #+#             */
/*   Updated: 2025/12/16 16:13:51 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() : name("") {}

Zombie::~Zombie() { std::cout << "Destructor " << name << std::endl; }

void Zombie::announce() const { std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl; }

void Zombie::setName(const std::string &n) { name = n; }
