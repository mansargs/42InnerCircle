/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <mansargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:48:28 by mansargs          #+#    #+#             */
/*   Updated: 2025/12/16 17:59:07 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Weapon {
	private:
		std::string type;
	public:
		Weapon(const std::string &t);
		const std::string &getType() const;
		void setType(const std::string &type);
};
