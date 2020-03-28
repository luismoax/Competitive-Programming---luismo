/*
	Author: Luis Manuel D?az Bar?n (LUISMO)
	Problem: TRYCOMP
	Online Judge:
	Idea: Use a Trie, insert the words from the book first, and the insert the query words
	process using dp the Trie
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf
#define mkp make_pair
#define fi first
#define se second
#define endl "\n"

using namespace std;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e16 + 3;
const int mod = 1e9 + 7;
const int lim = 1e6 + 2;


string answ[lim];

string toString(int x)
{
    string s = "";
    if(x == 0)
        return "0";
    while(x > 0)
    {
        char c = (x % 10) + '0';
        s = c + s;
        x/=10;
    }
    return s;
}

// by Luismo
class TrieNode
{

public:
    char c;
    vector<TrieNode> sons;
    int word;

    vector<int> qs;

    TrieNode(){c = '$'; word = 0; }

};

class Trie
{

private:
    TrieNode * root;
    int sz;

    void DFS(TrieNode * node, string s)
    {
        // if found a word's end
        if(node->word > 0)
            cout << s << ": " << node->word << endl;

        // for each possible adjacent
        for(int i = 0; i < node->sons.size(); i++)
        {
            if(node->sons[i].c != '$')
                DFS(&node->sons[i], s + node->sons[i].c);
        }
    }

    pair<int, string> DFSAnswer(TrieNode * node, string s)
    {
        pair<int, string> pp = mkp(0, "");
        if(node->word > 0)
            pp = mkp(node->word, s);

        // foreach adjacent node
        for(int i = 0; i < node->sons.size(); i++)
        {
            if(node->sons[i].c != '$')
            {
                // take the best pair from a subtree
                pair<int, string> aux = DFSAnswer(&node->sons[i], s + node->sons[i].c);
                // update the best pair
                pp = cmp(pp, aux);
            }
        }

        // if the current end means queries ends
        if(node->qs.size() > 0)
        {
            for(int i = 0; i < node->qs.size(); i++)
            {
                if(pp.first == 0)
                    answ[node->qs[i]] = "-1";
                else answ[node->qs[i]] = pp.second + " " + toString(pp.first);
            }
        }
        // return the best pair
        return pp;
    }

    // compares 2 pairs of int string and returns the best according to the
    // problem statement
    pair<int, string> cmp(pair<int, string> p1, pair<int, string> p2)
    {
        if(p1.first == p2.first)
        {
            if(p1.second < p2.second)
                return p1;
            return p2;
        }
        if(p1.first > p2.first)
            return p1;
        return p2;
    }

public:

    // Constructor
    Trie()
    {
        root = new TrieNode();
        sz = 0;
    }

    // size of the Trie
    int size()
    {
        return sz;
    }

    void add(string & s, int qIdx)
    {
        TrieNode * node = root;
        // for each character in the string
        for(int i = 0; i < s.size(); i++)
        {
            // if the nodeent node hasn't created it's sons
            if(node->sons.size() == 0)
                node->sons.resize(26, TrieNode());

            // index of the nodeent char
            int idx = s[i] - 'a';

            // wirte the char in the next node (no necessary but...)
            node->sons[idx].c = s[i];
            // move to the next node
            node = &node->sons[idx];
        }

        // update the nodes' query index


        // if the inserted element is a query then do not
        // increase the number of words
        if(qIdx != -1)
        {
            node->qs.push_back(qIdx);
            return;
        }

        // if the word wasn't previously inserted
        if(node->word == 0)
            // increase the size of the Trie
            sz++;
        // increase the frequency of the word
        node->word++;
    }

    void processAnswer()
    {
        DFSAnswer(root, "");
    }

    // DFS traversal (word by word)
    void DFS()
    {
        DFS(root, "");
    }
};



int n, q;
string str;

void solve()
{
    Trie * t = new Trie();
    cin >> n;
    // instert the strings in the Trie
    while(n-- > 0)
    {
        cin >> str;
        t->add(str, -1);
    }

    cin >> q;
    // insert the queries in the Trie too
    for(int i = 0; i < q; i++)
    {
        cin >> str;
        t->add(str, i);
    }

    t->processAnswer();

    // print the queries' answers
    for(int i = 0; i < q; i++)
        cout << answ[i]  << endl;
}

void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}

void IO()
{
	if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
	}
	else if(fopen("/media/Beijing/lmo.in","r") != NULL)
	{
		freopen("/media/Beijing/lmo.in", "r", stdin);
	}
}

int main()
{
	IO();

	fastIO();

	solve();
}

