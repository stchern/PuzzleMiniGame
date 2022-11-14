#include "MatrixUtils.h"
#include <QtGlobal>

bool InternalUtils::UMatrix::isFoundInRow(const Matrix& matrix,  const Position& startPosition, unsigned char value, std::vector<Position>& outVector)
{
    size_t startRow = startPosition.row();
    size_t startCol = startPosition.column();
    std::vector<Position> resultVector;

    for(std::size_t col = 0; col < matrix.values()[startRow].size(); ++col)
        if (col != startCol)
            if (matrix.values()[startRow][col] == value)
                resultVector.push_back(Position(startRow, col));

    for (const Position& position: resultVector)
        outVector.push_back(position);
    return !resultVector.empty();
}

bool InternalUtils::UMatrix::isFoundInCol(const Matrix& matrix,  const Position& startPosition, unsigned char value, std::vector<Position>& outVector)
{
    size_t startRow = startPosition.row();
    size_t startCol = startPosition.column();
    std::vector<Position> resultVector;

    for (size_t row = 0; row < matrix.rowCount(); ++row)
        if (row != startRow)
            if (matrix.values()[row][startCol] == value)
                resultVector.push_back(Position(row, startCol));
    for (const Position& position: resultVector)
        outVector.push_back(position);

    return !resultVector.empty();
}

Matrix InternalUtils::UMatrix::createIsVisitedMatrix(int row, int col, const Position& startPosition)
{
    Matrix isVisitedMatrix(std::vector<std::vector<unsigned char>>(row, std::vector<unsigned char>(col, 0)));
    isVisitedMatrix.setValue(startPosition, 1);

    return isVisitedMatrix;
}

void InternalUtils::UMatrix::setVisitedPositions(Matrix& isVisitedMatrix, const Path& visitedPath)
{
    if (!visitedPath.positions().empty())
        for (size_t posIdx = 0; posIdx < visitedPath.positions().size() - 1; ++posIdx) {
            Q_ASSERT(visitedPath.positions()[posIdx].row() < isVisitedMatrix.rowCount());
            Q_ASSERT(visitedPath.positions()[posIdx].column() < isVisitedMatrix.columnCount());
            isVisitedMatrix.setValue(visitedPath.positions()[posIdx], 1);
        }
}
