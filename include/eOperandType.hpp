#ifndef EOPERANDTYPE_HPP
#define EOPERANDTYPE_HPP

#include <string>

enum eOperandType {
	E_INT8,
	E_INT16,
	E_INT32,
	E_FLOAT,
	E_DOUBLE,
};


struct	sParsedLine {
	std::string	        instruction;
	std::string	        type;
	std::string	        stringValue;
	std::string         error;
	bool                empty = false;
	unsigned int        line_num;
};

#endif //EOPERANDTYPE_HPP
