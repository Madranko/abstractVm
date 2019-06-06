#include "../include/Factory.hpp"
#include "../include/Operand.hpp"

Factory::Factory() {

}

Factory::Factory(const Factory & copy) {
    *this = copy;
}

Factory::~Factory() {

}

Factory &Factory::operator=(const Factory &rhs) {

    return *this;
}

IOperand const * Factory::createOperand( eOperandType type, std::string const & value ) const {

    typedef IOperand const *(Factory::*createType)(std::string const &)const;

    std::map <eOperandType, createType> types = {
            {E_INT8, &Factory::_createInt8},
            {E_INT16, &Factory::_createInt16},
            {E_INT32, &Factory::_createInt32},
            {E_FLOAT, &Factory::_createFloat},
            {E_DOUBLE, &Factory::_createDouble}
    };
    createType createMethod = types[type];
    return (this->*createMethod)(value);
}

IOperand const * Factory::_createInt8(std::string const & value )const {
    int intVal = std::stoi(value);
        eOperandType type = E_INT8;
        return new Operand<int8_t>(type, intVal, 0);
}

IOperand const * Factory::_createInt16(std::string const & value )const {
    eOperandType type = E_INT16;
    int intVal = std::stoi(value);
    return new Operand<int16_t> (type, intVal, 0);
}

IOperand const * Factory::_createInt32(std::string const & value )const {
    eOperandType type = E_INT32;
    int intVal = std::stoi(value);
    return new Operand<int32_t> (type, intVal, 0);
}

IOperand const * Factory::_createFloat(std::string const & value )const {
    int precision = this->_findPrecision(value);
    eOperandType type = E_FLOAT;
    float floatVal = std::stof(value);
    return new Operand<float> (type, floatVal, precision);
}

IOperand const * Factory::_createDouble(std::string const & value )const{

    long double num = std::stold(value);

    if (num > DBL_MAX)
        throw AvmException::OverflowException("double");
    else if (num < -DBL_MAX)
        throw AvmException::UnderflowException("double");
//    std::cout << "S: " << value <<std::endl;
//    std::cout << "N: " << num <<std::endl;
//    std::cout << "DBL_MAX: " << DBL_MAX <<std::endl;
//    std::cout << "DBL_MIN: " << DBL_MIN <<std::endl;

        int precision = this->_findPrecision(value);
        eOperandType type = E_DOUBLE;

        return new Operand<double>(type, num, precision);
}


int               Factory::_findPrecision(const std::string & value) const {

    std::string chars = "0";
    std::string copy = value;
    copy.erase(copy.find_last_not_of(chars) + 1);
    std::string delimiter = ".";
    int pos = copy.find(delimiter);
    std::string result = copy.substr(pos + 1, copy.length() - pos);
    return result.length();





//    value.substr(0, value.find('.')).compare(ss.str().substr(0, ss.str().find('.'))) != 0
}

















