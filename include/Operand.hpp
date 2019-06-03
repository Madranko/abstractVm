#ifndef OPERAND_HPP
#define OPERAND_HPP

#include <string>
#include "IOperand.hpp"

template <typename T>
class Operand : public IOperand {

public:
    Operand(eOperandType type, T value) {
        this->_type = type;
        this->_value = value;
        this->_stringValue = std::to_string(value);

    }

    Operand(const Operand & copy) {
        *this = copy;
    }

    ~Operand() {

    }

    Operand &operator=(const Operand &rhs) {
        this->_type = rhs.getType();
        this->_value = rhs.getValue();
        this->_precision = rhs.getPrecision();
        return (*this);
    }

    eOperandType    getType() const {
        return this->_type;
    }

    T               getValue() const {
        return this->_value;
    }

    int             getPrecision() const {
        return this->_type;
    }

    std::string const & toString( void ) const {
        return this->_stringValue;
    }

    virtual IOperand const * operator+( IOperand const & rhs ) const{
//        eOperandType	precision;
//        std::string 	str;
//
//        if (rhs.getType() > this->_type)
//            precision = rhs.getType();
//        else
//            precision = this->_type;
//        //std::cout << precision << std::endl;
//        str = makeNum(this->getValue(), rhs.getValue(), precision, 1);
//        return (makeType(precision, str));
        return this;
    };

    virtual IOperand const * operator-( IOperand const & rhs ) const{
        return this;
    }

    virtual IOperand const * operator/( IOperand const & rhs ) const{
        return this;
    }

    virtual IOperand const * operator*( IOperand const & rhs ) const{
        return this;
    }

    virtual IOperand const * operator%( IOperand const & rhs ) const{
        return this;
    }


private:
    eOperandType    _type;
    T               _value;
    std::string     _stringValue;
};

#endif //OPERAND_HPP
