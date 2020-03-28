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
          Problem: 1201 - Select Your Ropes
          Online Judge: COJ
          Idea: Easy, sorting... 
		  
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

        // static variables        

        static void SolveSingleProblem()
        {
            int tc = int.Parse(Console.ReadLine());
            for (int t = 0; t < tc; t++)
            {
                int n = int.Parse(Console.ReadLine());
                string[] data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                List<int> ropes = new List<int>(n);
                for (int i = 0; i < data.Length; i++)
                {
                    ropes.Add(int.Parse(data[i]));
                }

                // Sort
                ropes.Sort();

                int max = ropes[ropes.Count - 1];

                int idx = 2;
                int amount = max;
                for (int i = ropes.Count - 2; i >= 0; i-- , idx ++)
                {
                    // amount+=ropes[i];
                    if (idx * ropes[i] > max)
                    {
                        max = idx * ropes[i];
                    }
                }

                Console.WriteLine(max);
            }

        }

    }

}
