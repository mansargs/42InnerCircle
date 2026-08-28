/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <mansargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:02:32 by mansargs          #+#    #+#             */
/*   Updated: 2025/12/16 15:29:40 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Zombie {
	private:
		std::string name;

	public:
		explicit Zombie(const std::string &name);
		~Zombie();

		void announce() const;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

