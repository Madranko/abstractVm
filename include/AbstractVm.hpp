#ifndef ABSTRACT_VM_HPP
#define ABSTRACT_VM_HPP

#include <list>
#include <string>
#include <iostream>
#include <map>
#include "eOperandType.hpp"
#include "IOperand.hpp"
#include "Operand.hpp"

class AbstractVm {

public:
    AbstractVm();
    AbstractVm(const AbstractVm &copy);
    ~AbstractVm();
    AbstractVm &operator=(const AbstractVm &rhs);

    std::list<const IOperand *> getStack() const ;
    void                        executeInstrunction(std::list<struct sParsedLine>::iterator line);


private:
    std::list<const IOperand *> _stack;

    IOperand const * _createOperand( eOperandType type, std::string const & value ) const;
    IOperand const * _createInt8( std::string const & value ) const;
    IOperand const * _createInt16( std::string const & value ) const;
    IOperand const * _createInt32( std::string const & value ) const;
    IOperand const * _createFloat( std::string const & value ) const;
    IOperand const * _createDouble( std::string const & value ) const;


};

#endif //ABSTRACT_VM_HPP
