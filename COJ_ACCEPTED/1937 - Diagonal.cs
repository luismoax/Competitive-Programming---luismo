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
            /// Idea: Easy Algebra Problem (root of a 2-grade polinomial)
            /// </summary>
            /// <param name="args"></param>
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


            static void SolveSingleProblem()
            {
                long n = long.Parse(Console.ReadLine());
                int cs=1;
                while (n!=0)
                {
                    double D = 9 + 8 * n;

                    double x1 = (3 + Math.Sqrt(D)) / 2;

                    Console.WriteLine("Case {0}: {1}",cs,Math.Ceiling(x1));

                    n = long.Parse(Console.ReadLine());
                    cs++;
                }
            }

        }

    }
