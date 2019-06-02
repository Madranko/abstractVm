#ifndef AVM_PARSE_EXCEPTION_HPP
#define AVM_PARSE_EXCEPTION_HPP

#include <exception>
#include <string>

namespace AvmParseException {
    class ParseException : public std::exception {
        public:
            ParseException(unsigned int line);
            ParseException(const ParseException &copy);
            virtual ~ParseException() throw();
            ParseException &operator=(const ParseException &rhs);
            const char	*what(void) const throw();
            std::string getError() const;
        private:
            std::string _error;
    };

    class FailedOpenFileException : public std::exception {
    public:
        FailedOpenFileException(const std::string & fileName);
        FailedOpenFileException(const FailedOpenFileException &copy);
        virtual ~FailedOpenFileException() throw();
        FailedOpenFileException &operator=(const FailedOpenFileException &rhs);
        const char	*what(void) const throw();
        std::string getError() const;
    private:
        std::string _error;
    };
}

#endif //AVM_PARSE_EXCEPTION_HPP
