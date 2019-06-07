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
    static_cast<void >(rhs);
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
    long long int intVal = std::stoll(value);
    if (intVal > INT8_MAX) {
        throw AvmException::OverflowException("int8");
    } else if (intVal < INT8_MIN) {
        throw AvmException::UnderflowException("int8");
    }
    eOperandType type = E_INT8;
    return new Operand<int8_t>(type, static_cast<int8_t>(intVal), 0);
}

IOperand const * Factory::_createInt16(std::string const & value )const {
    long long int intVal = std::stoll(value);
    if (intVal > INT16_MAX) {
        throw AvmException::OverflowException("int16");
    } else if (intVal < INT16_MIN) {
        throw AvmException::UnderflowException("int16");
    }
    eOperandType type = E_INT16;
    return new Operand<int16_t> (type, static_cast<int16_t>(intVal), 0);
}

IOperand const * Factory::_createInt32(std::string const & value )const {
    long long int intVal = std::stoll(value);
    if (intVal > INT32_MAX) {
        throw AvmException::OverflowException("int32");
    } else if (intVal < INT32_MIN) {
        throw AvmException::UnderflowException("int32");
    }
    eOperandType type = E_INT32;
    return new Operand<int32_t> (type, static_cast<int32_t>(intVal), 0);
}

IOperand const * Factory::_createFloat(std::string const & value )const {

    long double floatVal = std::stold(value);
    if (floatVal > FLT_MAX) {
        throw AvmException::OverflowException("float");
    } else if (floatVal < -FLT_MAX) {
        throw AvmException::UnderflowException("float");
    }
    eOperandType type = E_FLOAT;
    int precision = this->_findPrecision(value);
    return new Operand<float> (type, static_cast<float>(floatVal), precision);
}

IOperand const * Factory::_createDouble(std::string const & value )const{

    long double doubleVal = std::stold(value);
    if (doubleVal > DBL_MAX) {
        throw AvmException::OverflowException("double");
    } else if (doubleVal < -DBL_MAX) {
        throw AvmException::UnderflowException("double");
    }
    int precision = this->_findPrecision(value);
    eOperandType type = E_DOUBLE;
    return new Operand<double>(type, static_cast<double>(doubleVal), precision);
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

















