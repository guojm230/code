//
// Created by guojm on 2020/3/16.
//
#include "StringToInteger_8.h"
#include<iostream>

using namespace std;
int StringToInteger_8::myAtoi(string str) {
    string number = "";
    char temp;
    int len = str.length(),sign = 1,i=0;
    bool start = false;
    for (; i < len; i++) {
        temp = str[i];
        if (temp < 48 || temp  > 57) {
            if (start)
                break;
            if (temp == 32)
                continue;
            if (temp == 45) {
                sign = -1;
                start = true;
                continue;
            }
            if (temp == 43) {
                start = true;
                continue;
            }
            return 0;
        }
        else {
            start = true;
            number+=temp;
        }
    }
    len = number.length();
    i = 0;
    while (i<len&&number[i] == '0')
        i++;
    if (i > 0) {
        number = number.substr(i);
    }
    len = number.length();
    if (len > 10 && sign == 1)
        return INT32_MAX;
    if (len > 10 && sign == -1)
        return INT32_MIN;
    //转换为数字
    long long result = 0;
    long long t = 1;
    for (; len > 0; len--) {
        result += ((long long)(number[len - 1] - 48)) * t;
        t *= 10;
    }
    if (sign > 0) {
        result = result > INT32_MAX ? INT32_MAX : result;
    }
    else {
        result = 0 - result;
        result = result < INT32_MIN ? INT32_MIN : result;
    }
    return result;
}

string StringToInteger_8::extract(string str) {
    string number = "";
    char temp;
    int len = str.length(), sign = 1;
    bool start = false;
    for (int i = 0; i < len; i++) {
        temp = str[i];
        if (temp < 48 || temp  > 57) {
            if (start)
                break;
            if (temp == 32)
                continue;
            if (temp == 45) {
                sign = -1;
                start = true;
                continue;
            }

            if (temp == 43) {
                start = true;
            }
        }
        else {
            number += temp;
        }
    }
    return number;
}

void StringToInteger_8::extractTest() {
    cout << extract("  -123ab")<<endl;
    cout << extract("  -asd123ab")<<endl;
}

void StringToInteger_8::myAtoiTest() {
    /*cout << myAtoi("  -123ab") << endl;
    cout << myAtoi("  -asd123ab") << endl;*/
    cout << myAtoi(" 0000000000012345678") << endl;
    //cout << myAtoi("-91283472332") << endl;
}

void StringToInteger_8::test() {

}
