#ifndef MATRIXUTILS_H
#define MATRIXUTILS_H

#include "Position.h"
#include "Matrix.h"
#include "Path.h"

namespace InternalUtils {

namespace UMatrix
{

bool isValid(const Position& currPosition, const Matrix& isVisitedMatrix, const Matrix& matrix, unsigned char seqValue);
bool isFoundInRow(const Matrix& matrix,  const Position& startPosition, unsigned char value, std::vector<Position>& outVector);
bool isFoundInCol(const Matrix& matrix,  const Position& startPosition, unsigned char value, std::vector<Position>& outVector);
void setVisitedPositions(Matrix& isVisitedMatrix, const Path& visitedPath = Path(std::vector<Position>{}));
Matrix createIsVisitedMatrix(int row, int col, const Position& startPosition);

}
}

#endif // MATRIXUTILS_H
