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
          Problem: 1032 - Cow Politics
          Online Judge: COJ
          Idea: Use a LCA algorithm. Foreach party we must find the pair of nodes U and V such as distance from U to V is maximum for 
		  that party, so first of all the diameter of a tree is found doing 2 BFS the first one from a leaf (root), the furthest node found
		  on the first BFS is used as root for the second one, is proven that a path of maximum length can be found on the second BFS from the
		  root to it's fruthest node. Then all we need is foreach party make a BFS, such as the furthest node found will be one of the extremes
		  on a path of maximum length, then use LCA algorithm with this node to every other node in the party, so I can find the largest path
		  on the tree.
		*/


        static void Main(string[] args)
        {
            TextReader tr = Console.In;
            TextWriter tw = Console.Out;

            // Console.SetIn(new StreamReader(@"d:\cowpol\cowpol.5.in"));

            SolveSingleProblem();


            Console.SetIn(tr);
            Console.SetOut(tw);
            Console.ReadLine();

            //string[] data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
        }

        // static variables
        
        static List<int> [] adj;
        static List<int>[] parties; // for parties
        static List<Node> nodes;

        // for EulerTour
        static List<int> eulerTour;
        static int root;
        
        // For RMQ
        static int[,] rmqTable;

        static void SolveSingleProblem()
        {
            string[] data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            int n = int.Parse(data[0]);
            
            int k = int.Parse(data[1]);

            // nodes
            nodes = new List<Node>();

            // parties
            parties = new List<int>[k];
            for (int i = 0; i < parties.Length; i++)
                parties[i] = new List<int>();

            // reading / setting adjacency
            adj = new List<int>[n];
            for (int i = 0; i < n; i++)
                adj[i] = new List<int>();

            // reading adjacency
            for (int i = 0; i < n; i++)
            {
                data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                int party = int.Parse(data[0]);
                int parent = int.Parse(data[1]);

                // adding the node
                nodes.Add(new Node(i, (parent == 0) ? 0:-1 , party - 1));

                // adding adjacency
                if (parent > 0)
                    adj[parent - 1].Add(i);
                else root = i;
                // adding to a Party
                parties[party - 1].Add(i);
            }

            // --- LCA ---

            // --- EULER TOUR ---
            eulerTour = new List<int>();
            Tour(root);
            // --- END EULER TOUR ---

            // --- RMQ PREPROCESS ---
            RMQPreProcess();
            // --- END RMQ PREPROCESS ---

            // --- END LCA ---

			// this array stores the last node found per party in a BFS from the root
			// lastPerParty[i] is the last node of the i-th party found on the BFS traversal
            int[] lastPerParty = BFS(n, k);

			// foreach party 
            for (int pp =0 ; pp < parties.Length ; pp++)
            {
                int max = 0;
				// foreach node on current party
				// calculate LCA with the last node of this party found in the previous BFS
                for (int i = 0; i < parties[pp].Count; i++)
                {
                    int first = parties[pp][i]; // i-th node of the party
                    int second = lastPerParty[pp]; // last node of the party found on the BFS
					
					// LCA
                    int lca = RMQQuery(nodes[first].firstOcurrence, nodes[second].firstOcurrence);
					// distance measured in edges
                    int tmp = (nodes[first].level + nodes[second].level) - (2 * nodes[lca].level);
                    
                    // updating maximum
                    if(tmp > max)
                        max = tmp;
                }
				// answer
                Console.WriteLine(max);
            }

        }

        private static int[] BFS(int n, int k)
        {
            // BFS to set the last per PARTY
            int[] lastPerParty = new int[k];
            bool[] taken = new bool[n];

            Queue<int> q = new Queue<int>();
            q.Enqueue(root);
            taken[0] = true;

            while (q.Count > 0)
            {
                int current = q.Dequeue();

                lastPerParty[nodes[current].PARTY] = current;

                for (int i = 0; i < adj[current].Count; i++)
                {
                    int idx = adj[current][i];
                    
                    q.Enqueue(idx);
                    
                }
            }

            return lastPerParty;
        }


        static void Tour(int idx)
        {
            // setting ocurrences
            if (nodes[idx].firstOcurrence == -1)
                nodes[idx].firstOcurrence = eulerTour.Count;
            // adding to the tour
            eulerTour.Add(idx);

            // forach possible son
            for (int i = 0; i < adj[idx].Count; i++)
            {
                // next node to scan
                Node next = nodes[adj[idx][i]];
                // setting level
                next.level = nodes[idx].level + 1;
                // recursively call
                Tour(next.id);
                // adding to the tour
                eulerTour.Add(idx);                
            }

        }

        static void RMQPreProcess()
        {
            int n = eulerTour.Count;

            // table for RMQ
            rmqTable = new int[n, (int)Math.Ceiling(Math.Log(n, 2))];

            // setting intervals of length 1
            for (int i = 0; i < n; i++)
                rmqTable[i, 0] = eulerTour[i];

            // foreach  possible interval
            for (int j = 1; 1 << j <= n; j++)
            {
                // foreach possible start
                for (int i = 0; i + (1 << j) - 1 < n; i++)
                {
                    int idx1 = rmqTable[i, j - 1];
                    int idx2 = rmqTable[i + (1 << (j - 1)), j - 1];

                    if (nodes[idx1].level < nodes[idx2].level)
                        rmqTable[i, j] = idx1;
                    else rmqTable[i, j] = idx2;
                }
            }
        }

        static int RMQQuery(int i, int j)
        {
            if (j < i)
                Swap(ref i,ref j);
            
            int block = (int)Math.Log((j - i + 1), 2);

            int idx1 = rmqTable[i,block];

            int idx2 = rmqTable[j - (1 << block) + 1, block];

            if (nodes[idx1].level < nodes[idx2].level)
                return idx1;

            return idx2;
        }

        #region Auxiliar Methods
        static void Swap(ref int a, ref int b)
        {
            int x = a;
            a = b;
            b = x;
        }

        static int Min(int a, int b)
        {
            return (a < b) ? a : b;
        }

        static int Max(int a, int b)
        {
            return (a > b) ? a : b;
        }

        static int Abs(int a)
        {
            return (a < 0) ? -1 * a : a;
        }
        #endregion

    }



    class Node
    {
        public int 
            id, 
            level,
            PARTY,
            firstOcurrence = -1
            ;

        public Node(int id, int level, int party)
        {
            this.id = id;
            this.level = level;            
            this.PARTY = party;
        }

        public override string ToString()
        {
            return string.Format("ID:{0} L:{1} P:{3} V:{2}", id, level,PARTY);
        }
    }
}
