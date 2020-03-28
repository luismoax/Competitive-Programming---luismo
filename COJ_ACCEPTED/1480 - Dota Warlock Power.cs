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
            //StreamReader sr = new StreamReader(@"d:\in.lmo");
            int n = int.Parse(Console.ReadLine());            
            List<Point> lst = new List<Point>();
            string[] p = null;
            List<EdgeValue> edges = new List<EdgeValue>();

            for (int i = 0; i < n; i++)
            {
                p = Console.ReadLine().Split(' ');
                Point point = new Point(double.Parse(p[0]), double.Parse(p[1]));
                lst.Add(point);
                //A?adimos en la matriz de adyacencia
                for (int j = 0; j < lst.Count-1; j++)
                {
                    double k1 = (point.x - lst[j].x) * (point.x - lst[j].x);
                    double k2 = (point.y - lst[j].y) * (point.y - lst[j].y);
                    double distance = Math.Sqrt(k1+ k2);

                    edges.Add(new EdgeValue(i, j, distance));
                }
            }

            double d = Kruskal(n, edges)*5;
            Console.WriteLine("{0:f2}",d);
            
            Console.ReadLine();
        }


        public static double Kruskal(int n, List<EdgeValue> edges)
        {
            double cost = 0;

            DisjointSet<int> ds = new DisjointSet<int>(new int[n]);
            int tomadas = 0;

            //Ordenamos las aristas
            edges.Sort();
            //Por c\arsita en orden
            for (int i = 0; i < edges.Count && tomadas < n-1; i++)
            {
                //Si tienen setof distintos los vertices incidentes
                if (ds.SetOf(edges[i].X) != ds.SetOf(edges[i].Y))
                {
                    //Los mezclo y a?ado el valor de la arista al costo
                    ds.Merge(edges[i].X, edges[i].Y);
                    cost += (double)edges[i].Value;
                    tomadas++;
                }

            }

            return cost;
        }

    }

    class Point
    {
        public double x;
        public double y;
        public Point(double x, double y)
        {
            this.x = x;
            this.y = y;
        }
    }

    public class DisjointSet<T>
    {
        T[] values;
        int[] pi;

        public DisjointSet(T[] values)
        {
            //Colocamos los valores
            this.values = values;
            //Creamos el arreglo de paternidad con -1 en c\posicion
            pi = new int[values.Length];
            for (int i = 0; i < pi.Length; i++)
            {
                pi[i] = -1;
            }
        }

        public T[] Values
        {
            get { return this.values; }
        }


        public int SetOf(int i)
        {
            if (i < 0 || i >= values.Length)
                throw new IndexOutOfRangeException("Indice fuera de rango");

            int k = i;
            while (pi[k] >= 0)
            {
                k = pi[k];
            }
            return k;
        }

        public void Merge(int i, int j)
        {
            //Cojo los setOf de c\elemento
            int p1index = SetOf(i);
            int p2index = SetOf(j);
            //Unire por peso, en cada setof estara el valor del peso pero en negativo
            if (pi[p1index] > pi[p2index])
            {
                pi[p1index] = p2index;
            }
            else pi[p2index] = p1index;
        }

    }

    public class EdgeValue : IComparable
    {
        int x;
        int y;
        IComparable value;

        public EdgeValue(int x, int y, IComparable value)
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
            if (!(obj is EdgeValue)) throw new FormatException("Esta intentado comparar con un valor de otro tipo");
            EdgeValue ev = (EdgeValue)obj;
            return this.value.CompareTo(ev.value);
        }
    }


}
