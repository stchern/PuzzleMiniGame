#ifndef PATH_NOR_FOUND_ERROR_PUZZLE_H
#define PATH_NOR_FOUND_ERROR_PUZZLE_H

#include "Common.h"

class PathNotFoundError : public std::runtime_error
{
public:
    using std::runtime_error::runtime_error;

    PathNotFoundError():runtime_error("Path not found"){}
    PathNotFoundError(std::string msg):runtime_error(msg.c_str()){}
};

#endif
