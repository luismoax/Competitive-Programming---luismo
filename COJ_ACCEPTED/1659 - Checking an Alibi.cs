using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace COJ
{
    class Program
    {
		//1659 - Checking an Alibi
        static void Main(string[] args)
        {
            string[] split = Console.ReadLine().Split(' ');
            int f = int.Parse(split[0]), p = int.Parse(split[1]);
            int c = int.Parse(split[2]), m = int.Parse(split[3]);

            //Para guardar las aristas
            Edge[] edges = new Edge[p];
            //Guardando los caminos
            for (int i = 0; i < p; i++)
            {
                split = Console.ReadLine().Split(' ');
                int x1 = int.Parse(split[0]) - 1;
                int x2 = int.Parse(split[1]) - 1;
                int v = int.Parse(split[2]);
                //Guardando la arista
                edges[i] = new Edge(x1,x2, v);                
            }

            //Para guardar el indice del granero donde esta c\vaca
            int [] farmcow = new int[c];
            for (int i = 0; i < c; i++)
            {
                farmcow[i] = int.Parse(Console.ReadLine())-1;
            }
            //Aplicamos Bellman-Ford y nos quedamos con el arreglo de di
            int[] di = BellmanFord(f, edges);
            //Lista para meter a las vacas culpables
            List<int> guiltyOnes = new List<int>();
            
            for (int i = 0; i < farmcow.Length; i++)
            {
                if (di[farmcow[i]] <= m)
                {
                    guiltyOnes.Add(i+1);
                }
            }
            guiltyOnes.Sort();
            Console.WriteLine(guiltyOnes.Count);
            foreach (var item in guiltyOnes)
            {
                Console.WriteLine(item);
            }

            Console.ReadLine();
        }



        static int[] BellmanFord(int n, Edge[] edges)
        {
            int[] di = new int[n];
            for (int i = 0; i < di.Length; i++)
                di[i] = int.MaxValue;
            di[0] = 0;

            for (int i = 0; i < n-1; i++)
            {
                //n-1 ciclos
                for (int j = 0; j < edges.Length; j++)
                {
                    //Relajo todas las aristas
                    int x = edges[j].X;
                    int y = edges[j].Y;

                    if (di[x]!=int.MaxValue && di[x] + (int)edges[j].Value <= di[y])
                    {
                        di[y] = di[x] + (int)edges[j].Value;
                    }
                    else if (di[y]!=int.MaxValue && di[y] + (int)edges[j].Value <= di[x])
                    {
                        di[x] = di[y] + (int)edges[j].Value;
                    }
                }
            }
            return di;
        }


    }

    public class Edge : IComparable
    {
        int x;
        int y;
        IComparable value;

        public Edge(int x, int y, IComparable value)
        {
            this.x = x;
            this.y = y;
            this.value = value;
        }

        public int X
        {
            get { return this.x; }
        }

        public int Y
        {
            get { return this.y; }
        }

        public IComparable Value
        {
            get { return this.value; }
        }

        public int CompareTo(object obj)
        {
            if (!(obj is Edge)) throw new FormatException("Esta intentado comparar con un valor de otro tipo");
            Edge ev = (Edge)obj;
            return this.value.CompareTo(ev.value);
        }
    }


}
