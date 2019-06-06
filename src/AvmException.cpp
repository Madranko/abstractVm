#include "AvmException.hpp"

/*
 * OverflowException
 */

AvmException::
OverflowException::OverflowException(const std::string & type)  {

    this->_error = "Overflow exception on type " + type;
}

AvmException::
OverflowException::OverflowException(const AvmException::OverflowException &copy) {
    *this = copy;
}

AvmException::
OverflowException::OverflowException::~OverflowException() throw() {}

std::string AvmException::OverflowException::getError() const {
    return this->_error;
}

AvmException::OverflowException &
AvmException::OverflowException::operator=(AvmException::OverflowException const & rhs){
    this->_error = rhs.getError();
    return (*this);
}

const char	*
AvmException::OverflowException::what() const throw() {
    return (this->_error.c_str());
}

/*
 * UnderflowException
 */

AvmException::
UnderflowException::UnderflowException(const std::string & type)  {

    this->_error = "Underflow exception on type " + type;
}

AvmException::
UnderflowException::UnderflowException(const AvmException::UnderflowException &copy) {
    *this = copy;
}

AvmException::
UnderflowException::UnderflowException::~UnderflowException() throw() {}

std::string AvmException::UnderflowException::getError() const {
    return this->_error;
}

AvmException::UnderflowException &
AvmException::UnderflowException::operator=(AvmException::UnderflowException const & rhs){
    this->_error = rhs.getError();
    return (*this);
}

const char	*
AvmException::UnderflowException::what() const throw() {
    return (this->_error.c_str());
}
