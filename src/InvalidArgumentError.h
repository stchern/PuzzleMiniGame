#ifndef INVALID_ARGUMENT_ERROR_PUZZLE_H
#define INVALID_ARGUMENT_ERROR_PUZZLE_H


#include "Common.h"

class InvalidArgumentError : public std::runtime_error
{
public:
    using std::runtime_error::runtime_error;

    InvalidArgumentError():runtime_error("Invalid argument error"){}
    InvalidArgumentError(std::string msg):runtime_error(msg.c_str()){}
};

#endif
