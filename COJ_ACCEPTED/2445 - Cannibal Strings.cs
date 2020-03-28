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
         * Author: Luismo
		 * Problem: 2445 - Cannibal Strings
		 * Online Judge: COJ
         * Idea: Easy Ad-Hoc with strings
         * 
         * */


        static void Main(string[] args)
        {
            //string[] data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            TextReader tr = Console.In;
            Console.SetIn(new StreamReader(@"d:\lmo.in"));

            SolveSingleProblem();

            Console.SetIn(tr);
            Console.ReadLine();
        }


        // static variables        
        static void SolveSingleProblem()
        {
            string str = Console.ReadLine();
            char cannibal = str[0];
            char current = str[0];
            int max = 0; int best = 0;

            for (int i = 1; i < str.Length; i++)
            {
                if (Char.IsUpper(current) && (Char.IsLower(str[i]) || current > str[i]))
                    max++;
                else if (Char.IsLower(current) && (Char.IsLower(str[i]) && current > str[i]))
                    max++;
                else
                {                    
                    if (max > best)
                    {
                        best = max;
                        cannibal = current;
                    }
                    current = str[i];
                }
            }

            Console.WriteLine(cannibal);
        }

        #region Helpers
        static int Abs(int x)
        {
            return (x < 0) ? x * -1 : x;
        }

        static int Min(int a, int b)
        {
            return (a < b) ? a : b;
        }

        static int Max(int a, int b)
        {
            return (a > b) ? a : b;
        }
        #endregion
        
    }

    

}
