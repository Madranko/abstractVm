#ifndef OPERAND_HPP
#define OPERAND_HPP

#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include "IOperand.hpp"
#include "Factory.hpp"

template <typename T>
class Operand : public IOperand {

public:
    Operand(const eOperandType type, const T value, const int precision) {
        if (type == E_INT8) {
            this->_stringValue = std::to_string(value);
        } else {
            std::ostringstream out;
            out << std::fixed << std::setprecision(precision) << value;
            this->_stringValue = out.str();
        }

        this->_factory = new Factory;
        this->_type = type;
        this->_value = value;
        this->_precision = precision;
    }

    Operand(const Operand & copy) {
        *this = copy;
    }

    ~Operand() {
        delete(this->_factory);
    }

    Operand &operator=(const Operand &rhs) {
        this->_type = rhs.getType();
        this->_value = rhs.getValue();
        this->_precision = rhs.getPrecision();
        this->_factory = rhs.getFactory();
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

    Factory *           getFactory() const {
        return this->_factory;
    }

    virtual IOperand const * operator+( IOperand const & rhs ) const {

        eOperandType	type;
        std::string     newValue;

        if (rhs.getType() > this->getType()) {
            type = rhs.getType();
        } else {
            type = this->getType();
        }
        if (type < E_FLOAT) {
            newValue = std::to_string(std::stoi(this->toString()) + std::stoi(rhs.toString()));
        } else {
            newValue = std::to_string(std::stod(this->toString()) + std::stod(rhs.toString()));
        }
        IOperand const * result = this->_factory->createOperand(type, newValue);
        return  result;
    };

    virtual IOperand const * operator-( IOperand const & rhs ) const{
        eOperandType	type;
        std::string     newValue;

        if (rhs.getType() > this->getType()) {
            type = rhs.getType();
        } else {
            type = this->getType();
        }
        if (type < E_FLOAT) {
            newValue = std::to_string(std::stoi(this->toString()) - std::stoi(rhs.toString()));
        } else {
            newValue = std::to_string(std::stod(this->toString()) - std::stod(rhs.toString()));
        }
        IOperand const * result = this->_factory->createOperand(type, newValue);
        return  result;
    }

    virtual IOperand const * operator*( IOperand const & rhs ) const{
        eOperandType	type;
        std::string     newValue;

        if (rhs.getType() > this->getType()) {
            type = rhs.getType();
        } else {
            type = this->getType();
        }
        if (type < E_FLOAT) {
            newValue = std::to_string(std::stoi(this->toString()) * std::stoi(rhs.toString()));
        } else {
            newValue = std::to_string(std::stod(this->toString()) * std::stod(rhs.toString()));
        }
        IOperand const * result = this->_factory->createOperand(type, newValue);
        return  result;
    }

    virtual IOperand const * operator/( IOperand const & rhs ) const{
        eOperandType	type;
        std::string     newValue;

        if (rhs.getType() > this->getType()) {
            type = rhs.getType();
        } else {
            type = this->getType();
        }
        if (type < E_FLOAT) {
            newValue = std::to_string(std::stoi(this->toString()) / std::stoi(rhs.toString()));
        } else {
            newValue = std::to_string(std::stod(this->toString()) / std::stod(rhs.toString()));
        }
        IOperand const * result = this->_factory->createOperand(type, newValue);
        return  result;
    }

    virtual IOperand const * operator%( IOperand const & rhs ) const{
        eOperandType	type;
        std::string     newValue;

        if (rhs.getType() > this->getType()) {
            type = rhs.getType();
        } else {
            type = this->getType();
        }
        if (type < E_FLOAT) {
            newValue = std::to_string(std::stoi(this->toString()) % std::stoi(rhs.toString()));
        } else {
            newValue = std::to_string(fmod(std::stod(this->toString()), std::stod(rhs.toString())));
//            newValue = std::to_string(std::stod(this->toString()) % std::stod(rhs.toString()));
        }
        IOperand const * result = this->_factory->createOperand(type, newValue);
        return  result;
    }


    virtual bool operator==( IOperand const & rhs ) const{
        return (this->getType() == rhs.getType() && this->toString() == rhs.toString());
    }


private:
    eOperandType    _type;
    T               _value;
    std::string     _stringValue;
    int             _precision;
    Factory *       _factory;
};

#endif //OPERAND_HPP
