#include "../include/Parser.hpp"

Parser::Parser() {

}

Parser::Parser(const Parser &copy) {
	*this = copy;
}

Parser::~Parser() {

}

Parser &Parser::operator=(const Parser &rhs) {

	return *this;
}


/**
 * Read user input until exit or ;;.
 * @return sum of `values`, or 0.0 if `values` is empty.
 */
void   Parser::readInput(){

	std::string line;
	bool		end = false;

	while(!end) {
		std::getline(std::cin, line);
		end = this->_endOfInput(line);


	}
}

bool   Parser::_endOfInput(const std::string & line) {
	std::cout << line << std::endl;
	std::regex endRegex2(".*;;.*");
	return regex_match(line, endRegex2);
}



