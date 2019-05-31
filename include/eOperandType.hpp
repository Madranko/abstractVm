#ifndef EOPERANDTYPE_HPP
#define EOPERANDTYPE_HPP

#include <string>

enum eOperandType {
	T_INT8,
	T_INT16,
	T_INT32,
	T_FLOAT,
	T_DOUBLE,
};

struct	sParsedLine {
	std::string	instruction;
	std::string	type;
	std::string	stringValue;
	std::string	error;
	bool        empty;
	int         line_num;
};

#endif //EOPERANDTYPE_HPP
