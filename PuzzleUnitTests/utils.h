#ifndef UTILS_TEST_H
#define UTILS_TEST_H

#include <iostream>
#include <vector>


namespace UtilsUnitTests {

template <typename T>
bool isEqualsVector(const std::vector<T>& lhs, const std::vector<T>& rhs)
{
    if (lhs.size() != rhs.size())
        return false;

    for (size_t idx = 0; idx < lhs.size(); ++idx)
        if (!(lhs[idx] == rhs[idx]))
            return false;
    return true;

}

template <typename T>
bool isEqualsVectorOfVector(const std::vector<std::vector<T>>& lhs, const std::vector<std::vector<T>>& rhs)
{
    if (lhs.size() != rhs.size())
        return false;

    for (size_t idx = 0; idx < lhs.size(); ++idx)
        if (!isEqualsVector(lhs[idx], rhs[idx]))
            return false;
    return true;
}


}

#endif // UTILS_H
