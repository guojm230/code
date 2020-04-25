//
// Created by guojm on 2020/4/17.
//

#ifndef LEETCODE_QUICKSORT_H
#define LEETCODE_QUICKSORT_H

#include "../../Common.h"
#include <random>
#include <assert.h>

/**
 * 快速排序
 */
class QuickSort {
private:
    static int partition(int *array, int low, int high){
        /**
         * 选取第一个元素作为枢纽元素
         */
        int part = array[low],l = low,h = high;
        /**
         * 从左往右查找一个比part大的元素
         * 从又往左查找一个比high小的元素
         * 然后两者换位
         * 最后将part和array[low]换位
         */
        while (l < h){
            while (array[l]<=part && l< high) l++;
            while (array[h] >= part && h > low) h--;
            if (l >= h) break;
            swap(array[l],array[h]);
        }
        swap(array[low],array[h]);
        return h;
    }

    static void internalSort(int *array,int low,int high){
        if (high <= low) return;
        int p = partition(array, low, high);
        internalSort(array,low,p-1);
        internalSort(array,p+1,high);
    }
public:
    static void sort(int *array,int length){
        internalSort(array,0,length - 1);
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

class QuickSort3Way{

};


#endif //LEETCODE_QUICKSORT_H
