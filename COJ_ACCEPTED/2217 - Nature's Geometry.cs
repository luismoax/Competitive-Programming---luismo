using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;


namespace COJ
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            TextReader tr = Console.In;
            TextWriter tw = Console.Out;
            //Console.SetIn(new StreamReader(@"d:\lmo.in"));
            //Console.SetOut(new StreamWriter(@"d:\lmo.out"));
            //string [] data = Console.ReadLine().Split(new char[]{' '},StringSplitOptions.RemoveEmptyEntries);

            string xin = "";
            while ((xin = Console.ReadLine()) != "0")
            {
                double n = double.Parse(xin);
                string[] data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                double x = double.Parse(data[0]);
                double y = double.Parse(data[1]);

                while (true)
                {
                    double division = n / 3.0;
                    // if is inside the center white square
                    
                    if (x > division && x < n - division && y > division && y < n - division)
                    {
                        double d1 = ABS(Math.Min(ABS(y - division), ABS(x - division)));
                        double d2 = ABS(Math.Min(ABS(y - (n-division)), ABS(x -(n- division))));
                        Console.WriteLine("{0:0.000000}", Math.Min(d1,d2));
                        break;
                    }
                    else if (x == division || x == n - division || y == division || y == n - division)
                    {
                        Console.WriteLine("{0:0.000000}", 0);
                        break;
                    }

                    // Relocating X
                    if (x > division && x < n - division)
                        x = x - division;
                    else if (x > n - division)
                        x = x - 2 * division;

                    // Relocating Y
                    if (y > division && y < n - division)
                        y = y - division;
                    else if (y > n - division)
                        y = y - 2 * division;

                    n = division;

                    //Console.WriteLine ("{0}",n);
                }

            }
            
            
            Console.Out.Close();
            Console.SetIn (tr);
            Console.SetOut(tw);
            Console.ReadLine();
        }

        public static double EuclideanDistance(double x1, double y1, double x2, double y2)
        {
            return Math.Sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        }

        static double ABS(double a)
        {
            if (a < 0)
                a *= -1;
            return a;
        }

        static int ABS(int a)
        {
            if (a < 0)
                a *= -1;
            return a;
        }

        static void PrintMt(int[,] mt)
        {
            for (int i = 0; i < mt.GetLength(0); i++)
            {
                for (int j = 0; j < mt.GetLength(1); j++)
                {
                    Console.Write(mt[i, j] + " ");
                }
                Console.WriteLine();
            }
        }


    }

    class Pair
    {
        public int x, y;
        public Pair(int x, int y)
        {
            this.x = x;
            this.y = y;
        }

        public override string ToString()
        {
            return string.Format("[{0} , {1}]", x, y);
        }

    }

    class Point
    {
        public double x, y;
        public Point(double x, double y)
        {
            this.x = x;
            this.y = y;
        }

        public override string ToString()
        {
            return string.Format("{0} {1}", x, y);
        }

        public double EuclidDistance(Point p1)
        {
            double dist = Math.Sqrt((this.x - p1.x) * (this.x - p1.x) + (this.y - p1.y) * (this.y - p1.y));
            return dist;
        }

    }

}