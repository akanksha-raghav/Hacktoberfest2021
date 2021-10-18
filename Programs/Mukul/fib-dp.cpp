//Ques Link: https://leetcode.com/problems/fibonacci-number
//Approach: DP

class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;
        int dp[n+1];
        memset(dp,0,sizeof(int));
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        
        for(int i=3;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n];
    } 
};
