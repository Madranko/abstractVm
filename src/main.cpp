#include <string>
#include <iostream>
#include "Parser.cpp"

//int main(void)
int main(int argc, char **argv)
{
    std::list<struct sParsedLine> list;
	Parser parser(argc, argv);
	if (!parser.getFilenames().empty()) {
        std::list<std::string> filenames = parser.getFilenames();
        for (auto const & filename : filenames) {
            parser.readFile(filename);
            list = parser.getListOfParsedLines();

            for (std::list<struct sParsedLine>::iterator parsedLine = list.begin(); parsedLine != list.end(); parsedLine++) {
                std::cout << "|---------------------------------|" << std::endl;
                std::cout << "|" << parsedLine->instruction << "|" << std::endl;
                std::cout << "|" << parsedLine->type        << "|" << std::endl;
                std::cout << "|" << parsedLine->stringValue << "|" << std::endl;
                std::cout << "|" << parsedLine->error       << "|" << std::endl;
                std::cout << "|" << parsedLine->empty       << "|" << std::endl;
                std::cout << "|" << parsedLine->line_num    << "|" << std::endl;
                std::cout << "|---------------------------------|" << std::endl;
            }

        }
	} else {
        parser.readInput();

        for (std::list<struct sParsedLine>::iterator parsedLine = list.begin(); parsedLine != list.end(); parsedLine++) {
            std::cout << "|---------------------------------|" << std::endl;
            std::cout << "|" << parsedLine->instruction << "|" << std::endl;
            std::cout << "|" << parsedLine->type        << "|" << std::endl;
            std::cout << "|" << parsedLine->stringValue << "|" << std::endl;
            std::cout << "|" << parsedLine->error       << "|" << std::endl;
            std::cout << "|" << parsedLine->empty       << "|" << std::endl;
            std::cout << "|" << parsedLine->line_num    << "|" << std::endl;
            std::cout << "|---------------------------------|" << std::endl;
        }
	}

//    list = parser.getListOfParsedLines();






//	std::string line;
//	while(1) {
//		std::getline(std::cin, line);
//	}
}


