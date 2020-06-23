//
// Created by guojm on 2020/3/16.
//

#ifndef LEETCODE_REGULAREXPRESSIONMATCHING_10_H
#define LEETCODE_REGULAREXPRESSIONMATCHING_10_H


#include <string>
#include <stack>
#include <iostream>

class RegularExpressionMatching_10
{
public:
    static bool isMatch(std::string s,std::string p){
        using namespace std;
        int sl = s.length();
        int pl = p.length();
        typedef struct {
            int pp;  //状态
            int sp; //文本位置
        } state;
        stack<state> states = stack<state>();
        states.push(state{0,0});
        //开始匹配
        while (!states.empty()){
            state sc = states.top();
            states.pop();
            if(sc.sp >=  sl && sc.pp >= pl){
                return true;
            }
            if(sc.sp >= sl){
                //若p没到结尾，判断一下是否结尾是a*b*形式的字符
                if(sc.pp < pl - 1 && p[sc.pp + 1] == '*'){
                    states.push(state{sc.pp+2,sc.sp});
                }
                continue;
            }
            //若下一个字符为*,进行特殊处理
            if(sc.pp < (pl - 1) && p[sc.pp + 1] == '*'){
                //不匹配，进入下一个状态
                if(!matchSingle(s[sc.sp],p[sc.pp])){
                    states.push(state{sc.pp+2,sc.sp});
                }else{
                    //如果能匹配，则有两个分支
                    states.push(state{sc.pp+2,sc.sp});
                    states.push(state{sc.pp,sc.sp+1});
                }
                continue;
            }
            //匹配单个字符
            if(matchSingle(s[sc.sp],p[sc.pp])){
                states.push(state{sc.pp+1,sc.sp+1});
                continue;
            }
        }
        return false;
    }

    inline static bool matchSingle(char s,char p){
        return s == p || p == '.';
    }

    static void test(){
        using namespace std;
        string str = "a";
        string p = "ab*";
        cout<<isMatch(str,p)<<endl;
    }
};


#endif //LEETCODE_REGULAREXPRESSIONMATCHING_10_H
