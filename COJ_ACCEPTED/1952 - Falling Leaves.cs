using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace COJ
{
    class Program
    {
		/*
		* Author: Luismo
		* Problem: Falling Leaves
		* Judge: COJ
		* Idea: The idea for this problem is to build a Binary Search Tree, and insert the given values
		* in reverse order, and the do a pre-order traversal in the Tree
		*
		*/
        static void Main(string[] args)
        {            
            bool stop = false;
            string collection = "";
            while (!stop)
            {
                string s = Console.ReadLine();
                if (s == "*" || s== "$")
                {
                    BinarySearTree<char> abb = new BinarySearTree<char>();
                    for (int i = 0; i < collection.Length; i++)
                    {
                        abb.Insert(collection[collection.Length - 1 - i]);
                    }
                    abb.DFS();
                    Console.WriteLine();
                    // Reset Collection
                    collection = "";
                    
                    if (s == "$")
                        stop = true;
                }                
                else
                {
                    collection+=s;
                }
            }

            Console.ReadLine();
        }


    }

    class BinarySearTree<T> where T:IComparable
    {
        public BinarySearchTreeNode<T> root;
        int count;
        public BinarySearTree()
        {
            root = null;
        }

        public void Insert(T value)
        {
            if (root == null)
                root = new BinarySearchTreeNode<T>(value);
            else
            {
                BinarySearchTreeNode<T> node = root;
                bool found = false;
                while (!found)
                {
                    if (value.CompareTo(node.Value) <= 0)
                    {
                        if (node.Left == null)
                        {
                            node.Left = new BinarySearchTreeNode<T>(value);
                            found = true;
                        }
                        else node = node.Left;
                    }
                    else
                    {
                        if(node.Right == null)
                        {
                            node.Right = new BinarySearchTreeNode<T>(value);
                            found=true;
                        }
                        else node = node.Right;
                    }
                }
            }
            this.count++;
        }

        public void DFS()
        {
            DFS(this.root);
        }

        void DFS(BinarySearchTreeNode<T> node)
        {
            Console.Write(node.Value);
            if (node.Left != null)
                DFS(node.Left);
            if (node.Right != null)
                DFS(node.Right);
        }

        public int Count
        {
            get { return this.count; }
        }
    }

    class BinarySearchTreeNode<T> where T:IComparable
    {
        T value;
        BinarySearchTreeNode<T> left;
        BinarySearchTreeNode<T> right;

        public BinarySearchTreeNode(T value)
        {
            this.value = value;
            left = null;
            right = null;
        }

        public T Value
        {
            get { return this.value; }
        }

        public BinarySearchTreeNode<T> Left
        {
            get { return this.left; }
            set { this.left = value; }
        }

        public BinarySearchTreeNode<T> Right
        {
            get { return this.right; }
            set { this.right = value; }
        }

        public bool IsLeaf
        {
            get { return this.left == null && this.right == null; }
        }

        

        public override string ToString()
        {
            return this.value.ToString();
        }
    }
}
