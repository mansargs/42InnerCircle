/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <mansargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:47:56 by mansargs          #+#    #+#             */
/*   Updated: 2025/12/16 15:50:29 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Zombie {
	private:
		std::string name;
	public:
		Zombie();
		~Zombie();

		void setName(const std::string &n);
		void announce() const;
};

Zombie* zombieHorde( int N, std::string name );
