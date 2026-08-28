#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
private:
	std::map<std::string, double> db;

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	void parseDb();
	void exchange(const std::string& file);

	void dateValidation(const std::string& date);
	void valueValidation(const std::string& value);
	void lineValidation(const std::string& line);
};

void trimSpaces(std::string& line);

#endif

