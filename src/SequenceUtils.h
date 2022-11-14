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
bool isPossibleAddWastedMovesBeforeFirstSequences(const Path& path, const int maxColumnCount, const size_t maxLengthPath, std::vector<Path>& outPaths);

bool addOneWastedMoveBeforeFirstSequence(const Path& path, std::vector<Path>& outPaths);
bool addTwoWastedMovesBeforeFirstSequence(const Path& path, const int maxColumnCount, std::vector<Path>& outPaths);

}
}

#endif // SEQUENCEUTILS_H
