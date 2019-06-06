#include "../include/AbstractVm.hpp"

AbstractVm::AbstractVm() {

}

AbstractVm::AbstractVm(const AbstractVm & copy) {
    *this = copy;
}

AbstractVm::~AbstractVm() {

}

AbstractVm &AbstractVm::operator=(const AbstractVm &rhs) {

    return *this;
}


void AbstractVm::executeInstrunction(std::list<struct sParsedLine>::iterator line) {

    if (line->type.empty()) {
        typedef void (AbstractVm::*instructionMethod)();
        std::map <std::string, instructionMethod> instructions = {
                {"add", &AbstractVm::_add},
                {"exit", &AbstractVm::_exit},
        };
        instructionMethod method = instructions[line->instruction];
        (this->*method)();
    } else {
        typedef void (AbstractVm::*instructionMethod)(std::list<struct sParsedLine>::iterator);
        std::map <std::string, instructionMethod> instructions = {
                {"push", &AbstractVm::_push},
        };
        instructionMethod method = instructions[line->instruction];
        (this->*method)(line);
    }
}

void    AbstractVm::_push(std::list<struct sParsedLine>::iterator line) {
    Factory *factory = new Factory;
    std::map <std::string, eOperandType> operands = {
            {"int8",    E_INT8},
            {"int16",   E_INT16},
            {"int32",   E_INT32},
            {"float",   E_FLOAT},
            {"double",  E_DOUBLE}
    };
    IOperand const * result = factory->createOperand(operands[line->type], line->stringValue);
    std::cout << "Type: " << result->getType() << std::endl;
    std::cout << "Value: " << result->toString() << std::endl;
    std::cout << "Precision: " << result->getPrecision() << std::endl;
    this->_stack.push_front(result);
    delete(factory);
}

void    AbstractVm::_add() {
    IOperand const * first;
    IOperand const * second;

    first = this->_stack.front();
    this->_stack.pop_front();
    second = this->_stack.front();
    IOperand const * newVal = *first + *second;

    delete(first);
    delete(second);
}

void    AbstractVm::_exit() {

}

std::list<const IOperand *> AbstractVm::getStack() const {
    return this->_stack;
}