class Solution {
public:

    vector<vector<int>> FloydWarshall(int n, vector<vector<int>> &mt)
    {
        for(int k = 0; k < n; k++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(mt[i][k] + mt[k][j] < mt[i][j])
                        mt[i][j] = mt[i][k] + mt[k][j];
                }
            }
        }
        return mt;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>> mt(n, vector<int> (n, distanceThreshold + distanceThreshold));

        for(int i = 0; i < edges.size(); i++)
        {
            int from = edges[i][0];
            int to = edges[i][1];
            int cost = edges[i][2];

            mt[from][to] = cost;
            mt[to][from] = cost;
        }

        for(int i = 0; i < n; i++)
            mt[i][i] = 0;

        FloydWarshall(n, mt);

        int mn = n;
        int city = -1;
        
        for(int i = 0; i < n; i++)
        {
            int cnt = 0;
            for(int j = 0; j < n; j++)
            {
                if(i == j)
                    continue;
                if(mt[i][j] <= distanceThreshold)
                    cnt++;
            }

            if((cnt < mn) || (cnt == mn && i > city))
            {
                mn = cnt;
                city = i;
            }            
        }
        
        return city;
    }
};