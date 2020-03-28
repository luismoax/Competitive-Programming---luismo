using System;
using System.Collections.Generic;
using System.Text;
using System.IO;


namespace COJ
{
    class Program
    {
        static void Main(string[] args)
        {
            //StreamReader Console = new StreamReader(@"d:\in.lmo");
            string[] p = Console.ReadLine().Split(' ');
            int n = int.Parse(p[0]);
            int m = int.Parse(p[1]);
            //Pesos de los nodos
            p = Console.ReadLine().Split(' ');
            int[] nodeWeight = new int[p.Length];
            for (int i = 0; i < p.Length; i++)
            {
                nodeWeight[i] = int.Parse(p[i]);
            }

            List<List<Edge>> ady = new List<List<Edge>>(n);
            for (int i = 0; i < n; i++)
            {
                ady.Add(new List<Edge>());
            }

            for (int i = 0; i < m; i++)
            {
                p = Console.ReadLine().Split(' ');
                Edge e1 = new Edge(int.Parse(p[0]) - 1, int.Parse(p[1]) - 1, 1);
                Edge e2 = new Edge(int.Parse(p[1]) - 1, int.Parse(p[0]) - 1, 1);
                ady[e1.x].Add(e1);
                ady[e2.x].Add(e2);
            }

            int[] f = Disjktra(n, ady, nodeWeight);

            Console.WriteLine(f[n - 1]);

            Console.ReadLine();
        }

        static int[] Disjktra(int n, List<List<Edge>> ady, int[] weights)
        {
            int[] di = new int[n];
            //Ponemos todo en oo
            for (int i = 0; i < n; i++)
                di[i] = int.MaxValue;
            di[0] = 0;

            //Ponemos los pesos en 0 de los lugares donde no se paga
            weights[0] = 0;
            weights[n - 1] = 0;

            bool[] takenNodes = new bool[n];
            int takenNodesCount = 0;
            int index = -1;

            do
            {
                index = -1;
                //Buscamos el de menor distancia O(n)
                long kid = long.MaxValue;
                for (int i = 0; i < di.Length; i++)
                {
                    if (!takenNodes[i] && di[i] < kid)
                    {
                        kid = di[i];
                        index = i;
                    }
                }

                
                takenNodes[index] = true;
                takenNodesCount++;

                //Relajamos c\u de sus aristas
                for (int i = 0; i < ady[index].Count; i++)
                {
                    Edge e = ady[index][i];
                    if (!takenNodes[e.y] && di[index] + weights[e.y] < di[e.y])
                    {
                        di[e.y] = di[index] + weights[e.y];
                    }
                }

            }
            while (takenNodesCount < n);

            return di;
        }

    }

    class Edge
    {
        public int x, y, value;

        public Edge(int x, int y, int value)
        {
            this.x = x;
            this.y = y;
            this.value = value;
        }
    }

}