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

Parser::~Parser() {

}

Parser &Parser::operator=(const Parser &rhs) {

    this->_listOfParsedLines = rhs.getListOfParsedLines();
    this->_filenames = rhs.getFilenames();
    return *this;
}

void    Parser::parse() {
    if (!this->_filenames.empty()) {
        for (auto const & filename : this->_filenames) {
            this->readFile(filename);
        }
    } else {
        this->readInput();
    }
}

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
        parsedLine = this->_parseLine(line, lineNumber);
        this->_listOfParsedLines.push_back(*parsedLine);
        lineNumber++;
    }
}

void    Parser::readFile(const std::string & filename) {

    struct sParsedLine *parsedLine = new struct sParsedLine;
    std::string         line;
    unsigned int        lineNumber = 1;

    std::ifstream   file;
    file.open (filename);
    if (!file.is_open()) {
        parsedLine->error = "Error opening file '" + filename + "'";
        this->_listOfParsedLines.push_back(*parsedLine);
    } else {
        while(std::getline(file, line)) {
            line = this->_clearCommentFromLine(line);
            parsedLine = this->_parseLine(line, lineNumber);
            this->_listOfParsedLines.push_back(*parsedLine);
            lineNumber++;
        }
    }
    file.close();
}

sParsedLine *   Parser::_parseLine(std::string &line, const unsigned int lineNumber) {
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
        std::string stringValue = line.substr(posOpenParenthesis + 1, posCloseParenthesis - posOpenParenthesis - 1);
        parsedLine->stringValue = this->replaceSpacings(stringValue);
    } else if (!line.empty()) {
        parsedLine->error = "Parse error on line " + std::to_string(lineNumber) + "";
    } else {
        parsedLine->empty = true;
    }
    parsedLine->line_num = lineNumber;
    return parsedLine;
}

bool    Parser::validate() {
    bool success = true;
    for (std::list<struct sParsedLine>::iterator parsedLine = this->_listOfParsedLines.begin(); parsedLine != this->_listOfParsedLines.end(); parsedLine++) {
        if (!parsedLine->error.empty()) {
            std::cout << "\033[1;31m" + parsedLine->error + "\033[0m" << std::endl;
            success = false;
        }
    }
    return success;
}

std::string   Parser::_clearCommentFromLine(const std::string &line){

    int pos = line.find(';');
    std::string clearLine = line.substr (0, pos);
    return clearLine;
}

bool   Parser::_endOfInput(std::string & line) {
    std::string chars = "\t ";
    line.erase(line.find_last_not_of(chars) + 1);
    line.erase(0, line.find_first_not_of(chars));
    std::regex endRegex2("^;;$");
    return regex_match(line, endRegex2);
}

std::string   Parser::replaceSpacings(std::string &line){
    std::string chars = "\t ";
    line.erase(line.find_last_not_of(chars) + 1);
    line.erase(0, line.find_first_not_of(chars)); //trim line
    replace(line.begin(), line.end(), '\t', ' '); //replace tab on whitespace
    std::regex regexpr("\\s{2,}");
    line = regex_replace(line, regexpr, " "); //leaves only one space
    return line;
}

bool   Parser::_isInstructionWithoutValue(const std::string &line){
    std::regex regexpr("^\\s*(pop|dump|add|sub|mul|div|mod|min|max|avg|print|exit)\\s*$");
    return regex_match(line, regexpr);
}

bool   Parser::_isInstructionWithValue(const std::string &line){
    std::regex regexpr("^\\s*(push|assert)\\s*(((int8|int16|int32)\\(\\s*[-]?[0-9]+\\s*\\)\\s*)|((float|double)\\(\\s*[-]?[0-9]+[.]([0-9]+)+\\s*\\)\\s*))$");
    return regex_match(line, regexpr);
}


std::list<struct sParsedLine> Parser::getListOfParsedLines() const {
    return this->_listOfParsedLines;
}

std::list<std::string>         Parser::getFilenames() const {
    return this->_filenames;
}

void    Parser::clearList() {
    this->_listOfParsedLines.clear();
}