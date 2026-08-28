/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <mansargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:22:37 by mansargs          #+#    #+#             */
/*   Updated: 2025/12/16 16:30:09 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main() {
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;
	std::cout << "========= Memory addresses =============\n"
			  << &str << '\t' << stringPTR << '\t' << &stringREF << "\n\n";
	std::cout << "========= Value =============\n"
			  << str << '\t' << *stringPTR << '\t' << stringREF << std::endl;
}
