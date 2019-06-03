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

    std::map <std::string, eOperandType> operands = {
            {"int8",    E_INT8},
            {"int16",   E_INT16},
            {"int32",   E_INT32},
            {"float",   E_FLOAT},
            {"double",  E_DOUBLE}
    };
    if (!line->type.empty()) {
        IOperand const * result = this->_createOperand(operands[line->type], line->stringValue);
        std::cout << "Type: " << result->getType() << std::endl;
        std::cout << "Value: " << result->toString() << std::endl;
        std::cout << "Precision: " << result->getPrecision() << std::endl;
        this->_stack.push_front(result);

    }


}

std::list<const IOperand *> AbstractVm::getStack() const {
    return this->_stack;
}

IOperand const * AbstractVm::_createOperand( eOperandType type, std::string const & value ) const {

    IOperand *test;
    switch (type)
    {
        case E_INT8:
            return this->_createInt8(value);
        case E_INT16:
            return this->_createInt16(value);
        case E_INT32:
            return this->_createInt32(value);
        case E_FLOAT:
            return this->_createFloat(value);
        case E_DOUBLE:
            return this->_createDouble(value);
        default:
            break;
    }
}

IOperand const * AbstractVm::_createInt8(std::string const & value )const {
    eOperandType type = E_INT8;
    int intVal = std::stoi(value);
    return new Operand<int8_t> (type, intVal);
}

IOperand const * AbstractVm::_createInt16(std::string const & value )const {
    eOperandType type = E_INT16;
    int intVal = std::stoi(value);
    return new Operand<int16_t> (type, intVal);
}

IOperand const * AbstractVm::_createInt32(std::string const & value )const {
    eOperandType type = E_INT32;
    int intVal = std::stoi(value);
    return new Operand<int32_t> (type, intVal);
}

IOperand const * AbstractVm::_createFloat(std::string const & value )const {
    eOperandType type = E_FLOAT;
    float floatVal = std::stof(value);
    return new Operand<float> (type, floatVal);
}

IOperand const * AbstractVm::_createDouble(std::string const & value )const{
    eOperandType type = E_DOUBLE;
    double floatVal = std::stod(value);
    return new Operand<double> (type, floatVal);
}