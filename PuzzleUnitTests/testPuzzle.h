#ifndef PUZZLE_TEST_H
#define PUZZLE_TEST_H

#include <QTest>

class TestPuzzle: public QObject{

    Q_OBJECT
public:

    explicit TestPuzzle(QObject *parent = 0): QObject(parent){
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

    void testIsFoundInRow01();
    void testIsFoundInRow02();
    void testIsFoundInRow03();
    void testIsFoundInRow04();
    void testAdjacencyMatrix01();
    void testAdjacencyMatrix02();
    void testAdjacencyMatrix03();
    void testfindAllPurePaths();
    void testDFSForMatrix01();
    void testDFSForMatrix02();
    void testDFSForMatrix03();
    void testDFSForMatrix04();
    void testDFSForMatrix05();
    void testDFSForMatrix06();
    void testDFSForMatrix07();
    void testDFSForMatrix08();
    void testDFSForMatrix09();

    void testBFSForMatrix01();
    void testBFSForMatrix02();
    void testBFSForMatrix03();
    void testBFSForMatrix04();
    void testBFSForMatrix05();
    void testBFSForMatrix06();
    void testBFSForMatrix07();



};

#endif //INPAINTING_TEST_H
