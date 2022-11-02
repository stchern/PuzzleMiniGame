#ifndef UTILS_H
#define UTILS_H

#include "Path.h"
#include "Matrix.h"
#include "Sequence.h"

namespace Utils
{

std::vector<std::vector<std::pair<Path, int>>> combinePurePaths(const std::vector<std::vector<Path>>& purePaths, const Matrix& matrix, const std::vector<Sequence>& sequences, size_t maxLengthPath);
Path findBestPath(const std::vector<std::vector<std::pair<Path, int>>>& allPaths);
std::vector<std::vector<Position>> adjacencyMatrix(const Matrix& matrix, const std::vector<Sequence>& sequences);
std::vector<std::vector<Path>> findAllPurePaths(
        const Matrix& matrix,
        const std::vector<Sequence>& sequences,
        const std::vector<std::vector<Position>>& adjacencyMatrix,
        size_t maxLengthPath);

}


#endif
