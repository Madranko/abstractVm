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

    class NotEnoughElementsException : public std::exception {
    public:
        NotEnoughElementsException(const std::string & command, const unsigned int line);
        NotEnoughElementsException(const NotEnoughElementsException  &copy);
        virtual ~NotEnoughElementsException () throw();
        NotEnoughElementsException  &operator=(const NotEnoughElementsException &rhs);
        const char	*what(void) const throw();
        std::string getError() const;
    private:
        std::string _error;
    };

    class EmptyStackException : public std::exception {
    public:
        EmptyStackException(const std::string & command, const unsigned int line);
        EmptyStackException(const EmptyStackException  &copy);
        virtual ~EmptyStackException () throw();
        EmptyStackException &operator=(const EmptyStackException &rhs);
        const char	*what(void) const throw();
        std::string getError() const;
    private:
        std::string _error;
    };

    class AssertFalseException : public std::exception {
    public:
        AssertFalseException(const unsigned int line);
        AssertFalseException(const AssertFalseException  &copy);
        virtual ~AssertFalseException () throw();
        AssertFalseException &operator=(const AssertFalseException &rhs);
        const char	*what(void) const throw();
        std::string getError() const;
    private:
        std::string _error;
    };

    class DivisionOnZeroException : public std::exception {
    public:
        DivisionOnZeroException(const unsigned int line);
        DivisionOnZeroException(const DivisionOnZeroException  &copy);
        virtual ~DivisionOnZeroException () throw();
        DivisionOnZeroException &operator=(const DivisionOnZeroException &rhs);
        const char	*what(void) const throw();
        std::string getError() const;
    private:
        std::string _error;
    };

    class ModuloOnZeroException : public std::exception {
    public:
        ModuloOnZeroException(const unsigned int line);
        ModuloOnZeroException(const ModuloOnZeroException  &copy);
        virtual ~ModuloOnZeroException () throw();
        ModuloOnZeroException &operator=(const ModuloOnZeroException &rhs);
        const char	*what(void) const throw();
        std::string getError() const;
    private:
        std::string _error;
    };

    class InvalidTypeException : public std::exception {
    public:
        InvalidTypeException(const std::string & instruction, const unsigned int line);
        InvalidTypeException(const InvalidTypeException  &copy);
        virtual ~InvalidTypeException () throw();
        InvalidTypeException &operator=(const InvalidTypeException &rhs);
        const char	*what(void) const throw();
        std::string getError() const;
    private:
        std::string _error;
    };

    class NoExitCommandException : public std::exception {
    public:
        NoExitCommandException();
        NoExitCommandException(const NoExitCommandException  &copy);
        virtual ~NoExitCommandException () throw();
        NoExitCommandException &operator=(const NoExitCommandException &rhs);
        const char	*what(void) const throw();
        std::string getError() const;
    private:
        std::string _error;
    };

    class CinFailedException : public std::exception {
    public:
        CinFailedException();
        CinFailedException(const CinFailedException  &copy);
        virtual ~CinFailedException () throw();
        CinFailedException &operator=(const CinFailedException &rhs);
        const char  *what(void) const throw();
        std::string getError() const;
    private:
        std::string _error;
    };


}

#endif //AVM_EXCEPTION_HPP
