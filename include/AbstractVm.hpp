#ifndef ABSTRACT_VM_HPP
#define ABSTRACT_VM_HPP

#include <list>
#include <string>
#include <iostream>
#include "eOperandType.hpp"
#include "IOperand.hpp"
#include "Operand.hpp"
#include "Factory.hpp"

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

    void    _push(std::list<struct sParsedLine>::iterator line);
    void    _add();
    void    _exit();




};

#endif //ABSTRACT_VM_HPP
