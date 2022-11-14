#include "Sequence.h"

Sequence::Sequence(const std::vector<unsigned char> &codes, int score)
    : m_codes(codes)
    , m_score(score)
{
}

const std::vector<unsigned char> &Sequence::codes() const
{
    return m_codes;
}

int Sequence::score() const
{
    return m_score;
}
