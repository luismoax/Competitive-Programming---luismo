/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
    struct Node {
        int data;
        Node* left;
        Node* right;
    }
*/
    bool checkBST(Node* root) {
       pair<bool, pair<int, int>> answ = C(root);
        return answ.first;
    }

    // returns the min,max values found
    pair<bool, pair<int, int> > C(Node * root) {
        pair<bool, pair<int, int>> ret = make_pair(true, make_pair(root->data, root->data));
        
        if(root->left != NULL)
        {
            pair<bool, pair<int, int>> aux = C(root->left);
            ret.first = ret.first && aux.first;
            
            if(aux.second.second >= root->data)
                ret.first = false;
            
            ret.second.first = min(ret.second.first, aux.second.first);                                       ret.second.second = max(ret.second.second, aux.second.second);
            
        }
        
        if(root->right != NULL)
        {
            pair<bool, pair<int, int>> aux = C(root->right);
            ret.first = ret.first && aux.first;
            
            
            if(aux.second.first <= root->data)
                ret.first = false;
            
            ret.second.first = min(ret.second.first, aux.second.first);                                       ret.second.second = max(ret.second.second, aux.second.second);
        }
        return ret;
    }


