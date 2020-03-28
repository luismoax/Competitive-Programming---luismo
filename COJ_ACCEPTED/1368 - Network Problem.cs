using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace COJ
{
    class Program
    {
        static double total = double.MaxValue;
        static Point[] puntos;
        // Network Problem
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            puntos = new Point[n];
            string[] p = null;
            for (int i = 0; i < n; i++)
            {
                p = Console.ReadLine().Split(' ');
                puntos[i] = new Point(int.Parse(p[0]), int.Parse(p[1]));
            }

            Costo(new Point[n], new bool[n], 0, 0);

            Console.WriteLine("{0:f2}",total);
            Console.ReadLine();
        }

        static void Costo(Point [] arr, bool [] barray, int index, double costo)
        {
            if (index == puntos.Length)
            {
                if (costo < total)
                    total = costo;
                return;
            }

            for (int i = 0; i < puntos.Length; i++)
            {
                if (!barray[i])
                {
                    arr[index] = puntos[i];
                    double d = 0;
                    if (index > 0)
                        d= arr[index].Distance(arr[index - 1]);
                    
                    barray[i] = true;

                    //Llamo al metodo
                    Costo(arr, barray, index + 1, costo+d);

                    barray[i] = false;
                }
            }
        }
    }

    class Point
    {
        public int x;
        public int y;
        public Point(int x, int y)
        {
            this.x = x;
            this.y = y;
        }

        public double Distance(Point p)
        {
            return Math.Sqrt((this.x - p.x) * (this.x - p.x) + (this.y - p.y) * (this.y - p.y));
        }

    }

}