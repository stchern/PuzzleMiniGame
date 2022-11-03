#ifndef PATH_PUZZLE_H
#define PATH_PUZZLE_H

#include "Common.h"
#include "Position.h"

class Path
{
public:
    Path();
    Path(const std::vector<Position> &positions);

    const std::vector<Position> &positions() const;
    size_t length() const;
    bool operator==(const Path &other) const;

    friend std::ostream &operator<<(std::ostream &stream, const Path &path);

    void push_back(const Position& position);

private:
    std::vector<Position> m_positions;
};

#endif
