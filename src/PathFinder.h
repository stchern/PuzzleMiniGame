#ifndef PATH_FINDER_PUZZLE_H
#define PATH_FINDER_PUZZLE_H

#include "Common.h"
#include "Matrix.h"
#include "Path.h"
#include "Sequence.h"

class PathFinder
{
public:
    PathFinder(const Matrix &matrix, const std::vector<Sequence> &sequences, int maxPathLength);
    Path run();

private:
    Matrix m_matrix;
    std::vector<Sequence> m_sequences;
    int m_maxPathLength;
};

#endif
