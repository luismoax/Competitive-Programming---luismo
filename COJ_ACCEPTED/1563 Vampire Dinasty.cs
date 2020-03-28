using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace COJ
{
    class Program
    {
        static int[] di;
        static void Main(string[] args)
        {
            string[] split = Console.ReadLine().Split(' ');
            int n = int.Parse(split[0]), e = int.Parse(split[1]);
            int s = int.Parse(split[2]), t = int.Parse(split[3]);

            Edge[] edges = new Edge[e];

            for (int i = 0; i < e; i++)
            {
                split = Console.ReadLine().Split(' ');
                int a = int.Parse(split[0]);
                int b = int.Parse(split[1]);
                int c = int.Parse(split[2]);
                int d = int.Parse(split[3]);

                Edge k = new Edge(a, b, c - d);
                k.append = c;

                edges[i] = k;
            }

            int[] sunImpact = BellmanFord(n, edges, s);
            Console.WriteLine("{0} {1}", di[t], sunImpact[t]);

            Console.ReadLine();
        }


        static int[] BellmanFord(int n, Edge[] edges, int startingVertex)
        {
            int[] sunImpact = new int[n];
            di = new int[n];
            for (int i = 0; i < sunImpact.Length; i++)
            {
                sunImpact[i] = int.MaxValue;
                di[i] = int.MaxValue;
            }
            //En el vertice inicial ponemos en 0
            sunImpact[startingVertex] = 0;
            di[startingVertex] = 0;

            for (int i = 0; i < n - 1; i++)
            {
                //n-1 ciclos
                for (int j = 0; j < edges.Length; j++)
                {
                    //Relajo todas las aristas
                    int x = edges[j].x;
                    int y = edges[j].y;

                    if (sunImpact[x] != int.MaxValue && sunImpact[x] + (int)edges[j].Value < sunImpact[y])
                    {
                        sunImpact[y] = sunImpact[x] + (int)edges[j].Value;
                        di[y] = di[x] + edges[j].append;
                    }
                    else if (sunImpact[y] != int.MaxValue && sunImpact[y] + (int)edges[j].Value < sunImpact[x])
                    {
                        sunImpact[x] = sunImpact[y] + (int)edges[j].Value;
                        di[x] = di[y] + edges[j].append;
                    }
                    //En caso de que no se minimize la exposicion al sol buscaremos minimizar la distancia
                    else if (sunImpact[y] != int.MaxValue && sunImpact[y] + (int)edges[j].Value == sunImpact[x])
                    {
                        if (di[y] + edges[j].append < di[x])
                        {
                            di[x] = di[y] + edges[j].append;
                        }
                    }
                    else if (sunImpact[x] != int.MaxValue && sunImpact[x] + (int)edges[j].Value == sunImpact[y])
                    {
                        if (di[x] + edges[j].append < di[y])
                        {
                            di[y] = di[x] + edges[j].append;
                        }
                    }
                }
            }
            return sunImpact;
        }


    }

    public class Edge : IComparable<Edge>
    {
        public int x;
        public int y;
        IComparable value;
        public int append;

        public Edge(int x, int y, IComparable value)
        {
            this.x = x;
            this.y = y;
            this.value = value;
        }

        public IComparable Value
        {
            get { return this.value; }
        }

        public int CompareTo(Edge other)
        {
            if (this.value.CompareTo(other.value) == 0)
            {
                return this.append.CompareTo(other.append);
            }
            return this.value.CompareTo(other.value);
        }
    }


}
