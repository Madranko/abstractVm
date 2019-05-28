#ifndef EOPERANDTYPE_HPP
#define EOPERANDTYPE_HPP

#include <string>

enum eOperandType {
	INT8,
	INT16,
	INT32,
	FLOAT,
	DOUBLE
};

struct	parsedLine {
	std::string	instruction;
	std::string	type;
	std::string	stringValue;
	std::string	error;
};

#endif //EOPERANDTYPE_HPP
