//
// Created by guojm on 2020/6/21.
//

#ifndef LEETCODE_LINKEDLIST_H
#define LEETCODE_LINKEDLIST_H
#include <stdexcept>

template<typename E> struct LinkedNode{
    E *data = nullptr;
    struct LinkedNode<E> *next = nullptr;
    struct LinkedNode<E> *prev = nullptr;

    ~LinkedNode(){
        delete data;
    }
};

template<typename E> class LinkedList {
private:
    LinkedNode<E> *_first = nullptr;
    LinkedNode<E> *_tail = nullptr;
    int _size = 0;

    void assert_not_empty(){
        if (isEmpty()) throw std::out_of_range("列表为空");
    }
public:
    LinkedNode<E>* first(){
        assert_not_empty();
        return _first;
    }

    LinkedNode<E>* tail(){
        assert_not_empty();
        return _tail;
    }

    LinkedList<E>& push(E &data){
        push(&data);
        return *this;
    }

    LinkedList<E>& push(E *data){
        auto* node = new LinkedNode<E>();
        node->data = data;
        if(isEmpty()){
            node->prev = (node->next = nullptr);
            _first = (_tail = node);
        } else {
            node->next = _first;
            _first->perv = node;
            _first = node;
        }
        _size++;
        return *this;
    }

    LinkedList<E>& append(E &data){
        append(&data);
        return *this;
    }

    LinkedList<E>& append(E *data){
        auto* node = new LinkedNode<E>();
        node->data = data;
        if(isEmpty()){
            node->prev = (node->next = nullptr);
            _first = (_tail = node);
        } else {
            node->prev = _tail;
            _tail->next = node;
            _tail = node;
        }
        _size++;
        return *this;
    }

    LinkedNode<E>& pop(){
        assert_not_empty();
        LinkedNode<E>* temp = _first;
        _size--;
        if(isEmpty()){
            _first = (_tail = nullptr);
        } else {
            _first = _first->next;
        }
        return *temp;
    }

    LinkedNode<E>& peek(){
        assert_not_empty();
        return *_first;
    }

    bool isEmpty(){
        return _size == 0;
    }

    int size(){
        return _size;
    }

    ~LinkedList(){
        if(isEmpty()) return;
        LinkedNode<E> *temp = nullptr;
        while ((temp = _first) != nullptr){
            _first = _first->next;
            delete temp;
        }
    }
};


#endif //LEETCODE_LINKEDLIST_H
