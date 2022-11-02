#include <QtGlobal>
#include "Matrix.h"

Matrix::Matrix(const std::vector<std::vector<unsigned char>> &values)
    : m_values(values)
{
}

int Matrix::rowCount() const
{
    return static_cast<int>(m_values.size());
}

int Matrix::columnCount() const
{
    return !m_values.empty() ? static_cast<int>(m_values[0].size()) : 0;
}

unsigned char Matrix::value(int row, int column) const
{
    return m_values[row][column];
}

unsigned char Matrix::value(const Position &position) const
{
    Q_ASSERT(position.row() < rowCount());
    Q_ASSERT(position.column() < columnCount());

    return m_values[position.row()][position.column()];
}

std::vector<std::vector<unsigned char>> Matrix::values() const
{
    return this->m_values;
}

void Matrix::setValue(const Position &position, unsigned char value)
{
    Q_ASSERT(position.row() < rowCount());
    Q_ASSERT(position.column() < columnCount());

    this->m_values[position.row()][position.column()] = value;
}

Sequence Matrix::sequenceByPath(const Path& path) const
{
    std::vector<unsigned char> codes;
    for (const Position& position: path.positions()) {
        Q_ASSERT(position.row() < rowCount());
        Q_ASSERT(position.column() < columnCount());
        codes.push_back(this->m_values[position.row()][position.column()]);
    }
    return Sequence(codes, 0);
}

bool Matrix::operator==(const Matrix &other) const
{
    if (this->values().size() != other.values().size())
        return false;

    for (size_t row = 0; row < this->values().size(); ++row) {
        if (this->values()[row].size() != other.values()[row].size())
            return false;
        for (size_t col = 0; col < this->values().size(); ++col) {
            if (this->values()[row][col] != other.values()[row][col])
                return false;
        }
    }

    return true;
}
