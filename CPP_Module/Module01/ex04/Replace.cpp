/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <mansargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 00:43:22 by mansargs          #+#    #+#             */
/*   Updated: 2025/12/17 01:33:38 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>

Replace:: Replace(const std::string &f, const std::string &search, const std::string &rep) :
	find(search), replace(rep), file(f) {}

std::string Replace::outfileName() const {
	size_t pos = file.rfind('.');
	if (pos == std::string::npos)
		return file + ".replace";
	else
		return file.substr(0, pos) + ".replace";
}

void Replace::generateOutfile() const {
	std::ifstream infile(file.c_str());
	if (!infile.is_open()) {
		std::cerr << "Error: cannot open input file\n";
		std::exit(1);
	}
	std::ofstream outfile(outfileName().c_str());
	if (!outfile.is_open()) {
		std::cerr << "Error: cannot create output file\n";
		std::exit(1);
	}
	std::string content((std::istreambuf_iterator<char>(infile)),
						 std::istreambuf_iterator<char>());
	if (find.empty()) {
		std::cerr << "Error: string to find is empty\n";
		std::exit(1);
	}
	std::string result;
	size_t pos = 0;
	size_t found;
	while ((found = content.find(find, pos)) != std::string::npos) {
		result += content.substr(pos, found - pos);
		result += replace;
		pos = found + find.length();
	}
	result += content.substr(pos);
	outfile << result;
}
