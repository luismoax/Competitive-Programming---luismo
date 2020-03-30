#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  	
  	void preOrder(Node *root) {
		
      	if( root == NULL )
          	return;
      
      	std::cout << root->data << " ";
      	
      	preOrder(root->left);
      	preOrder(root->right);
    }

/*
Node is defined as 

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    Node * insert(Node * root, int data) {
        if(root == NULL)
        {
            root = new Node(data);
            return root;
        }
        if(data < root->data)
        {
            if(root->left == NULL)            
                root->left = new Node(data);            
            else insert(root->left, data);
        }
        else
        {
            if(root->right == NULL)            
                root->right = new Node(data);            
            else insert(root->right, data);
        }
        return root;
    }

};