class Solution {
public:
    int numPermsDISequence(string S) {
        vector<vector<int>> dp(S.length()+1, vector<int>(S.length()+1, 0));
        dp[0][0] = 1;
        int i, j, k, res=0, mod=1000000007;
        for(i=1; i<S.length()+1; i++){
            for(j=0; j<i+1; j++){
                if(S[i-1] == 'D'){
                    for(k=j; k<i; k++) dp[i][j] = (dp[i][j] + dp[i-1][k])%mod;
                }
                else{
                    for(k=0; k<j; k++) dp[i][j] = (dp[i][j] + dp[i-1][k])%mod;
                }
            }
        }
        for(j=0; j<S.length()+1; j++) res = (res + dp[S.length()][j]) % mod;
        return res;
    }
};
