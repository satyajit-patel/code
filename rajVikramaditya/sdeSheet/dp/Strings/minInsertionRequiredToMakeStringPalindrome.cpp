//https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/submissions/
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string text1 = s;
        reverse(s.begin(), s.end());
        string text2 = s;
        
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        //baseCase
        for(int j=0; j<=m; j++) dp[0][j] = 0;
        for(int i=0; i<=n; i++) dp[i][0] = 0;
        
        //recursiveCase
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(text1[i-1] == text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
    
    int minInsertions(string s) {
        return s.size() - longestPalindromeSubseq(s);
    }
};