/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <mansargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:18:17 by mansargs          #+#    #+#             */
/*   Updated: 2025/12/17 01:10:50 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include "Replace.hpp"

int main (int argc, char *argv[]) {
	if (argc != 4) {
		std::cout << "Usage: " << argv[0] << " <filename> <s1> <s2>\n"
				  << "  <filename> : path to the input file\n"
				  << "  <s1>       : string to search for\n"
				  << "  <s2>       : string to replace <s1> with\n";
		return 1;
	}
	Replace instance(argv[1], argv[2], argv[3]);

	instance.generateOutfile();
	return 0;
}
