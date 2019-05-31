#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <regex>
#include <algorithm>
#include "eOperandType.hpp"
#include <list>

class Parser {

public:
	Parser(int argc, char **argv);

	Parser(const Parser &copy);

	~Parser();

	Parser &operator=(const Parser &rhs);

	void		readInput();
    void		readFile(const std::string & filename);
	std::string	replaceSpacings(std::string & line);
    std::list<struct sParsedLine>&  getListOfParsedLines();
    std::list<std::string>&         getFilenames();

private:
	bool				_endOfInput(std::string & line);
	std::string			_clearCommentFromLine(const std::string & line);
    sParsedLine*		_parseLine(std::string & line);
	bool				_isInstructionWithoutValue(const std::string & line);
	bool				_isInstructionWithValue(const std::string & line);

    std::list<struct sParsedLine>   _listOfParsedLines;
    std::list<std::string>          _filenames;

};

#endif
