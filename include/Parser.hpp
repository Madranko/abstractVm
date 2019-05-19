#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <cstdio>
#include <iostream>
#include <regex>

class Parser {

public:
	Parser();

	Parser(const Parser &copy);

	~Parser();

	Parser &operator=(const Parser &rhs);

	void	readInput();

private:
	bool	_endOfInput(const std::string & line);
};

#endif
