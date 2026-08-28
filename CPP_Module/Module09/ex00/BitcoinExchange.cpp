#include "BitcoinExchange.hpp"
#include <cctype>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include <iostream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : db(other.db) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	db = other.db;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void trimSpaces(std::string& line) {
	while (!line.empty() && std::isspace(line[0]))
		line.erase(0,1);
	while (!line.empty() && std::isspace(line[line.size()-1]))
		line.erase(line.size()-1,1);
}

void BitcoinExchange::dateValidation(const std::string& date) {
	const std::string msg = "Error: bad date => " + date;
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		throw std::runtime_error(msg);
	for (int i = 0; i < 10; ++i)
		if (i != 4 && i != 7 && !isdigit(date[i]))
			throw std::runtime_error(msg);
}

void BitcoinExchange::valueValidation(const std::string& value) {
	const std::string neg = "Error: not a positive number => " + value;
	const std::string large = "Error: too large a number => " + value;
	if (value.empty())
		throw std::runtime_error(neg);
	char* endptr;
	double num = std::strtod(value.c_str(), &endptr);
	if (*endptr != '\0')
		throw std::runtime_error(neg);
	if (num < 0)
		throw std::runtime_error(neg);
	if (num > 1000)
		throw std::runtime_error(large);
}

void BitcoinExchange::lineValidation(const std::string& line) {
	size_t sep = line.find('|');
	if (sep == std::string::npos)
		throw std::runtime_error("Error: missing '|' separator => " + line);
	std::string date = line.substr(0, sep);
	std::string value = line.substr(sep + 1);
	trimSpaces(date);
	trimSpaces(value);
	dateValidation(date);
	valueValidation(value);
}

void BitcoinExchange::parseDb() {
	std::ifstream db_file("data.csv");
	std::string line;

	if (!db_file.is_open())
		throw std::runtime_error("Must have data.csv");
	std::getline(db_file, line);
	while (std::getline(db_file, line)) {
		std::stringstream ss(line);
		std::string date, rate;
		if (std::getline(ss, date, ',') && std::getline(ss, rate)) {
			trimSpaces(date);
			trimSpaces(rate);
			double rate_value = std::strtod(rate.c_str(), NULL);
			db[date] = rate_value;
		}
	}
}

void BitcoinExchange::exchange(const std::string& file) {
	std::ifstream f(file.c_str());
	std::string line;

	if (!f.is_open())
		throw std::runtime_error(std::string("Must have ") + file);
	std::getline(f, line);
	if (line != "date | value")
		throw std::runtime_error("First line must be <date | value>");
	while (std::getline(f, line)) {
		try {
			lineValidation(line);
			std::stringstream ss(line);
			std::string date, value;
			if (std::getline(ss, date, '|') && std::getline(ss, value)) {
				trimSpaces(date);
				trimSpaces(value);
				double val = std::strtod(value.c_str(), NULL);
				std::map<std::string,double>::iterator it = db.lower_bound(date);
				if (it == db.end() || it->first != date) {
					if (it == db.begin()) {
						std::cerr << "Error: no earlier date in database for " << date << std::endl;
						continue;
					}
					--it;
				}
				std::cout << date << " => " << val << " = " << val * it->second << std::endl;
			}
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
}
