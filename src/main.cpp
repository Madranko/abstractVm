#include <string>
#include <iostream>
#include "Parser.cpp"
#include "../include/AvmParseException.hpp"

int main(int argc, char **argv)
{
    std::list<struct sParsedLine> list;
	Parser parser(argc, argv);
	parser.parse();
	if (parser.validate()) {
	    std::cout << "Success" << std::endl;
	}
}


