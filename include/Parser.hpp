#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <cstdio>
#include <iostream>
#include <regex>
#include <algorithm>
#include "eOperandType.hpp"

class Parser {

public:
	Parser();

	Parser(const Parser &copy);

	~Parser();

	Parser &operator=(const Parser &rhs);

	void		readInput();
	std::string	replaceSpacings(std::string & line);

private:
	bool				_endOfInput(const std::string & line);
	std::string			_clearCommentFromLine(const std::string & line);
	std::string			_parseLine(std::string & line);
	std::string			_parseInstruction(const std::string & line, const bool & hasValue);
	bool				_isInstructionWithoutValue(const std::string & line);
	bool				_isInstructionWithValue(const std::string & line);
	bool				_error;
//	struct parsedLine	*_parsedLine;

};

#endif
