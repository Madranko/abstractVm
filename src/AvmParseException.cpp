#include "../include/AvmParseException.hpp"

/*
 * ParseException
 */

AvmParseException::
ParseException::ParseException(unsigned int line) {

    this->_error = "Parse error on line " + std::to_string(line);
}

AvmParseException::
ParseException::ParseException(const AvmParseException::ParseException &copy) {
    *this = copy;
}

AvmParseException::
ParseException::ParseException::~ParseException() throw() {}

std::string AvmParseException::ParseException::getError() const {
    return this->_error;
}

AvmParseException::ParseException &
AvmParseException::ParseException::operator=(AvmParseException::ParseException const & rhs){
    this->_error = rhs.getError();
    return (*this);
}

const char	*
AvmParseException::ParseException::what() const throw() {
    return (this->_error.c_str());
}

/*
 * FailedOpenFileException
 */

AvmParseException::
FailedOpenFileException::FailedOpenFileException(const std::string & fileName) {
    this->_error = "Failed to open file '" + fileName + "'";
}

AvmParseException::
FailedOpenFileException::FailedOpenFileException(const AvmParseException::FailedOpenFileException &copy) {
    *this = copy;
}

AvmParseException::
FailedOpenFileException::FailedOpenFileException::~FailedOpenFileException() throw() {}

std::string AvmParseException::FailedOpenFileException::getError() const {
    return this->_error;
}

AvmParseException::FailedOpenFileException &
AvmParseException::FailedOpenFileException::operator=(AvmParseException::FailedOpenFileException const & rhs){
    this->_error = rhs.getError();
    return (*this);
}

const char	*
AvmParseException::FailedOpenFileException::what() const throw() {
    return (this->_error.c_str());
}





