#ifndef UTILS_TEST_H
#define UTILS_TEST_H

#include <iostream>
#include <vector>


namespace UtilsUnitTests {

template <typename T>
bool isEqualsVector(const std::vector<T>& rhs, const std::vector<T>& lhs)
{
    if (rhs.size() != lhs.size())
        return false;

    for (size_t idx = 0; idx < rhs.size(); ++idx)
        if (!(rhs[idx] == lhs[idx]))
            return false;
    return true;

}

template <typename T>
bool isEqualsVectorOfVector(const std::vector<std::vector<T>>& rhs, const std::vector<std::vector<T>>& lhs)
{
    if (rhs.size() != lhs.size())
        return false;

    for (size_t idx = 0; idx < rhs.size(); ++idx)
        if (!isEqualsVector(rhs[idx], lhs[idx]))
            return false;
    return true;
}


}

#endif // UTILS_H
