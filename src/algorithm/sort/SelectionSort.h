//
// Created by guojm on 2020/4/21.
//

#ifndef LEETCODE_SELECTIONSORT_H
#define LEETCODE_SELECTIONSORT_H

#include <random>
#include <cassert>
#include "../../Common.h"

class SelectionSort {
private:

    /**
     * 将数组构建为二叉堆
     * @param array
     * @param len
     * @param min
     */
    void buildHeap(int *heap, int len, bool min = true) {
        for (int i = len/2; i >= 1 ; --i) {
            sink(heap,i,len,min);
        }
//        for (int k = 0;k<len;k++){
//            std::cout<<heap[k+1]<<"\t";
//        }
    }

    int pop(int *heap,int len,bool min = true){
        int val = heap[1];
        heap[1] = heap[len];
        sink(heap,1,len-1,min);
        return val;
    }

    //由最下往上调整
    void swim(int *heap, int len, bool min = true) {
        while (len > 1) {
            if ((heap[len] < heap[len / 2] && min) || (heap[len] > heap[len / 2] && !min))
                swap(heap, len, len / 2);
            len /= 2;
        }
    }

    //由上往下调整
    void sink(int *heap, int k,int len,bool min = true) {
        while (2*k <= len){
            if (min){ //小堆
                //需要调整
                if (heap[k] > heap[k*2] || heap[k] > heap[2*k+1]){
                    if (heap[k*2] < heap[k*2+1]){
                        swap(heap,k,k*2);
                        k *= 2;
                    } else {
                        swap(heap,k,k*2+1);
                        k = k*2 + 1;
                    }
                } else break;
            } else {    //大堆
                if (heap[k] < heap[k*2] || heap[k] < heap[2*k+1]){
                    if (heap[k*2] > heap[k*2+1]){
                        swap(heap,k,k*2);
                        k *= 2;
                    } else {
                        swap(heap,k,k*2+1);
                        k = k*2 + 1;
                    }
                } else break;
            }
        }
    }

public:
    /**
     *
     * @param array 数组首元素指针
     * @param len 数组长度
     * @param min 小堆
     */
    void sort(int *array, int len, bool min = true) {
        int heap[len + 1],l = len;
        //复制数组
        for (int i = 1; i < len + 1; i++) {
            heap[i] = array[i - 1];
        }
        buildHeap(heap, len, min);
        for (int j = 0; j < len; ++j,--l) {
            array[j] = pop(heap,l,min);
        }
    }

    void test(){
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


#endif //LEETCODE_SELECTIONSORT_H
