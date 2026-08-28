/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <mansargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:12:54 by mansargs          #+#    #+#             */
/*   Updated: 2025/12/16 17:47:24 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const std::string &Weapon::getType() const { return type; }

void Weapon::setType(const std::string &t) {type = t;}

Weapon::Weapon(const std::string &t) : type(t) {}
