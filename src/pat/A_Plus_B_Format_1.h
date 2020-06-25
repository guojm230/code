//
// Created by guojm on 2020/6/24.
//

#ifndef LEETCODE_A_PLUS_B_FORMAT_1_H
#define LEETCODE_A_PLUS_B_FORMAT_1_H
#include <iostream>
#include <stack>
class A_Plus_B_Format_1{
public:
    static int main(){
        using namespace std;
        istream::sync_with_stdio(false);
        int a,b,temp;
        cin>>a>>b;
        a += b;
        if(a == 0){
            cout<<0<<endl;
            return 0;
        }
        if(a<0){
            cout<<'-';
        }
        stack<int> sta;
        for(b = 1; a != 0; b++,a/=10){
            temp = a % 10;
            sta.push(temp < 0 ? -temp : temp);
            if(b % 3 == 0 && (a >= 10 || a<= -10)){
                sta.push(',');
            }
        }
        while(!sta.empty()){
            b = sta.top();
            sta.pop();
            if (b == 44){
                cout<< ',';
            } else {
                cout<<b;
            }
        }
        cout.flush();
        return 0;
    }
};


#endif //LEETCODE_A_PLUS_B_FORMAT_1_H
