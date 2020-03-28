/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3267 - Anders And The Nephews
    Online Judge: COJ
    Idea: Easy Ad-Hoc
*/
using System;
using System.Collections.Generic;
using System.Collections;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CompetitiveProgramming
{
    class Program
    {
        static string str;
        static string[] data;
        static void Main(string[] args)
        {
            TextReader tr = Console.In;
            TextWriter tw = Console.Out;
            string pathIn = @"e:\lmo.in";
            string pathOut = @"e:\lmo.out";

            // Console.SetIn(new StreamReader(pathIn));
            // Console.SetOut(new StreamWriter(@"E:\tt.out"));
            //---------------------------------------------------------------

            SolveSingleProblem();
            //Console.Out.Close();
            //---------------------------------------------------------------
            Console.SetOut(tw);
            Console.SetIn(tr);
            Console.ReadLine();
        }

        private static void SolveSingleProblem()
        {
            str = Console.ReadLine();
            data = str.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);

            while (true)
            {
                int N = int.Parse(data[0]);
                int K = int.Parse(data[1]);

                if(K * 4 > N)
                    Console.WriteLine(-1);
                else Console.WriteLine(  K + ( (N - 4 * K) / 2 + (N - 4 * K) % 2   )    );

                str = Console.ReadLine();
                if (str == null) break;
                data = str.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            }
        }

        static int Max(int a, int b)
        {
            return (a > b) ? a : b;
        }

        static int Min(int a, int b)
        {
            return (a < b) ? a : b;
        }
    }
}