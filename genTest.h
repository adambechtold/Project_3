//
// Created by Adam Bechtold on 3/22/17.
//

#ifndef PROJECT_3_GENTEST_H
#define PROJECT_3_GENTEST_H

template <typename T>
class genTest {
private:
    T t1;
    T t2;
public:
    genTest(T t1, T t2);
    T getT1();
    T getT2();
};


#endif //PROJECT_3_GENTEST_H
