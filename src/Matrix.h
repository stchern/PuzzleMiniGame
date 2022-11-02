// ---------------------------------------------------------------------------------------------
// PLEASE DO NOT MODIFY, RENAME OR REMOVE ANY OF CLASSES, METHODS AND VARIABLES BELOW.
// YOU CAN ADD YOUR OWN METHODS AND VARIABLES TO THE EXISTING CLASSES AND USE THEM IN YOUR WORK.
// ---------------------------------------------------------------------------------------------

#pragma once

#include "Common.h"
#include "Position.h"
#include "Sequence.h"
#include "Path.h"

class Matrix
{
public:
    Matrix(const std::vector<std::vector<unsigned char>> &values);

    int rowCount() const;
    int columnCount() const;

    unsigned char value(int row, int column) const;
    unsigned char value(const Position &position) const;

    // You can add your own class members here.
    std::vector<std::vector<unsigned char>> values() const;
    void setValue(const Position &position, unsigned char value);
    Sequence sequenceByPath(const Path& path) const;

private:
    std::vector<std::vector<unsigned char>> m_values;
};
