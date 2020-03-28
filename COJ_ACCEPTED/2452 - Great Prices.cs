using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Collections;
using System.Globalization;
// good one
//using C = System.Console;

namespace COJ
{
    class MainClass
    {
        /// <summary>
        /// Author: Luismo
        /// Idea:
        /// </summary>
        /// <param name="args"></param>
        public static void Main(string[] args)
        {
            
            TextReader tr = Console.In;
            //Console.SetIn(new StreamReader(@"d:\lmo.in"));

            SolveSingleProblem();

            Console.SetIn(tr);
            Console.ReadLine();
        }


        static void SolveSingleProblem()
        {
            int tc = int.Parse(Console.ReadLine());
            for (int t = 0; t < tc; t++)
            {
                Dictionary<long, double> map = new Dictionary<long, double>();
                int itm = int.Parse(Console.ReadLine());
                for (int i = 0; i < itm; i++)
                {
                    string[] data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                    long k = long.Parse(data[0]);
                    double v = double.Parse(data[1]);

                    if (map.ContainsKey(k))
                    {
                        if (map[k] > v)
                            map[k] = v;
                    }
                    else map.Add(k, v);
                }
                double sum = 0;

                foreach (var item in map)
                {
                    sum += item.Value;    
                }
                Console.WriteLine("{0:f2}",sum);
            }

        }

        static int NumberOfOnes(int n)
        {
            int cnt = 0;
            while (n > 0)
            {
                cnt += (n % 2);
                n /= 2;
            }
            return cnt;
        }

        static bool IsPrime(int n)
        {
            if (n == 2 || n == 3)
                return true;
            if (n % 2 == 0 || n < 2)
                return false;

            for (int i = 3; i * i <= n; i += 2)
            {
                if (n % i == 0)
                    return false;
            }
            return true;
        }

        static int Min(int a, int b)
        {
            return (a < b) ? a : b;
        }

    }


    class FenwickTree
    {
        int[] arr;
        public FenwickTree(int n)
        {
            this.arr = new int[n + 1];
        }

        public void Update(int idx,int k)
        {
            for (int i = idx; i < arr.Length; i+= i&-i)			
                arr[i] += k;
        }

        public long Retrieve(int idx)
        {
            long sum = 0;
            for (int i = idx; i > 0; i-= i&-i)            
                sum += arr[i];
            return sum;
        }
    }



    class Point : IComparable<Point>
    {
        public double x, y;
        public Point(double x, double y)
        {
            this.x = x;
            this.y = y;
        }

        public double EuclideanDistance(Point other)
        {
            return Math.Sqrt
                (
                    (this.x - other.x) * (this.x - other.x) + (this.y - other.y) * (this.y - other.y)
                );
        }

        public int CompareTo(Point other)
        {
            if (this.x == other.x)
                return this.y.CompareTo(other.y);
            return this.x.CompareTo(other.x);
        }
    }

    class PointComparerY : IComparer<Point>
    {
        public int Compare(Point x, Point y)
        {
            if (x.y.CompareTo(y.y) == 0)
                return x.x.CompareTo(y.x);
            else return x.y.CompareTo(y.y);
        }
    }

}
