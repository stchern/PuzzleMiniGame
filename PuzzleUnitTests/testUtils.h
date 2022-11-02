#ifndef TESTUTILS_H
#define TESTUTILS_H


#include <QTest>

class TestUtils: public QObject{

    Q_OBJECT
public:

    explicit TestUtils(QObject *parent = 0): QObject(parent){
    };

private:
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

private slots:

    void testAdjacencyMatrix01();
    void testAdjacencyMatrix02();
    void testAdjacencyMatrix03();
    void testfindAllPurePaths();

};


#endif // TESTUTILS_H
