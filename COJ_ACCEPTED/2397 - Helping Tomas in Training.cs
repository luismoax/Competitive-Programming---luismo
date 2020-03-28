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
        /// Idea: Simple Use of the classes DateTime and TimeSpan
        /// </summary>
        /// <param name="args"></param>
        public static void Main(string[] args)
        {
            //string[] data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
   

            TextReader tr = Console.In;
            Console.SetIn(new StreamReader(@"d:\lmo.in"));

            SolveSingleProblem();

            Console.SetIn(tr);
            Console.ReadLine();
        }


        static void SolveSingleProblem()
        {
            int n = int.Parse(Console.ReadLine());
            for (int i = 0; i < n; i++)
            {
                string[] data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                
                string[] dtstr = data[0].Split('-');
                DateTime dt1 = new DateTime(int.Parse(dtstr[0]), int.Parse(dtstr[1]), int.Parse(dtstr[2]));
                
                dtstr = data[1].Split('-');
                DateTime dt2 = new DateTime(int.Parse(dtstr[0]), int.Parse(dtstr[1]), int.Parse(dtstr[2]));

                TimeSpan ts = dt2.Subtract(dt1);

                Console.WriteLine( Abs( ts.Days ));
            }

        }

        static int Abs(int x)
        {
            return (x < 0) ? -1 * x : x;
        }

    }

}
