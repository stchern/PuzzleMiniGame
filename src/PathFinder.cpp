// ---------------------------------------------------------------------------------------------
// PLEASE DO NOT MODIFY, RENAME OR REMOVE ANY OF CLASSES, METHODS AND VARIABLES BELOW
// EXCEPT PATHFINDER::RUN() METHOD THAT YOU NEED TO IMPLEMENT.
// YOU CAN ADD YOUR OWN METHODS AND VARIABLES TO THE EXISTING CLASSES AND USE THEM IN YOUR WORK.
// ---------------------------------------------------------------------------------------------

#include "PathFinder.h"
#include "Utils.h"
#include "InvalidArgumentError.h"
#include "PathNotFoundError.h"

PathFinder::PathFinder(const Matrix &matrix, const std::vector<Sequence> &sequences, int maxPathLength)
    : m_matrix(matrix)
    , m_sequences(sequences)
    , m_maxPathLength(maxPathLength)
{
}

Path PathFinder::run()
{
    // TODO: Implement me.

    if (m_matrix.values().empty() || m_sequences.empty() || m_maxPathLength <= 0)
        throw InvalidArgumentError("Invalid argument error");

    for (const Sequence& sequence: m_sequences) {
        if (sequence.codes().empty())
            throw InvalidArgumentError("Invalid argument error");
        if (sequence.score() <= 0 )
            throw InvalidArgumentError("Invalid argument error");
    }

    std::vector<std::vector<Position>> adjacencyMatrix = Utils::adjacencyMatrix(m_matrix, m_sequences);
    std::vector<std::vector<Path>> purePaths = Utils::findAllPurePaths(m_matrix, m_sequences, adjacencyMatrix, m_maxPathLength);
    std::vector<std::vector<std::pair<Path, int>>> allPathsAndScores = Utils::combinePurePaths(purePaths, m_matrix, m_sequences, m_maxPathLength);
    Path bestPath = Utils::findBestPath(allPathsAndScores);

    if (bestPath.positions().empty())
        throw PathNotFoundError("Path not found");

    return Path();
}
