#ifndef SEARCH_H
#define SEARCH_H

#include "Position.h"
#include "Sequence.h"
#include "Matrix.h"

namespace Search {

std::vector<Path> BFS(
        const Matrix& matrix,
        const Position& endPosition,
        const Position& startPosition,
        bool isNextSeqStartByCol,
        bool isStartFromCol);

std::vector<Path> DFS(const Matrix& matrix, const Sequence& sequences, const Position& startPosition, std::size_t maxLengthPath);



}

#endif // SEARCH_H
