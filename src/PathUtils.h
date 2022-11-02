#ifndef PATHUTILS_H
#define PATHUTILS_H

#include "Sequence.h"
#include "Matrix.h"
#include "Path.h"


namespace InternalUtils {

namespace UPath
{

std::vector<std::pair<Path, int>> combinePurePath(
        const std::vector<std::vector<Path>>& purePaths,
        const Path& currPath,
        const Sequence& currSequence,
        std::vector<bool>& isVisitedSequence,
        const std::vector<Sequence>& sequences,
        const Matrix& matrix, size_t maxLengthPath, int score);

Path concatenatePaths(const Path& rhsPath, const Path& lhsPath);
bool isCreatedPathsAfterCurrent(
        const Path& currPath,
        const Path& nextPath,
        const Sequence& currSequence,
        const Sequence& nextSequence,
        const Matrix& matrix,
        size_t maxLengthPath,
        std::vector<Path>& outPaths);

bool hasOverlapping(const Sequence& rhsPath, const Sequence& lhsPath, size_t& overlapLength);
bool hasIntersection(const Path& rhsPath, const Path& lhsPath);


}
}

#endif // PATHUTILS_H
