
 
// << KUHN
vector<int> adj[lim];
int visited[lim];
int matched[lim];
 
bool findIncremental(int v, int tm)
{
    // mark as visited
    visited[v] = tm;
 
    for(int i = 0; i < adj[v].size(); i++)
    {
        int nxt = adj[v][i];
        // if not matched yet or can rematch its match
        if(matched[nxt] == 0 || visited[matched[nxt]] != tm && findIncremental(matched[nxt], tm))
        {
            // match with node v
            matched[nxt] = v;
            return true;
        }
    }
    return false;
}
 
int Kuhn()
{
    for(int i = 1; i <= N; i++)
    {
        // try to find an incremental alternate path
        findIncremental(i, i);
    }
    int ret = 0;
    //
    for(int i = 1; i <= M; i++)
        if(matched[N + i] != 0)
            ret++;
    return ret;
}
 
// << KUHN