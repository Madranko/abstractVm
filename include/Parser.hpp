#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <regex>
#include <algorithm>
#include <list>
#include "eOperandType.hpp"
#include "AvmException.hpp"

class Parser {

public:
	Parser(int argc, char **argv);

	Parser(const Parser &copy);

	~Parser();

	Parser &operator=(const Parser &rhs);

	void        parse();
	void        clearList();
	void		readInput();
    void		readFile(const std::string & filename);
    bool        validate();
	std::string	replaceSpacings(std::string & line);
    std::list<struct sParsedLine>  getListOfParsedLines() const;
    std::list<std::string>         getFilenames() const;

private:
	bool				_endOfInput(std::string & line);
	std::string			_clearCommentFromLine(const std::string & line);
    sParsedLine*		_parseLine(std::string & line, const unsigned int lineNumber);
	bool				_isInstructionWithoutValue(const std::string & line);
	bool				_isInstructionWithValue(const std::string & line);

    std::list<struct sParsedLine>   _listOfParsedLines;
    std::list<std::string>          _filenames;


};

#endif
