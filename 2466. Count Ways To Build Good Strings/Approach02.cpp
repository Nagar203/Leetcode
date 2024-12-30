class Solution {
public:
    int MOD = 1000000007;
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1, 0);
        dp[0] = 1;

        for(int length = 1; length <= high; ++length){
            if(length>=zero){
                dp[length] = (dp[length] + dp[length-zero])%MOD;
            }
            if(length>=one){
                dp[length] = (dp[length] + dp[length-one])%MOD;
            }
        }
        int result = 0;
        for(int length=low; length<=high; ++length){
            result = (result + dp[length])%MOD;
        }
        return result;
    }
};