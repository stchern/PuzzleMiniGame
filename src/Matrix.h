#ifndef MATRIX_PUZZLE_H
#define MATRIX_PUZZLE_H

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

    bool operator==(const Matrix &other) const;
//    Sequence sequenceByPath(const Path& path) const;

    std::vector<std::vector<unsigned char>> values() const;
    void setValue(const Position &position, unsigned char value);


private:
    std::vector<std::vector<unsigned char>> m_values;
};


#endif
