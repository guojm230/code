//
// Created by guojm on 2020/7/7.
//

#ifndef CODE_PAT_8_ELEVATOR_H
#define CODE_PAT_8_ELEVATOR_H
#include <iostream>

//水题，累加即可
namespace PAT_8_Elevator{
    using namespace std;
    constexpr int UP = 6,DOWN = 4,STOP = 5;

    int main(){
        std::iostream::sync_with_stdio(false);
        int M,totalTime = 0,i = 0,last = 0,temp = 0;
        cin>>M;
        cin>>temp;
        last = temp;
        totalTime += temp*UP+STOP;
        for (i = 1; i < M; ++i) {
            cin>>temp;
            temp -= last;
            last += temp;
            totalTime += (temp < 0 ? -temp * DOWN : temp * UP) + STOP;
        }
        cout<<totalTime<<endl;
        return 0;
    }
}


#endif //CODE_PAT_8_ELEVATOR_H
