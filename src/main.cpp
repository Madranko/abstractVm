#include <string>
#include <iostream>
#include "Parser.cpp"
#include "AvmException.hpp"
#include "../include/AbstractVm.hpp"

int main(int argc, char **argv)
{

    //todo: 1) Segmentation fault если в файле есть пучтая строка
    //todo: 2) Не выходит из парсера если в файле нет ;;

    std::list<struct sParsedLine> list;
	Parser parser(argc, argv);
    AbstractVm avm;

	parser.parse();
	if (parser.validate()) {
	    list = parser.getListOfParsedLines();
        for (std::list<struct sParsedLine>::iterator parsedLine = list.begin(); parsedLine != list.end(); parsedLine++) {
            try {
                avm.executeInstrunction(parsedLine);
            } catch (std::exception &exception) {
                std::cout << exception.what() << std::endl;
            }
        }
	}
}


