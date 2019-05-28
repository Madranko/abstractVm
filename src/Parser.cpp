#include "../include/Parser.hpp"

Parser::Parser() {
	this->_error = false;
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
 * Search for ';' symbol. Returns substring before ';'
 * @param string line to search.
 * @return string substring before ';'
 */
std::string   Parser::_clearCommentFromLine(const std::string &line){

	int pos = line.find(';');
	std::string clearLine = line.substr (0, pos);
	return clearLine;
}

/**
 * Check if line is ';;'.
 * @param line string to search.
 * @return bool true if regex match, false if does not
 */
bool   Parser::_endOfInput(const std::string & line) {
	std::regex endRegex2("^;;$");
	return regex_match(line, endRegex2);
}

/**
 * Read user input until exit or ';;'.
 * @return void.
 */
void   Parser::readInput(){

	std::string line;
	std::string instruction;
	bool		end = false;

	while(true) {
		std::getline(std::cin, line);
		if ((end = this->_endOfInput(line))) {
			break;
		}
		line = this->_clearCommentFromLine(line);
		line = this->_parseLine(line);
//		std::cout << "PARSED INSTRUCION: |" << this->_parsedLine->instruction << "|" << std::endl;
	}
}

/**
 * Replace all unnecessary symbols
 * @param string line to clear.
 * @return string clear line
 */
std::string   Parser::replaceSpacings(std::string &line){
	std::string chars = "\t ";
	line.erase(line.find_last_not_of(chars) + 1);
	line.erase(0, line.find_first_not_of(chars)); //trim line
	replace(line.begin(), line.end(), '\t', ' '); //replace tab on whitespace
	std::regex regexpr("\\s{2,}");
	line = regex_replace(line, regexpr, " "); //leaves only one space
	return line;
}


std::string   Parser::_parseLine(std::string &line) {
	struct parsedLine *parsedLine = new struct parsedLine;
	line = this->replaceSpacings(line);
	if (this->_isInstructionWithoutValue(line)) {
		parsedLine->instruction = line;
	} else if (this->_isInstructionWithValue(line)) {
		int posSpace = line.find(' ');
		int posOpenParenthesis = line.find('(');
		int posCloseParenthesis = line.find(')');
		parsedLine->instruction = line.substr (0, posSpace);
		parsedLine->type = line.substr(posSpace + 1, posOpenParenthesis - posSpace - 1);
		std::string stingValue = line.substr(posOpenParenthesis + 1, posCloseParenthesis - posOpenParenthesis - 1);
		parsedLine->stringValue = this->replaceSpacings(stingValue);
	} else if (!line.empty()) {
		std::cout << "Error" << std::endl;
	} else {
		std::cout << "Empty" << std::endl;
	}
//	this->_parseInstruction(line);
    return line;
}

std::string   Parser::_parseInstruction(const std::string &line, const bool & hasValue){

//	int pos = line.find(' ');
//	std::string clearLine = line.substr (0, pos);

	if (hasValue) {
		std::cout << "line: " << line << std::endl;

	} else {
		std::cout << "line: " << line << std::endl;
	}
	return line;
}



/**
 * Check if instruction not requires value
 * @param string line to check.
 * @return bool
 */
bool   Parser::_isInstructionWithoutValue(const std::string &line){
	std::regex regexpr("^\\s*(pop|dump|add|sub|mul|div|mod|print|exit)\\s*$");
    return regex_match(line, regexpr);
}

/**
 * Check if instruction requires value
 * @param string line to check.
 * @return bool
 */
bool   Parser::_isInstructionWithValue(const std::string &line){
	std::regex regexpr("^\\s*(push|assert)\\s*(((int8|int16|int32)\\(\\s*[-]?[0-9]+\\s*\\)\\s*)|((float|double)\\(\\s*[-]?[0-9]+(..[0-9]+)?\\s*\\)\\s*))$");
	return regex_match(line, regexpr);
}






// ^ *(pop|dump|add|sub|mul|div|mod|print|exit) *  ----> commands with no params
// ^ *(push|assert) (((int8|int16|int32)\([-]?[0-9]+\) *)|((float|double)\([-]?[0-9]+(..[0-9]+)?\) *))$  ----> commands with params