#include <string>
#include <iostream>
#include "Parser.cpp"
#include "AvmException.hpp"
#include "../include/AbstractVm.hpp"

int main(int argc, char **argv)
{
    std::list<struct sParsedLine> list;
    std::list<std::string>         filenames;
    Parser parser(argc, argv);
    AbstractVm avm;

    filenames = parser.getFilenames();
    if (!filenames.empty()) {
        for (auto const & filename : filenames) {
            parser.readFile(filename);
            if (parser.validate()) {
                list = parser.getListOfParsedLines();
                try {
                    avm.startExecution(list);
                } catch (std::exception &exception) {
                    std::string error = exception.what();
//                    error = "\033[1;31mbold" + error + "\033[0m";
                    std::cout << "\033[1;31m" + error + "\033[0m" << std::endl;
                }
            }
            parser.clearList();
            avm.clearStack();
        }
    } else {
        parser.readInput();
        if (parser.validate()) {
            list = parser.getListOfParsedLines();
            try {
                avm.startExecution(list);
            } catch (std::exception &exception) {
                std::cout << exception.what() << std::endl;
            }
            avm.clearStack();
        }
        parser.clearList();
    }
}


