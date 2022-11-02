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

bool isPossibleAddWastedMovesBetweenSequences(const Path& rhsPath, const Path& lhsPath, const Matrix& matrix, size_t maxLengthPath, std::vector<Path>& outPaths);
bool isPossibleAddWastedMovesBeforeFirstSequences(const Path& path, int maxColumnCount, size_t maxLengthPath, Path& outPath);

bool addOneWastedMoveBeforeFirstSequence(const Path& path, Path& outPath);
bool addTwoWastedMovesBeforeFirstSequence(const Path& path, int maxColumnCount, Path& outPath);

}
}

#endif // SEQUENCEUTILS_H
