class Solution {
public:
    int countSubstrings(string s) {
        int sz = s.size();
        vector<vector<int>> dp(sz, vector<int>(sz, 0));
        vector<vector<int>> mark(sz, vector<int>(sz, 0));

        int cnt = sz;

        for(int i = 0; i < sz; i++)
        {
            for(int j = i + 1; j < sz; j++)
            {
                bool k = DynamicProgramming(dp, mark, s, i, j);

                if(k)
                    cnt++;
            }
        }
        return cnt;
    }

    bool DynamicProgramming(vector<vector<int>> &dp, vector<vector<int>> &mark, string &s, int le, int  ri)
    {
        if(le >= ri)
        {          
            return true;
        }
        
        if(mark[le][ri])
            return dp[le][ri];
        
        mark[le][ri] = true;
        dp[le][ri] = false;

        if(s[le] == s[ri])
        {
            bool k = DynamicProgramming(dp, mark, s, le + 1, ri - 1);
            dp[le][ri] |= k;
        }
        return dp[le][ri];
    }
};