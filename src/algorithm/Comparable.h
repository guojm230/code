//
// Created by guojm on 2020/4/22.
//

#ifndef LEETCODE_COMPARABLE_H
#define LEETCODE_COMPARABLE_H

template <class T> class Comparable{
public:
    virtual int compare(T other) = 0;
};

#endif //LEETCODE_COMPARABLE_H
