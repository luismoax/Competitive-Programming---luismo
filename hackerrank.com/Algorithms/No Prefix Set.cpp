/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: No Prefix Set
	Online Judge: hackerrank.com
	Idea: Use a Trie keeping the number of times a node is visiting
    during an insertion, and check wether a word has ended of the 
    current work end where another continues
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
#define ld long double
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
const int lim = 200;

int N;
string comm, word;


struct Node
{
	char key;
	map<char, Node *> adj;
	bool endWord;
	int cnt;
	Node(char k)
	{
		key = k;
		endWord = false;
		cnt = 0;
	}
};

struct Trie
{
	Node * root;
	int count;
	Trie() 
	{
		root = new Node('$');
		count = 0;
	}

	bool insert(string w)
	{
		Node * curr = root;

		for(int i = 0; i < w.size(); i++)
		{
			char k = w[i];

			if(curr->adj.find(k) == curr->adj.end())
			{
				Node * aux = new Node(k);
				curr->adj[k] = aux;
			}
			curr = curr->adj[k];
			if(curr->endWord)
				return false;
			curr->cnt ++;
		}
		if(curr->cnt > 1)
			return false;

		curr->endWord = true;
		return true;
	}

	void DFS()
	{
		for(auto item: root->adj)
		{
			DFS(item.second, "");
		}
	}

	void DFS(Node * node, string w)
	{
		w += node -> key;
		if(node->endWord)
			cout << w << " " << node->cnt<< endl;

		for( auto item: node->adj)
		{
			DFS(item.second, w);
		}
	}
};

void solve()
{
	Trie t = Trie();

	cin >> N;
	while(N-- > 0 )
	{
		cin >> word;
		if(!t.insert(word))
		{
			cout << "BAD SET" << endl;
			cout << word;
			return;
		}
	}
	cout << "GOOD SET";
	// t.DFS();
}

void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}

void IO()
{
	if(fopen("c:\\USERS\\LUISMO\\lmo.in","r") != NULL)
	{
		freopen("c:\\USERS\\LUISMO\\lmo.in","r",stdin);
	}
	else if(fopen("media/Beijing/lmo.in","r") != NULL)
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
