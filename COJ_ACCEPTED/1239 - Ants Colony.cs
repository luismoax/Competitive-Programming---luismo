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
          Author: Luismo
          Problem: 1239 - Ants Colony
          Online Judge: COJ
          Idea: Use LCA algorithm, keep track for every node about its level and its distance to root.
        */


        static void Main(string[] args)
        {
            TextReader tr = Console.In;
            TextWriter tw = Console.Out;

            // Console.SetIn(new StreamReader(@"d:\lmo.in"));

            SolveSingleProblem();


            Console.SetIn(tr);
            Console.SetOut(tw);
            Console.ReadLine();

            //string[] data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
        }

        // static variables
        static List<List<Path>> adj;
        static int n;
        static AntHill[] nodes;
        // for BFS and Euler tour
        static bool[] dfsVisited;

        static List<int> eulerTour;
        static int[] ocurrences;
        // for RMQ
        static int[,] RMQTable;

        static void SolveSingleProblem()
        {
            n = -1;
            while (n != 0)
            {
                // for reading
                string[] data = { };

                // number of nodes
                n = int.Parse(Console.ReadLine());

                if (n == 0)
                    return;

                // reading adjacency
                adj = new List<List<Path>>();
                for (int i = 0; i < n; i++)
                    adj.Add(new List<Path>());

                // reading n-1 edges
                for (int i = 1; i <= n - 1; i++)
                {
                    data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);

                    int ai = int.Parse(data[0]);
                    int length = int.Parse(data[1]);

                    Path p1 = new Path(i, ai, length);
                    Path p2 = new Path(ai, i, length);

                    // adding edges to the adjancency
                    adj[i].Add(p1);
                    adj[ai].Add(p2);
                }

                // array of nodes
                nodes = new AntHill[n];
                for (int i = 0; i < n; i++)
                    nodes[i] = new AntHill(i);
                // setting nodes[0] - root
                nodes[0].dfsLevel = 0;
                nodes[0].distance = 0;

                // PROCESS the LCA

                // finding euler tour and setting values using it 
                dfsVisited = new bool[n]; // for marks
                dfsVisited[0] = true;
                eulerTour = new List<int>(); // stores the complete euler tour
                // the index in the list of the euler tour of the first ocurrence of each element
                ocurrences = new int[n];

                //
                EulerTour(0);

                // Processing RMQ Table
                RMQTable = RMQProcessTable();

                // number of queries
                int queries = int.Parse(Console.ReadLine());

                StringBuilder sb = new StringBuilder();
                // Reading queries
                for (int i = 0; i < queries; i++)
                {
                    data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);

                    int one = int.Parse(data[0]);
                    int two = int.Parse(data[1]);

                    // index of the LCA int the nodes array
                    int qqq = RMQQuery(ocurrences[one], ocurrences[two]);
                    //
                    long answer = (nodes[one].distance - nodes[qqq].distance) + (nodes[two].distance - nodes[qqq].distance);

                    sb.Append(answer + " ");
                }
                
                Console.WriteLine(sb.ToString().Trim());

            }
        }

        private static int[,] RMQProcessTable()
        {
            // RMQ over the euler tour
            int col = (int)Math.Ceiling(Math.Log(eulerTour.Count, 2));
            int N = eulerTour.Count;
            // MAtrix for RMQ
            int[,] RMQ = new int[N, col];

            // setting intervals of length 1
            for (int i = 0; i < RMQ.GetLength(0); i++)
                RMQ[i, 0] = i;

            // foreach possible length
            for (int j = 1; (1 << j) <= N; j++)
            {
                for (int i = 0; i + (1 << j) - 1 < N; i++)
                {
                    // index on the Nodes array
                    int idx1 = eulerTour[RMQ[i, j - 1]];
                    int level1 = nodes[idx1].dfsLevel;

                    // index on the Nodes array
                    int idx2 = eulerTour[RMQ[i + (1 << (j - 1)), j - 1]];
                    int level2 = nodes[idx2].dfsLevel;

                    // if the first level is better
                    if (level1 < level2)
                        RMQ[i, j] = RMQ[i, j - 1];
                    else RMQ[i, j] = RMQ[i + (1 << (j - 1)), j - 1];
                }
            }

            return RMQ;
        }

        static int RMQQuery(int i, int j)
        {
            // if indexes are exchanged, swap them right
            if (j < i)
                Swap(ref i, ref j);


            int length = (j - i + 1);
            int k = (int)Math.Log(length, 2);

            // indexes on the EulerTour list
            int first = RMQTable[i, k];
            int second = RMQTable[j - (1 << k) + 1, k];

            // indexes on the Nodes array
            int idxOnNodes1 = eulerTour[first];
            int idxOnNodes2 = eulerTour[second];

            // comparing by distance to root
            if (nodes[idxOnNodes1].dfsLevel < nodes[idxOnNodes2].dfsLevel)
                return idxOnNodes1;
            return idxOnNodes2;
        }





        static void EulerTour(int id)
        {
            if (id > 0 && ocurrences[id] == 0)
                ocurrences[id] = eulerTour.Count;

            // adding to the euler tour
            eulerTour.Add(id);

            //foreach possible 'son'
            for (int i = 0; i < adj[id].Count; i++)
            {
                Path p = adj[id][i];
                if (!dfsVisited[p.y])
                {
                    // setting visited, level and distance from root
                    dfsVisited[p.y] = true;
                    nodes[p.y].distance = nodes[id].distance + p.v;
                    nodes[p.y].dfsLevel = nodes[id].dfsLevel + 1;
                    // recursive call
                    EulerTour(p.y);

                    // adding this node again to the euler tour
                    eulerTour.Add(id);
                }
            }
        }

        static void Swap(ref int a, ref int b)
        {
            int x = a;
            a = b;
            b = x;
        }



    }

    // NODES
    class AntHill
    {
        public int id;
        public int dfsLevel;
        public long distance;

        public AntHill(int id)
        {
            this.id = id;
        }

        public override string ToString()
        {
            return string.Format("id:{0} L:{1} D:{2}", id, dfsLevel, distance);
        }

    }

    // EDGES
    class Path
    {
        public int x, y, v;
        public Path(int x, int y, int v)
        {
            this.x = x;
            this.y = y;
            this.v = v;
        }

        public override string ToString()
        {
            return string.Format("{0}->{1} : {2}", x, y, v);
        }
    }



}
