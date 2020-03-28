/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1228 - Compound Words
	Online Judge: COJ
	Idea: Basic Use of a Trie
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e6 + 7;

struct Trie
{
    struct TrieNode
    {
        char key;
        vector<int> children;
        bool wordEnd;
        TrieNode(){}
        TrieNode(char cc)
        {key = cc; wordEnd = false;}
    };

    TrieNode * tree;
    int cntNodes;

    Trie()
    {
        tree = new TrieNode[1000003];
        tree[0] = TrieNode('$'); // root of the trie
        cntNodes = 1;
    }

    void Add(string s)
    {
        int idx = 0;
        int len = s.length();
        int curr = 0;
        while(idx < len)
        {
            char cc = s[idx];

            // find the index of this character in the node
            int auxIdx = -1;
            for(int i = 0; i < tree[curr].children.size(); i++)
                if(tree[tree[curr].children[i]].key == cc)
                { auxIdx = i; break; }

            // if the node needs to be created
            if(auxIdx == -1)
            {
                tree[curr].children.push_back(cntNodes);
                tree[cntNodes] = TrieNode(cc);
                // update the current node
                curr = cntNodes;
                // update the number of nodes
                cntNodes++;
            }
            // if not
            else
                curr = tree[curr].children[auxIdx];
            idx++;
        }
        // if sucefully inserted, mark the end of the word
        tree[curr].wordEnd = true;
    }

    bool ContainsWord(string s)
    {
        int idx = 0;
        int len = s.length();
        int curr = 0;
        while(idx < len)
        {
            char cc = s[idx];

            // find the index of this character in the node
            int auxIdx = -1;
            for(int i = 0; i < tree[curr].children.size(); i++)
                if(tree[tree[curr].children[i]].key == cc)
                { auxIdx = i; break; }

            // if the node needs to be created
            if(auxIdx == -1)
                return false;
            else curr = tree[curr].children[auxIdx];
            idx++;
        }
        return tree[curr].wordEnd;
    }

    bool ContainsWord(string s, int L, int R)
    {
        int idx = L;
        int len = s.length();
        int curr = 0;
        while(idx <= R)
        {
            char cc = s[idx];
            // find the index of this character in the node
            int auxIdx = -1;
            for(int i = 0; i < tree[curr].children.size(); i++)
                if(tree[tree[curr].children[i]].key == cc)
                { auxIdx = i; break; }

            // if the node needs to be created
            if(auxIdx == -1)
                return false;
            else curr = tree[curr].children[auxIdx];
            idx++;
        }
        return tree[curr].wordEnd;
    }

    void PrintAll(int nodeIdx, string carry)
    {
        // if End of the Word Here
        if(tree[nodeIdx].wordEnd)
            cout << carry << endl;
        // for each adjacent
        for(int i = 0; i < 26; i++)
        {
            int nxt = tree[nodeIdx].children[i];
            if(nxt > - 1)
                PrintAll(nxt, carry + tree[nxt].key);
        }
    }
};

string str;
vector<string> coll;
void solve()
{
    Trie t;
    while(cin >> str)
    {
        t.Add(str);
        coll.push_back(str);
    }

    int answ = 0;
    // for each string
    for(int c = 0; c < coll.size(); c++)
    {
        // current string
        string aux = coll[c];
        int len = aux.length();
        for(int i = 0; i < len; i++)
        {
            if( t.ContainsWord(aux, 0, i) && t.ContainsWord(aux, i + 1, len - 1) )
            {
                cout << aux << "\n";
                break;
            }
        }
    }
}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
	}
	else if(fopen("/media/luismo/Pablo's Destruction/lmo.in","r") != NULL)
	{
		freopen("/media/luismo/Pablo's Destruction/lmo.in", "r", stdin);
	}

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
