class Solution {
public:
    string longestPalindrome(string s) {
        int sz = s.size();
        vector<vector<int>> dp(sz, vector<int>(sz, 0));
        vector<vector<int>> mark(sz, vector<int>(sz, 0));

        int le = -1;
        int ri = -1;
        int mx = 0;

        for(int i = 0; i < sz; i++)
        {
            for(int j = i; j < sz; j++)
            {
                bool k = DynamicProgramming(dp, mark, s, i, j);

                if(k)
                {
                    int len = j - i + 1;
                    if(len > mx)
                    {
                        mx = len;
                        le = i;
                        ri = j;
                    }
                }
            }
        }
        string ret = "";
        
        for(int i = le; i <= ri; i++)
            ret += s[i];

        return ret;
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