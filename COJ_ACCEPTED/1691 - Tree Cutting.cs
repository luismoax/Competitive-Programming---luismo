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
         Problem: 1691 - Tree Cutting
         Online Judge: COJ
         Idea: DFS, and at each node check that the number of descendants through each child and the number of nodes
		 through the branch of the father (total - (total of descendats) - 1) is less or equal than n/2
         
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
        static List<List<Edge>> adj;
        static int n;
        static bool[] visited;
        static void SolveSingleProblem()
        {

            n = int.Parse(Console.ReadLine());
            adj = new List<List<Edge>>();
            // initializing adjacency list
            for (int i = 0; i < n; i++)            
                adj.Add(new List<Edge>());
            // 
            visited = new bool[n];

            for (int i = 0; i < n-1; i++)
            {
                string[] data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                int x = int.Parse(data[0]) - 1;
                int y = int.Parse(data[1]) - 1;

                Edge e1 = new Edge(x, y);
                Edge e2 = new Edge(y,x);
                adj[x].Add(e1);
                adj[y].Add(e2);
            }
            

            BFS(0); // method from 0 as the root

            answer.Sort(); 

            for (int i = 0; i < answer.Count; i++)
            {
                Console.WriteLine(answer[i]);
            }

        }

        // array to store possible nodes
        static List<int> answer = new List<int>();
        static int BFS(int nodeIdx)
        {
            
            int cnt = 0; // number of descendats
            
            bool possible = true; //

            visited[nodeIdx] = true; // sets this node as visited

            for (int i = 0; i < adj[nodeIdx].Count; i++)
            {
                // next son
                int nextSonIdx = adj[nodeIdx][i].y;
                // if has not been visited, check it
                if(!visited[nextSonIdx])
                {
                    int k = BFS(nextSonIdx); // number of childs throught this branch
                    // setting possible if number of childs of the current branch
                    // is less than n/2
                    possible = possible && (k <= n / 2);
                    
                    cnt+=k;
                }
            }

            // if is already possible and the amout of nodes
            // through the father's branch is less than n/2
            possible = possible && ( (n - cnt - 1) <= n / 2);

            if (possible)
                answer.Add(nodeIdx + 1);

            return cnt+1;
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
        #endregion
        
    }

    class Edge
    {
        public int x, y;
        public Edge(int x, int y)
        {
            this.x = x;
            this.y = y;
        }

        public override string ToString()
        {
            return string.Format("{0} {1}", x, y);
        }
    }

    

}
