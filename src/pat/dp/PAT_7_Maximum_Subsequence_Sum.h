//
// Created by guojm on 2020/7/3.
//

#ifndef CODE_PAT_7_MAXIMUM_SUBSEQUENCE_SUM_H
#define CODE_PAT_7_MAXIMUM_SUBSEQUENCE_SUM_H
#include <iostream>

/**
 * 关键词：动态规划
 * 寻找最大子序列,构建dp数组，用来保存以改数字结尾的最大子序列的值，start数组储存序列从哪一个开始。
 * 最后再从其中找到值最大的那一个
 * 默认每个
 */
namespace PAT_7_Maximum_Subsequence_Sum{
    using namespace std;
    int *num,*dp,*start,K = 0,i = -1,j = -1;

    int main(){
        iostream::sync_with_stdio(false);
        cin>>K;
        num = new int[K];
        dp = new int[K];
        start = new int[K];
        for (i = 0; i < K; ++i) {
            cin>>num[i];
            dp[i] = num[i];
            start[i] = num[i];
        }

        for (i = 1;  i< K; i++) {
            if(dp[i]+dp[i-1] > dp[i]){
                dp[i] += dp[i-1];
                start[i] = start[i - 1];
            }
        }
        //寻找最大值
        int maxIndex = 0;
        for (i = 1; i < K; ++i) {
            if(dp[i] > dp[maxIndex]){
                maxIndex = i;
            }
        }
        if(dp[maxIndex] < 0){
            cout<<0<<" "<<num[0]<<" "<<num[K-1]<<endl;
            return 0;
        }

        cout << dp[maxIndex] << " " << start[maxIndex] << " " << num[maxIndex] << endl;
        return 0;
    }

}


#endif //CODE_PAT_7_MAXIMUM_SUBSEQUENCE_SUM_H
