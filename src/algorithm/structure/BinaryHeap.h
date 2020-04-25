//
// Created by guojm on 2020/4/22.
//

#ifndef LEETCODE_BINARYHEAP_H
#define LEETCODE_BINARYHEAP_H

/**
 * 二叉堆
 * 支持大堆或者小堆
 * @tparam T
 */
template<class T> class BinaryHeap {
private:
    const int DEFAULT_SIZE = 20;
    int *array = new int[DEFAULT_SIZE];
    //实际长度
    int _len = 0;
    bool _min;

    /**
     * 从下往上调整
     */
    void swim(){

    }

    /**
     * 从某个节点开始往下调整
     * @param k
     */
    void sink(int k){

    }
public:
    explicit BinaryHeap(bool min = true):_min(min){}


    /**
     * 是否是小堆
     * @return
     */
    bool isMinHeap(){
        return _min;
    }

    int size(){return _len;}

};


#endif //LEETCODE_BINARYHEAP_H
