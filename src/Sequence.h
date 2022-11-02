#ifndef SEQUENCE_PUZZLE_H
#define SEQUENCE_PUZZLE_H

#include "Common.h"

class Sequence
{
public:
    Sequence(const std::vector<unsigned char> &codes, int score);

    const std::vector<unsigned char> &codes() const;

    int score() const;

private:
    std::vector<unsigned char> m_codes;
    int m_score;
};

#endif
