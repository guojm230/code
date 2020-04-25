//
// Created by guojm on 2020/3/16.
//

#include "PalindromeNumber_9.h"
#include<string>
#include<assert.h>

using namespace std;
bool PalindromeNumber_9::isPalindrome(int x) {
    if (x < 0)
        return false;
    string str = to_string(x);
    int low=0, high=str.length()-1;
    while (low<high)
    {
        if (str.at(low) != str.at(high))
            return false;
        low++;
        high--;
    }
    return true;
}

void PalindromeNumber_9::test() {
    assert(isPalindrome(121));
    assert(!isPalindrome(-121));
    assert(!isPalindrome(10));
}
