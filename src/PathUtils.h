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
        const std::vector<Sequence>& sequences,
        const Matrix& matrix, size_t maxLengthPath, int score,
        std::vector<bool>& isVisitedSequence);

Path concatenatePaths(const Path& rhsPath, const Path& lhsPath);
bool isCreatedPathsAfterCurrent(
        const Path& currPath,
        const Path& nextPath,
        const Matrix& matrix,
        const size_t maxLengthPath,
        std::vector<Path>& outPaths);

bool hasIntersection(const Path& rhsPath, const Path& lhsPath);


}
}

#endif // PATHUTILS_H
