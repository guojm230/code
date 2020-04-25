//
// Created by guojm on 2020/4/17.
//

#ifndef LEETCODE_SHELLSORT_H
#define LEETCODE_SHELLSORT_H

#include <random>
#include "../../Common.h"
#include <random>
#include <assert.h>
#include <iostream>
/**
 * 希尔排序
 */
class ShellSort {
public:
    static void sort(int* array,int len){
        int x = len; //递减序列
        while((x = x/2)>0){
            for (int j = 0; j < x; ++j) {
                //对同一增量序列里的数组进行插入排序
                for (int i = j+x; i <= (len-x); i+=x) {
                    for (int k = i; k > j; k-=x) {
                        if(array[k] < array[k-x]){
                            swap(array,k,k-x);
                        }
                    }
                }
            }
        }
    }

    static void test(){
        using namespace std;
        uniform_int_distribution u(0,100);
        for (int i = 1; i < 50; ++i) {
            default_random_engine e(i);
            int length = i;
            int array[length];
            for (int j = 0; j < length; ++j) {
                array[j] = u(e);
            }
            sort(array,length);
            for (int k = 0; k < length-1; ++k) {
                assert(array[k] <= array[k+1]);
            }
        }
    }
};


#endif //LEETCODE_SHELLSORT_H
