// ---------------------------------------------------------------------------------------------
// PLEASE DO NOT MODIFY, RENAME OR REMOVE ANY OF CLASSES, METHODS AND VARIABLES BELOW.
// YOU CAN ADD YOUR OWN METHODS AND VARIABLES TO THE EXISTING CLASSES AND USE THEM IN YOUR WORK.
// ---------------------------------------------------------------------------------------------

#pragma once

#include "Common.h"

class InvalidArgumentError : public std::runtime_error
{
public:
    using std::runtime_error::runtime_error;

    // You can add your own class members here.
    InvalidArgumentError():runtime_error("Invalid argument error"){}
    InvalidArgumentError(std::string msg):runtime_error(msg.c_str()){}
};
