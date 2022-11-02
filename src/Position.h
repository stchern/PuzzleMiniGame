#ifndef POSITION_PUZZLE_H
#define POSITION_PUZZLE_H

#include "Common.h"

class Position
{
public:
    Position(int row, int column);

    int row() const;
    int column() const;

    bool operator==(const Position &other) const;

    friend std::ostream &operator<<(std::ostream &stream, const Position &position);

    bool operator<(const Position &other) const;
    Position(): m_row(0), m_column(0) {};

private:
    int m_row;
    int m_column;
};

#endif
