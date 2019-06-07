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

/*
 * NotEnoughElementsException
 */

AvmException::
NotEnoughElementsException::NotEnoughElementsException(const std::string & command, const unsigned int line)  {

    this->_error = "Error on line " + std::to_string(line) + ": Not enough elements in stack to execute " + command + " instruction";
}

AvmException::
NotEnoughElementsException::NotEnoughElementsException(const AvmException::NotEnoughElementsException &copy) {
    *this = copy;
}

AvmException::
NotEnoughElementsException::NotEnoughElementsException::~NotEnoughElementsException() throw() {}

std::string AvmException::NotEnoughElementsException::getError() const {
    return this->_error;
}

AvmException::NotEnoughElementsException &
AvmException::NotEnoughElementsException::operator=(AvmException::NotEnoughElementsException const & rhs){
    this->_error = rhs.getError();
    return (*this);
}

const char	*
AvmException::NotEnoughElementsException::what() const throw() {
    return (this->_error.c_str());
}

/*
 * EmptyStackException
 */

AvmException::
EmptyStackException::EmptyStackException(const std::string & command, const unsigned int line)  {

    this->_error = "Error on line " + std::to_string(line) + ": " + command + " on empty stack";
}

AvmException::
EmptyStackException::EmptyStackException(const AvmException::EmptyStackException &copy) {
    *this = copy;
}

AvmException::
EmptyStackException::EmptyStackException::~EmptyStackException() throw() {}

std::string AvmException::EmptyStackException::getError() const {
    return this->_error;
}

AvmException::EmptyStackException &
AvmException::EmptyStackException::operator=(AvmException::EmptyStackException const & rhs){
    this->_error = rhs.getError();
    return (*this);
}

const char	*
AvmException::EmptyStackException::what() const throw() {
    return (this->_error.c_str());
}

/*
 * EmptyStackException
 */

AvmException::
AssertFalseException::AssertFalseException(const unsigned int line)  {

    this->_error = "Error on line " + std::to_string(line) + ": Assert instruction is false";
}

AvmException::
AssertFalseException::AssertFalseException(const AvmException::AssertFalseException &copy) {
    *this = copy;
}

AvmException::
AssertFalseException::AssertFalseException::~AssertFalseException() throw() {}

std::string AvmException::AssertFalseException::getError() const {
    return this->_error;
}

AvmException::AssertFalseException &
AvmException::AssertFalseException::operator=(AvmException::AssertFalseException const & rhs){
    this->_error = rhs.getError();
    return (*this);
}

const char	*
AvmException::AssertFalseException::what() const throw() {
    return (this->_error.c_str());
}

/*
 * DivisionOnZeroException
 */

AvmException::
DivisionOnZeroException::DivisionOnZeroException(const unsigned int line)  {

    this->_error = "Error on line " + std::to_string(line) + ": Division by zero";
}

AvmException::
DivisionOnZeroException::DivisionOnZeroException(const AvmException::DivisionOnZeroException &copy) {
    *this = copy;
}

AvmException::
DivisionOnZeroException::DivisionOnZeroException::~DivisionOnZeroException() throw() {}

std::string AvmException::DivisionOnZeroException::getError() const {
    return this->_error;
}

AvmException::DivisionOnZeroException &
AvmException::DivisionOnZeroException::operator=(AvmException::DivisionOnZeroException const & rhs){
    this->_error = rhs.getError();
    return (*this);
}

const char	*
AvmException::DivisionOnZeroException::what() const throw() {
    return (this->_error.c_str());
}

/*
 * ModuloOnZeroException
 */

AvmException::
ModuloOnZeroException::ModuloOnZeroException(const unsigned int line)  {

    this->_error = "Error on line " + std::to_string(line) + ": Modulo by zero";
}

AvmException::
ModuloOnZeroException::ModuloOnZeroException(const AvmException::ModuloOnZeroException &copy) {
    *this = copy;
}

AvmException::
ModuloOnZeroException::ModuloOnZeroException::~ModuloOnZeroException() throw() {}

std::string AvmException::ModuloOnZeroException::getError() const {
    return this->_error;
}

AvmException::ModuloOnZeroException &
AvmException::ModuloOnZeroException::operator=(AvmException::ModuloOnZeroException const & rhs){
    this->_error = rhs.getError();
    return (*this);
}

const char	*
AvmException::ModuloOnZeroException::what() const throw() {
    return (this->_error.c_str());
}

/*
 * InvalidTypeException
 */

AvmException::
InvalidTypeException::InvalidTypeException(const std::string & instruction, const unsigned int line)  {

    this->_error = "Error on line " + std::to_string(line) + ": Invalid type provided for " + instruction + " instruction";
}

AvmException::
InvalidTypeException::InvalidTypeException(const AvmException::InvalidTypeException &copy) {
    *this = copy;
}

AvmException::
InvalidTypeException::InvalidTypeException::~InvalidTypeException() throw() {}

std::string AvmException::InvalidTypeException::getError() const {
    return this->_error;
}

AvmException::InvalidTypeException &
AvmException::InvalidTypeException::operator=(AvmException::InvalidTypeException const & rhs){
    this->_error = rhs.getError();
    return (*this);
}

const char	*
AvmException::InvalidTypeException::what() const throw() {
    return (this->_error.c_str());
}

/*
 * NoExitCommandException
 */

AvmException::
NoExitCommandException::NoExitCommandException()  {

    this->_error = "Exit command not found";
}

AvmException::
NoExitCommandException::NoExitCommandException(const AvmException::NoExitCommandException &copy) {
    *this = copy;
}

AvmException::
NoExitCommandException::NoExitCommandException::~NoExitCommandException() throw() {}

std::string AvmException::NoExitCommandException::getError() const {
    return this->_error;
}

AvmException::NoExitCommandException &
AvmException::NoExitCommandException::operator=(AvmException::NoExitCommandException const & rhs){
    this->_error = rhs.getError();
    return (*this);
}

const char	*
AvmException::NoExitCommandException::what() const throw() {
    return (this->_error.c_str());
}
