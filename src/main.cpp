#include <string>
#include <iostream>
#include "Parser.cpp"
#include "../include/AvmParseException.hpp"
#include "../include/AbstractVm.hpp"

int main(int argc, char **argv)
{
    std::list<struct sParsedLine> list;
	Parser parser(argc, argv);
    AbstractVm avm;

	parser.parse();
	if (parser.validate()) {
	    list = parser.getListOfParsedLines();
        for (std::list<struct sParsedLine>::iterator parsedLine = list.begin(); parsedLine != list.end(); parsedLine++) {
            avm.executeInstrunction(parsedLine);
        }
	}
}


