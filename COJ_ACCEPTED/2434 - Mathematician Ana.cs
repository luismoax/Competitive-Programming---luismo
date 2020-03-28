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
            /// Idea: Pre-calculate products
            /// </summary>
            /// <param name="args"></param>
            /// 

            static long[] prod;
            public static void Main(string[] args)
            {
                //string[] data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);

                //Console.WriteLine(long.MaxValue +"\n"+ Math.Pow(10,15));
                TextReader tr = Console.In;
                //Console.SetIn(new StreamReader(@"d:\lmo.in"));

                SolveSingleProblem();

                Console.SetIn(tr);
                Console.ReadLine();
            }

            static bool IsPrime(int n)
            {
                if (n == 2 || n == 3)
                    return true;
                if (n % 2 == 0)
                    return false;
                for (int i = 3; i*i <= n; i+=2)
                {
                    if (n % i == 0)
                        return false;
                }
                return true;
            }

            static void SolveSingleProblem()
            {
                prod = new long[51];
                prod[2] = 2;
                for (int i = 3; i <= 50; i++)
                {
                    if (IsPrime(i))
                        prod[i] = prod[i - 1] * i;
                    else prod[i] = prod[i - 1];
                }


                string xin = "";
                while ((xin = Console.ReadLine())!="0")
                {
                    int k = int.Parse(xin);
                    Console.WriteLine(prod[k]);
                }

            }

        }


        class FenwickTree
        {
            int[] arr;
            public FenwickTree(int n)
            {
                this.arr = new int[n + 1];
            }

            public void Update(int idx, int k)
            {
                for (int i = idx; i < arr.Length; i += i & -i)
                    arr[i] += k;
            }

            public long Retrieve(int idx)
            {
                long sum = 0;
                for (int i = idx; i > 0; i -= i & -i)
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
