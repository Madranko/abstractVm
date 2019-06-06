#ifndef FACTORY_HPP
#define FACTORY_HPP

#include <map>
#include <limits>
#include <iostream>
#include <sstream>
#include <cfloat>
#include <cstdint>
#include "IOperand.hpp"
#include "eOperandType.hpp"
#include "AvmException.hpp"

class Factory {

public:
    Factory();
    Factory(const Factory &copy);
    ~Factory();
    Factory&operator=(const Factory &rhs);
    IOperand const * createOperand( eOperandType type, std::string const & value ) const;

private:
    int                 _findPrecision(const std::string & value) const;
    IOperand const *    _createInt8( std::string const & value ) const;
    IOperand const *    _createInt16( std::string const & value ) const;
    IOperand const *    _createInt32( std::string const & value ) const;
    IOperand const *    _createFloat( std::string const & value ) const;
    IOperand const *    _createDouble( std::string const & value ) const;
};

#endif //FACTORY_HPP
