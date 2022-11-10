#ifndef SEQUENCEUTILS_H
#define SEQUENCEUTILS_H

#include <stack>
#include <queue>
#include "Position.h"
#include "Sequence.h"
#include "Matrix.h"
#include "Path.h"


namespace InternalUtils {

namespace USequence {

bool isPossibleAddWastedMovesBetweenSequences(const Path& rhsPath, const Path& lhsPath, const Matrix& matrix, const size_t maxLengthPath, std::vector<Path>& outPaths);
bool isPossibleAddWastedMovesBeforeFirstSequences(const Path& path, const int maxColumnCount, const size_t maxLengthPath, Path& outPath);

bool addOneWastedMoveBeforeFirstSequence(const Path& path, Path& outPath);
bool addTwoWastedMovesBeforeFirstSequence(const Path& path, const int maxColumnCount, Path& outPath);
//bool hasOverlapping(const Sequence& rhsSeq, const Sequence& lhsSeq, size_t& overlapLength);

}
}

#endif // SEQUENCEUTILS_H
