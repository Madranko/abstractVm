#include "../include/AbstractVm.hpp"

AbstractVm::AbstractVm() {
    this->_factory = new Factory;
    this->_exitCommand = false;
}

AbstractVm::AbstractVm(const AbstractVm & copy) {
    *this = copy;
}

AbstractVm::~AbstractVm() {
    this->_stack.clear();
    delete(this->_factory);
}

AbstractVm &AbstractVm::operator=(const AbstractVm &rhs) {

    this->_factory = rhs.getFactory();
    this->_stack = rhs.getStack();
    return *this;
}

void AbstractVm::startExecution(std::list<struct sParsedLine> &list) {
    this->_exitCommand = false;
    for (std::list<struct sParsedLine>::iterator parsedLine = list.begin(); parsedLine != list.end(); parsedLine++) {
        this->executeInstruction(parsedLine);
        if (this->_exitCommand) {
            return;
        }
    }
    if (!this->_exitCommand) {
        throw (AvmException::NoExitCommandException());
    }
}

void AbstractVm::executeInstruction(std::list<struct sParsedLine>::iterator line) {

    if (!line->empty) {
        typedef void (AbstractVm::*instructionMethod)(std::list<struct sParsedLine>::iterator);
        std::map<std::string, instructionMethod> instructions = {
                {"push", &AbstractVm::_push},
                {"assert", &AbstractVm::_assert},
                {"pop",  &AbstractVm::_pop},
                {"dump", &AbstractVm::_dump},
                {"add",  &AbstractVm::_add},
                {"sub",  &AbstractVm::_sub},
                {"mul",  &AbstractVm::_mul},
                {"div",  &AbstractVm::_div},
                {"mod",  &AbstractVm::_mod},
                {"min",  &AbstractVm::_min},
                {"max",  &AbstractVm::_max},
                {"avg",  &AbstractVm::_avg},
                {"print",&AbstractVm::_print},
                {"exit", &AbstractVm::_exit}
        };
        instructionMethod method = instructions[line->instruction];
        (this->*method)(line);
    }
}

void    AbstractVm::_push(std::list<struct sParsedLine>::iterator line) {
    std::map <std::string, eOperandType> operands = {
            {"int8",    E_INT8},
            {"int16",   E_INT16},
            {"int32",   E_INT32},
            {"float",   E_FLOAT},
            {"double",  E_DOUBLE}
    };
    IOperand const * result = this->_factory->createOperand(operands[line->type], line->stringValue);
    this->_stack.push_front(result);
}

void    AbstractVm::_assert(std::list<struct sParsedLine>::iterator line) {
    this->_stackNotEmpty("assert", line->line_num);
    std::map <std::string, eOperandType> operands = {
            {"int8",    E_INT8},
            {"int16",   E_INT16},
            {"int32",   E_INT32},
            {"float",   E_FLOAT},
            {"double",  E_DOUBLE}
    };
    IOperand const * result = this->_factory->createOperand(operands[line->type], line->stringValue);
    if (!(*result == *(this->_stack.front()))) {
        delete(result);
        throw(AvmException::AssertFalseException(line->line_num));
    }
    delete(result);
}

void    AbstractVm::_pop(std::list<struct sParsedLine>::iterator line) {

    this->_stackNotEmpty("pop", line->line_num);
    this->_stack.pop_front();
}


void    AbstractVm::_dump(std::list<struct sParsedLine>::iterator line) {
    line->line_num += 0;
    std::map <eOperandType, std::string> types = {
            {E_INT8, "int8"},
            {E_INT16, "int16"},
            {E_INT32, "int32"},
            {E_FLOAT, "float"},
            {E_DOUBLE, "double"}
    };
    for (std::list<const IOperand *>::iterator element = this->_stack.begin(); element != this->_stack.end(); element++){
        std::cout << (*element)->toString() << std::endl;
//            std::cout << types[(*element)->getType()] << "(" << (*element)->toString() << ")" << std::endl;
    }
}

void    AbstractVm::_add(std::list<struct sParsedLine>::iterator line) {

    this->_sizeValid("add", line->line_num);
    IOperand const * first;
    IOperand const * second;
    first = this->_stack.front();
    this->_stack.pop_front();
    second = this->_stack.front();
    this->_stack.pop_front();
    this->_stack.push_front(*first + *second);
    delete(first);
    delete(second);
}

