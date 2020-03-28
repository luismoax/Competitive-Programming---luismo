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
        /// Idea: Search for the positive root of the polinomial K^2 + K - 2*n = 0
        /// there, you'll find if n is a triangular number or not. 
        /// If positive, then it will lay on a cell on the form [K,1] if K is even
        /// or in a cell of the form [1,K] if K odd.
        /// If negative then figure out how will be moved the number n in the stair, by the
        /// fact of parity of K
        /// </summary>
        /// <param name="args"></param>
        /// 

        static long[] prod;
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
            string xin = "";
            while ((xin = Console.ReadLine()) != "0")
            {
                ulong n = ulong.Parse(xin);

                ulong sqrtD = (ulong)Math.Sqrt(1 + 8 * n);

                ulong k = (sqrtD - 1) / 2;
                ulong tri = (k * (k + 1)) / 2;
                // if is triangular
                if (tri == n)
                {
                    if (k % 2 == 0)
                        Console.WriteLine("{0} 1", k);
                    else Console.WriteLine("1 {0}", k);
                }
                // if not triangular
                else
                {

                    if (k % 2 == 0)
                    {
                        ulong kidx = k + 1;
                        kidx -= n - tri - 1;
                        Console.WriteLine("{0} {1}", kidx, n - tri);
                    }
                    else
                    {
                        ulong kidx = k + 1;
                        kidx -= n - tri - 1;

                        Console.WriteLine("{0} {1}", n - tri, kidx);
                    }
                }

            }

        }

    }

}
