//
// Created by guojm on 2020/4/17.
//
#include <cassert>
#include <random>

void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}

void swap(int *a,int *b){
    swap(*a,*b);
}

void swap(int* array,int lo,int hi){
    swap(array[lo],array[hi]);
}

void sortTest(const void (*sort)(int*,int)){
    using namespace std;
    uniform_int_distribution u(-100,100);
    for (int i = 1; i < 100; ++i) {
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