void    AbstractVm::_sub(std::list<struct sParsedLine>::iterator line) {

    this->_sizeValid("sub", line->line_num);
    IOperand const * first;
    IOperand const * second;
    first = this->_stack.front();
    this->_stack.pop_front();
    second = this->_stack.front();
    this->_stack.pop_front();
    this->_stack.push_front(*second - *first);
    delete(first);
    delete(second);
}

void    AbstractVm::_mul(std::list<struct sParsedLine>::iterator line) {

    this->_sizeValid("mul", line->line_num);
    IOperand const * first;
    IOperand const * second;
    first = this->_stack.front();
    this->_stack.pop_front();
    second = this->_stack.front();
    this->_stack.pop_front();
    this->_stack.push_front(*first * *second);
    delete(first);
    delete(second);
}

void    AbstractVm::_div(std::list<struct sParsedLine>::iterator line) {

    this->_sizeValid("mul", line->line_num);
    IOperand const * first;
    IOperand const * second;
    first = this->_stack.front();
    this->_stack.pop_front();
    second = this->_stack.front();
    if (first->toString() == "0") {
        delete(first);
        delete(second);
        throw (AvmException::DivisionOnZeroException(line->line_num));
    }
    this->_stack.pop_front();
    this->_stack.push_front(*second / *first);
    delete(first);
    delete(second);
}

void    AbstractVm::_mod(std::list<struct sParsedLine>::iterator line) {

    this->_sizeValid("mul", line->line_num);
    IOperand const * first;
    IOperand const * second;
    first = this->_stack.front();
    this->_stack.pop_front();
    second = this->_stack.front();
    if (first->toString() == "0") {
        delete(first);
        delete(second);
        throw (AvmException::ModuloOnZeroException(line->line_num));
    }
    this->_stack.pop_front();
    this->_stack.push_front(*second % *first);
    delete(first);
    delete(second);
}

void    AbstractVm::_min(std::list<struct sParsedLine>::iterator line) {

    this->_sizeValid("min", line->line_num);
    IOperand const * first;
    IOperand const * second;
    first = this->_stack.front();
    this->_stack.pop_front();
    second = this->_stack.front();
    this->_stack.pop_front();
    if (*second < *first) {
        this->_stack.push_front(second);
        delete(first);
    } else {
        this->_stack.push_front(first);
        delete(second);
    }
}

void    AbstractVm::_max(std::list<struct sParsedLine>::iterator line) {

    this->_sizeValid("min", line->line_num);
    IOperand const * first;
    IOperand const * second;
    first = this->_stack.front();
    this->_stack.pop_front();
    second = this->_stack.front();
    this->_stack.pop_front();
    if (*second > *first) {
        this->_stack.push_front(second);
        delete(first);
    } else {
        this->_stack.push_front(first);
        delete(second);
    }
}

void    AbstractVm::_avg(std::list<struct sParsedLine>::iterator line) {

    this->_sizeValid("min", line->line_num);
    IOperand const * first;
    IOperand const * second;
    IOperand const * sum;
    IOperand const * two = this->_factory->createOperand(E_INT32, "2");
    first = this->_stack.front();
    this->_stack.pop_front();
    second = this->_stack.front();
    this->_stack.pop_front();
    sum = *first + *second;
    this->_stack.push_front(*sum / *two);
    delete(first);
    delete(second);
    delete(sum);
    delete(two);
}

void    AbstractVm::_print(std::list<struct sParsedLine>::iterator line) {
    this->_stackNotEmpty("print", line->line_num);
    IOperand const * first;
    first = this->_stack.front();
    if (first->getType() != E_INT8) {
        delete(first);
        throw (AvmException::InvalidTypeException("print", line->line_num));
    } else {
        std::cout << static_cast<char>(std::stoi(first->toString())) << std::endl;
    }
}

void    AbstractVm::_exit(std::list<struct sParsedLine>::iterator line) {
    line->line_num = 0;
    this->_exitCommand = true;
}

std::list<const IOperand *> AbstractVm::getStack() const {
    return this->_stack;
}

Factory *                   AbstractVm::getFactory() const {
    return this->_factory;
}

void                        AbstractVm::_sizeValid(const std::string & command, unsigned int line_num) {
    if (this->_stack.size() < 2) {
        throw (AvmException::NotEnoughElementsException(command, line_num));
    }
}

void                        AbstractVm::_stackNotEmpty(const std::string &command, unsigned int line_num){
    if (!this->_stack.size()) {
        throw (AvmException::EmptyStackException(command, line_num));
    }
}

void    AbstractVm::clearStack() {
    this->_stack.clear();
}