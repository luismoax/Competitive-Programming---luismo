using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Collections;
using System.Globalization;
//using System.Numerics;
// good one
//using C = System.Console;

namespace COJ
{
    class MainClass
    {
        /// <summary>
        /// Author: Luismo
        /// Idea: Easy. Simulate the number of sides for each level of the fractal
        /// </summary>
        /// <param name="args"></param>
        /// 

        public static void Main(string[] args)
        {
            //string[] data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);

            TextReader tr = Console.In;
            //Console.SetIn(new StreamReader(@"d:\lmo.in"));

            SolveSingleProblem();

            Console.SetIn(tr);
            Console.ReadLine();
        }

        static void SolveSingleProblem()
        {
            double epsilon = 0.9;
            int tc = int.Parse(Console.ReadLine());
            for (int t = 0; t < tc; t++)
            {
                string[] data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                double len = double.Parse(data[0]);
                double s = double.Parse(data[1]);

                
                List<long> sides = new List<long>();
                sides.Add(1);
                for (int i = 0; true; i++)
                {
                    double lenghtOfSides = len / Math.Pow(3, i); // lenght of every new side
                    long sd = sides[sides.Count - 1];
                    if (sd * lenghtOfSides == s)
                    {
                        Console.WriteLine(i);
                        break;
                    }
                    else if (sd * lenghtOfSides > s)
                    {
                        Console.WriteLine(i-1);
                        break;
                    }
                    sides.Add(sd * 3 + sd * 2);
                }
            }
        }


    }

}
