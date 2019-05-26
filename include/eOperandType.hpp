#ifndef EOPERANDTYPE_HPP
#define EOPERANDTYPE_HPP

#include <string>

enum eOperandType {
	_int8 = 1,
	_int16 = 2,
	_int32 = 3,
	_float = 4,
	_double = 5
};

struct	parsedLine {
	std::string	instruction;
	std::string	type;
	std::string	value;
	std::string	error;
};

#endif //EOPERANDTYPE_HPP
