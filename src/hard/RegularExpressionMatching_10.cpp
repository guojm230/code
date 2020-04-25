
#include "RegularExpressionMatching_10.h"
#include<cassert>

using namespace std;

bool RegularExpressionMatching_10::isMatch(string s,string p) {
    const int slen = s.length(),plen=p.length();
    if (slen == 0 || plen == 0) {
        return plen == slen;
    }
    int state = 1, si = 0, pi = 0;
    char c, d; //c表示当前字符串中的字符,d表示当前pattern中的字符
    char next='-',e = '-'; //表示下一个pattern中的字符,e表示*捕获的字符
    int capture = 0; //表示*匹配的字符数量
    while (state>0&&si<slen&&pi<plen)
    {
        c = s.at(si);
        d = p.at(pi);
        next = pi < plen - 1 ? p.at(pi+1) : '-';
        switch (state) {
            case 1:	//初始化状态
                if (d == '.') {
                    if (next == '*') {
                        state = 4;
                        e = '.';
                        pi++;
                    }
                    else {
                        state = 3;
                    }
                }
                else if (next == '*') {
                    if (e != d)
                        capture = 0;
                    e = d;
                    pi++;
                    state = 4;
                }
                else {
                    state = 2;
                }
                break;
            case 2:  //匹配单个字符
                if (c == d) {
                    ++si;
                    ++pi;
                    state = 1;
                    break;
                }
                if(capture > 0 && (d == e || e == '.'))
                {
                    ++pi;
                    --capture;
                    state = 1;
                    break;
                }
                return false;
            case 3: //遇到.的情况
                ++pi;
                ++si;
                state = 1;
                break;
            case 4: //遇到*的情况
                if (c != e && e != '.') { //不匹配则跳出*的状态
                    ++pi;
                    state = 1;
                    break;
                }
                ++si;
                ++capture;
                break;
        }
    }
    pi = state == 4 ? pi + 1 : pi;
    return pi==plen && si == slen;
}
void RegularExpressionMatching_10::test()
{
    assert(isMatch("aaab","a*ab"));
    /*assert(isMatch("abc","abc"));
    assert(!isMatch("aa","a"));
    assert(isMatch("aab","c*a*b"));
    assert(isMatch("mississippi","mis*is*ip*."));
    assert(isMatch("abdabasf",".*"));
    assert(!isMatch("ab", ".*c"));*/
}

