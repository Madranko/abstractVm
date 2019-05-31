#include "../include/Parser.hpp"

Parser::Parser(int argc, char **argv) {

    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            std::string filename(argv[i]);
            this->_filenames.push_back(filename);
        }
    }
}

Parser::Parser(const Parser &copy) {
    *this = copy;
}

Parser::~Parser() {}

Parser &Parser::operator=(const Parser &rhs) {

    return *this;
}

/**
 * Read user input until exit or ';;'.
 * @return void.
 */
void   Parser::readInput() {

    std::string         line;
    struct sParsedLine *parsedLine;
    int                 lineNumber = 1;

    while(true) {
        std::getline(std::cin, line);
        if (this->_endOfInput(line)) {
            break;
        }
        line = this->_clearCommentFromLine(line);
        parsedLine = this->_parseLine(line);
        parsedLine->line_num = lineNumber;
        this->_listOfParsedLines.push_back(*parsedLine);
        lineNumber++;
    }
}

void    Parser::readFile(const std::string & filename) {

    std::string         line;
    struct sParsedLine* parsedLine;
    int                 lineNumber = 1;

    std::ifstream   file;
    file.open (filename);
    if (!file.is_open()) {
        std::cout << "Error File" << std::endl;
    } else {
        std::cout << "Success" << std::endl;
        while(true) {
            std::getline(file, line);
            if (this->_endOfInput(line)) {
                break;
            }
            line = this->_clearCommentFromLine(line);
            parsedLine = this->_parseLine(line);
            parsedLine->line_num = lineNumber;
            this->_listOfParsedLines.push_back(*parsedLine);
            lineNumber++;
        }
    }
    file.close();
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
bool   Parser::_endOfInput(std::string & line) {
    std::string chars = "\t ";
    line.erase(line.find_last_not_of(chars) + 1);
    line.erase(0, line.find_first_not_of(chars));
    std::regex endRegex2("^;;$");
    return regex_match(line, endRegex2);
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


sParsedLine *   Parser::_parseLine(std::string &line) {
    struct sParsedLine *parsedLine = new struct sParsedLine;
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
        parsedLine->error = "Syntax error";
        std::cout << "Error" << std::endl;
    } else {
        parsedLine->empty = true;
        std::cout << "Empty" << std::endl;
    }
    return parsedLine;
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

std::list<struct sParsedLine> & Parser::getListOfParsedLines() {
    return this->_listOfParsedLines;
}

std::list<std::string>&         Parser::getFilenames() {
    return this->_filenames;
}





// ^ *(pop|dump|add|sub|mul|div|mod|print|exit) *  ----> commands with no params
// ^ *(push|assert) (((int8|int16|int32)\([-]?[0-9]+\) *)|((float|double)\([-]?[0-9]+(..[0-9]+)?\) *))$  ----> commands with params