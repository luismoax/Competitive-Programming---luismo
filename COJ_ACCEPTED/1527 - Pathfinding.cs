using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace COJ
{
    class Program
    {
        /*
         
         Author: Luis Manuel Díaz Barón (LUISMO)
         Problem: 1527 - Pathfinding
         Online Judge: COJ
         Idea: BFS over the graph
         
        */

        static void Main(string[] args)
        {
            TextReader tr = Console.In;
            // Console.SetIn(new StreamReader(@"d:\lmo.in"));

            SolveSingleProblem();

            Console.SetIn(tr);
            Console.ReadLine();
            //string[] data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
        }

        // static variables        

        // solution

        static void SolveSingleProblem()
        {
            string[] data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            int n = int.Parse(data[0]);
            int m = int.Parse(data[1]); // starting node
            
            // adjacency
            List<List<int>> adj = new List<List<int>>();
            for (int i = 0; i < n; i++)
                adj.Add(new List<int>());

            // reading graph
            for (int i = 0; i < n; i++)
            {
                data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                for (int j = 0; j < data.Length; j++)
                {
                    if (i!=j && int.Parse(data[j]) == 1)
                        adj[i].Add(j);
                }
            }

            // queue for BFS
            Queue<Node> q = new Queue<Node>();
            // true if the ith node has been visited
            bool [] visited = new bool[n];
            
            // to store answer
            List<List<int>> answer = new List<List<int>>();
            for (int i = 0; i < n; i++)
                answer.Add(new List<int>());


            // BFS
            q.Enqueue(new Node(m-1,0));
            visited[m-1] = true; // first node visited
            while (q.Count > 0)
            {
                Node current = q.Dequeue();

                // adding solution
                answer[current.level].Add(current.number + 1);

                for (int i = 0; i < adj[current.number].Count; i++)
                {
                    if(!visited[ adj[current.number][i] ] )
                    {
                        q.Enqueue(new Node(adj[current.number][i], current.level + 1));
                        visited[adj[current.number][i] ] = true;
                    }
                }
            }
            // END OF BFS

            for (int i = 0; i < answer.Count; i++)
            {
                if (answer[i].Count == 0)
                    break;

                if(i > 0)
                    Console.WriteLine();

                answer[i].Sort();
                for (int j = 0; j < answer[i].Count; j++)
                {
                    if(j==0)
                        Console.Write(answer[i][j]);
                    else Console.Write(" "+answer[i][j]);
                }                
            }
            
        }


        #region Helpers
        static int Abs(int x)
        {
            return (x < 0) ? x * -1 : x;
        }

        static int Min(int a, int b)
        {
            return (a < b) ? a : b;
        }

        static int Max(int a, int b)
        {
            return (a > b) ? a : b;
        }

        static void PrintArr<T>(T[] arr)
        {
            for (int i = 0; i < arr.Length; i++)
            {
                if (i == 0)
                    Console.Write(arr[i].ToString());
                else Console.Write(" " + arr[i].ToString());
            }
        }
        #endregion

    }

    class Node
    {
        public int number, level;
        public Node(int number, int level)
        {
            this.number = number;
            this.level = level;
        }
    }

}
