using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace COJ
{
    class Program
    {  
        /*
         * Author: LUISMO
		 *
		 * Problem: 1961 - Roadblock
         *
         * Idea: First we find the shortest path from barn 1 to N, using a classic Dijkstra
         * then I take the edges of that path and for each one of them I create a new edge
         * with its coordinates, then I call another Dikjstra (this one modified) to wich I
         * pass this edges as paramether, that is an edge with the same coordinates of the 
         * one I am willing to duplicate the value with, (I have a method in the class Edge
         * that returns if 2 edges have the same coordinates), so when I'm relaxing
         * the edges in this new Dijkstra I duplicate the value of the edges that are
         * parallel to the one in the paremether.
         * In this way I find all the possible shortest paths values when I duplicate an Edge from
         * a shortest path from 1 to N, then I take the maximun value of this paths a rest the
         * original shortest path value to this one.
         * 
         * Cost: k*O(Dijkstra) [where K is the amount of Edges in the orginal shortest paths]
         * 
         * */
        static void Main(string[] args)
       {
            TextReader tr = Console.In;
            //Console.SetIn(new StreamReader(@"f:\in.lmo"));

            string[] data = Console.ReadLine().Split(new char[]{' '},StringSplitOptions.RemoveEmptyEntries);
            
            int n = int.Parse(data[0]);
            int m = int.Parse(data[1]);

            // Matrix for enabling edges in the original shortest path
            bool[,] enabledEdges = new bool[n, n];

            // Graph adyacency
            List<List<Edge>> ady = new List<List<Edge>>(n);
            for (int i = 0; i < n; i++)
                ady.Add(new List<Edge>());

            // Reading Edges
            for (int i = 0; i < m; i++)
            {
                data = Console.ReadLine().Split(new char[]{' '},StringSplitOptions.RemoveEmptyEntries);
                Edge edge = new Edge(int.Parse(data[0]) - 1, int.Parse(data[1]) - 1, int.Parse(data[2]));
                
                // Adding bidirectional edge
                ady[edge.x].Add(edge);
                ady[edge.y].Add(new Edge(edge.y,edge.x,edge.val));
                
            }
            
            // ShortestPath
            Node[] d = Dijkstra(ady, 0);

            // Foreach edge in the path from n to 1
            int k = n - 1;
            int max = 0;
            // Running backwards from N to 1
            while (d[k].pi!=-1)
            {
                Edge temp = new Edge(k, d[k].pi,0);
                int x = DijkstraDuplicateEdge(ady, 0, temp)[n - 1].di;
                
                if (x < int.MaxValue && x > max)
                    max = x;
                k = d[k].pi;
            }

            Console.WriteLine(max - d[n-1].di);

            Console.SetIn(tr);
            Console.ReadLine();
        }


        static Node[] Dijkstra(List<List<Edge>> ady,int s)
        {
            int n = ady.Count;
            Node[] adev = new Node[n];

            // Initialize Single Source
            for (int i = 0; i < n; i++)
                adev[i] = new Node();

            // Starting Node
            adev[s].taken = true;
            adev[s].di = 0;

            // Applying Algorithm
            int totalTaken = 1;
            int lastTaken = s;

            // While last node isn't taken
            while (totalTaken > 0 && !adev[n-1].taken)
            {
                // Relaxing edges of the last taken node
                for (int i = 0; i < ady[lastTaken].Count; i++)
                {
                    // Current edge
                    Edge e = ady[lastTaken][i];

                    // RELAXING
                    if (!adev[e.y].taken && adev[lastTaken].di + e.val < adev[e.y].di)
                    {
                        adev[e.y].di = adev[lastTaken].di + e.val;
                        adev[e.y].pi = lastTaken;
                    }
                }

                // Searching for the best node to take
                int minimunValue = int.MaxValue;
                int minimunIndex = -1;
                for (int i = 0; i < n; i++)
                {
                    if (!adev[i].taken && adev[i].di < minimunValue)
                    {
                        minimunValue = adev[i].di;
                        minimunIndex = i;
                    }
                }


                // We take the node
                adev[minimunIndex].taken = true;
                lastTaken = minimunIndex;
                totalTaken++;
            }

            return adev;
        }
        
        static Node[] DijkstraDuplicateEdge(List<List<Edge>> ady, int s,Edge other)
        {
            int n = ady.Count;
            Node[] adev = new Node[n];

            // Initialize Single Source
            for (int i = 0; i < n; i++)
                adev[i] = new Node();

            // Starting Node
            adev[s].taken = true;
            adev[s].di = 0;

            // Applying Algorithm
            int totalTaken = 1;
            int lastTaken = s;

            // While last node isn't taken
            while (totalTaken > 0 && !adev[n - 1].taken)
            {
                // Relaxing edges of the last taken node
                for (int i = 0; i < ady[lastTaken].Count; i++)
                {
                    // Current edge
                    Edge e = ady[lastTaken][i];

                    // RELAXING 
                    // In this method when relaxin an Edge e, if e is paraller to the 
                    // edge passed to the argument: other , we duplicate that value
                    if (e.ParallelTo(other))
                    {
                        if (!adev[e.y].taken && adev[lastTaken].di + e.val * 2 < adev[e.y].di)
                        {
                            adev[e.y].di = adev[lastTaken].di + e.val * 2;
                            adev[e.y].pi = lastTaken;
                        }
                    }
                    // If is not parallel we keep the algorithm the same
                    else if (!adev[e.y].taken && adev[lastTaken].di + e.val < adev[e.y].di)
                    {
                        adev[e.y].di = adev[lastTaken].di + e.val;
                        adev[e.y].pi = lastTaken;
                    }
                }

                // Searching for the best node to take
                int minimunValue = int.MaxValue;
                int minimunIndex = -1;
                for (int i = 0; i < n; i++)
                {
                    if (!adev[i].taken && adev[i].di < minimunValue)
                    {
                        minimunValue = adev[i].di;
                        minimunIndex = i;
                    }
                }

                // We take the node
                adev[minimunIndex].taken = true;
                lastTaken = minimunIndex;
                totalTaken++;
            }

            return adev;
        }  

    }


    class Edge : IComparable<Edge>
    {
        public int x, y, val;
        public bool enabled;

        public Edge(int x,int y,int val)
        {
            this.x = x;
            this.y = y;
            this.val = val;
            this.enabled = true;
        }

        public int CompareTo(Edge other)
        {
            return this.val.CompareTo(other.val);
        }

        public override string ToString()
        {
            return String.Format("{0}->{1} : {2}   {3}", x, y, val, enabled);
        }

        public bool ParallelTo(Edge e)
        {
            return (this.x == e.x && this.y == e.y) || (this.x == e.y && this.y == e.x);
        }
    }

    class Node
    {
        public int di, pi;
        public bool taken;

        public Node()
        {
            this.di = int.MaxValue;
            this.pi = -1;
            this.taken = false;
        }

        public override string ToString()
        {
            return String.Format("di: {0} pi: {1}  taken: {2}",di,pi,taken);
        }
    }


}
