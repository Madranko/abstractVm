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
    Factory *                   getFactory() const ;
    void                        startExecution(std::list<struct sParsedLine> & list);
    void                        executeInstruction(std::list<struct sParsedLine>::iterator line);
    void                        clearStack();


private:
    bool                        _exitCommand;
    Factory *                   _factory;
    std::list<const IOperand *> _stack;
    void    _sizeValid(const std::string & command, unsigned int line_num);
    void    _stackNotEmpty(const std::string & command, unsigned int line_num);
    void    _push(std::list<struct sParsedLine>::iterator line);
    void    _assert(std::list<struct sParsedLine>::iterator line);
    void    _pop(std::list<struct sParsedLine>::iterator line);
    void    _dump(std::list<struct sParsedLine>::iterator line);
    void    _add(std::list<struct sParsedLine>::iterator line);
    void    _sub(std::list<struct sParsedLine>::iterator line);
    void    _mul(std::list<struct sParsedLine>::iterator line);
    void    _div(std::list<struct sParsedLine>::iterator line);
    void    _mod(std::list<struct sParsedLine>::iterator line);
    void    _print(std::list<struct sParsedLine>::iterator line);
    void    _exit(std::list<struct sParsedLine>::iterator line);




};

#endif //ABSTRACT_VM_HPP
