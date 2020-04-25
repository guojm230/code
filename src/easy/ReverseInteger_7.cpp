//
// Created by guojm on 2020/3/16.
//

#include "ReverseInteger_7.h"
#include <cassert>
#include <string>
int ReverseInteger_7::reverse(int x) {
    long long result = 0, k = 1, temp = 1, i = 1;
    long long n =  x < 0 ? 0 - x : x;
    int sign = x < 0 ? -1 : 1;
    while (n /  (temp *=10 ) != 0) {
        i++;
    }
    //x一共有i位数
    for (; i > 0; i--,k *=10) {
        temp /= 10;
        result += (n / temp) * k;
        n %= temp;
    }
    result = (result > INT32_MAX || result < INT32_MIN )? 0 : result;
    return sign > 0 ? result : 0-result;
}

void ReverseInteger_7::test() {
    using namespace std;
    assert(this->reverse(123) == 321);
    assert(this->reverse(-30) == -3);
    assert(this->reverse(120) == 21);
    assert(this->reverse(1534236469) == 0);
    assert(this->reverse(-2147483648));
}
