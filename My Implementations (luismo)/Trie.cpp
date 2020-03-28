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

	void insert(string w)
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
			curr->cnt ++;
		}
		curr->endWord = true;
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