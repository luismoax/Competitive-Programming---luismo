using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace COJ
{
    class Program
    {
        //1847 - Claustrophobic Cows
        static void Main(string[] args)
        {
            int finalX = -1;
            int finalY = -1;
            
            double lowestDistance = double.MaxValue;
            List<Edge> lst = new List<Edge>();
            string[] p = null;
            int n = int.Parse(Console.ReadLine());
            for (int c = 0; c < n; c++)
            {
                p = Console.ReadLine().Split(' ');
                int x = int.Parse(p[0]);
                int y = int.Parse(p[1]);

                Edge e = new Edge(x, y, c + 1);

                for (int i = 0; i < lst.Count; i++)
                {
                    Edge aux = lst[i];
                    double d = Math.Sqrt((e.x - aux.x) * (e.x - aux.x) + (e.y - aux.y) * (e.y - aux.y));
                    if (d < lowestDistance)
                    {
                        lowestDistance = d;
                        finalX = e.value;
                        finalY = aux.value;
                    }

                }
                lst.Add(e);
            }
            if (finalX > finalY)
                Console.WriteLine("{0} {1}", finalY, finalX);
            else Console.WriteLine("{0} {1}", finalX, finalY);


            Console.ReadLine();
        }



    }

    class Edge : IComparable<Edge>
    {
        public long x;
        public long y;
        public int value;

        public Edge(long x, long y, int value)
        {
            this.x = x;
            this.y = y;
            this.value = value;
        }

        public int CompareTo(Edge other)
        {
            return this.value.CompareTo(other);
        }
    }

}
