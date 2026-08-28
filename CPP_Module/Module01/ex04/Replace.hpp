/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <mansargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:21:15 by mansargs          #+#    #+#             */
/*   Updated: 2025/12/17 01:04:31 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Replace {
	private:
		static const size_t chunk_size = 1024;
		std::string find;
		std::string replace;
		std::string file;
	private:
		std::string outfileName() const;
	public:
		explicit Replace(const std::string &f, const std::string &search, const std::string &rep);
		void     generateOutfile() const;
};
