#ifndef AVM_EXCEPTION_HPP
#define AVM_EXCEPTION_HPP

#include <exception>
#include <string>

namespace AvmException {

    class OverflowException : public std::exception {
    public:
        OverflowException(const std::string & type);
        OverflowException(const OverflowException &copy);
        virtual ~OverflowException() throw();
        OverflowException &operator=(const OverflowException &rhs);
        const char	*what(void) const throw();
        std::string getError() const;
    private:
        std::string _error;
    };

    class UnderflowException : public std::exception {
    public:
        UnderflowException(const std::string & type);
        UnderflowException(const UnderflowException  &copy);
        virtual ~UnderflowException () throw();
        UnderflowException  &operator=(const UnderflowException &rhs);
        const char	*what(void) const throw();
        std::string getError() const;
    private:
        std::string _error;
    };


}

#endif //AVM_EXCEPTION_HPP
