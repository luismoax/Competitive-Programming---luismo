using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace COJ
{
    class Program
    {
        /*
          Author: Luismo
          Problem: 1478 - Basic Edit Distance
          Online Judge: COJ
          Idea: Classic Edit Distance Problem
        */


        static void Main(string[] args)
        {
            TextReader tr = Console.In;
            TextWriter tw = Console.Out;

            // Console.SetIn(new StreamReader(@"d:\lmo.in"));

            SolveSingleProblem();


            Console.SetIn(tr);
            Console.SetOut(tw);
            Console.ReadLine();

            //string[] data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
        }

        static void SolveSingleProblem()
        {
            string first = Console.ReadLine();
            string second = Console.ReadLine();
            

            int[,] dyn = new int[first.Length + 1, second.Length + 1];

            for (int i = 0; i < first.Length + 1; i++)
                dyn[i, 0] = i;

            for (int i = 0; i < second.Length + 1; i++)
                dyn[0, i] = i;

            for (int i = 0; i < first.Length; i++)
            {
                for (int j = 0; j < second.Length; j++)
                {   
                    int min = Min(dyn[i, j], Min(dyn[i, j + 1], dyn[i + 1, j]));
                    if (first[i] == second[j])
                    {
                        dyn[i + 1, j + 1] = dyn[i,j];
                    }
                    else dyn[i + 1, j + 1] = min + 1;
                }
            }


            Console.WriteLine(dyn[first.Length, second .Length]);

        }

        private static void PrintMT(int[,] dyn)
        {
            for (int i = 0; i < dyn.GetLength(0); i++)
            {
                for (int j = 0; j < dyn.GetLength(1); j++)
                {
                    Console.Write(dyn[i, j] + " ");
                }
                Console.WriteLine();
            }
        }


        static int Min(int a, int b)
        {
            return (a < b) ? a : b;
        }

    }

}
