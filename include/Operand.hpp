#ifndef OPERAND_HPP
#define OPERAND_HPP

#include <string>
#include <sstream>
#include <iomanip>
#include "IOperand.hpp"
#include "Factory.hpp"

template <typename T>
class Operand : public IOperand {

public:
    Operand(const eOperandType type, const T value, const int precision) {
        std::ostringstream out;
        out << std::fixed << std::setprecision(precision) << value;
        this->_stringValue = out.str();
        this->_type = type;
        this->_value = value;
        this->_precision = precision;
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
        return this->_precision;
    }

    std::string const & toString( void ) const {
        return this->_stringValue;
    }

    virtual IOperand const * operator+( IOperand const & rhs ) const {

        eOperandType	type;
        std::string     newValue;
        Factory *factory = new Factory;

        if (rhs.getType() > this->getType()) {
            type = rhs.getType();
        } else {
            type = this->getType();
        }
        if (type < 3) {
            newValue = std::to_string(std::stoi(this->toString()) + std::stoi(rhs.toString()));
        } else {
            newValue = std::to_string(std::stod(this->toString()) + std::stod(rhs.toString()));
        }
        IOperand const * result = factory->createOperand(type, newValue);
        std::cout << "AddType: " << result->getType() << std::endl;
        std::cout << "AddValue: " << result->toString() << std::endl;
        std::cout << "AddPrecision: " << result->getPrecision() << std::endl;
        return  result;
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
    int             _precision;
};

#endif //OPERAND_HPP
