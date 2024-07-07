class Solution {
public:
    int min(int a, int b)
    {
        if(a < b) return a;
        return b;
    }
    
    // dp[i][j] = the minumun number of coins that I can use to achieve the value i using the first j coins

    int DynamicProgramming(vector<int>& coins, int amount, int ithCoin, vector<vector<int>> &dp, vector<vector<int>> &mark)
    {
        if(amount == 0)        
            return 0;
        
        if(ithCoin < 0)
            return 100000;

        if(mark[amount][ithCoin])
            return dp[amount][ithCoin];

        mark[amount][ithCoin] = true;

        dp[amount][ithCoin] = 100000;
        
        if(amount - coins[ithCoin] >= 0)        
            dp[amount][ithCoin] = DynamicProgramming(coins, amount - coins[ithCoin], ithCoin, dp, mark) + 1;       

        int aux = DynamicProgramming(coins, amount, ithCoin - 1, dp, mark);

        dp[amount][ithCoin] = min(dp[amount][ithCoin], aux);
        return dp[amount][ithCoin];
    }


    int coinChange(vector<int>& coins, int amount)
    {
        int sz = coins.size();

        vector<vector<int>> dp(amount + 1, vector<int>(sz, 0));
        vector<vector<int>> mark(amount + 1, vector<int>(sz, 0));

        int answ = 0;

        answ = DynamicProgramming(coins, amount, sz - 1, dp, mark);

        if(answ == 100000)
            answ = -1;
        return answ;
    }    
};