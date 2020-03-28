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
         
         Author: Luis Manuel Díaz Barón (LUISMO)
         Problem: 1882 - Eight-Character Strings
         Online Judge: COJ
         Idea: Use a dictionary to store substrings with frequency
         
        */

        static void Main(string[] args)
        {            
            TextReader tr = Console.In;
            // Console.SetIn(new StreamReader(@"d:\lmo.in"));
            
            SolveSingleProblem();

            Console.SetIn(tr);
            Console.ReadLine();
            //string[] data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
        }


        // static variables        
        
        static void SolveSingleProblem()
        {
            string s = Console.ReadLine();
            // dictionary to store strings
            Dictionary<string, int> dict = new Dictionary<string, int>();
            // 
            int bestFrequency = 0;
            string bestString = "";

            for (int i = 0; i <= s.Length-8; i++)
            {
                string subStr = s.Substring(i, 8);
                if (dict.ContainsKey(subStr))
                {
                    int freq = ++dict[subStr];

                    if (freq > bestFrequency)
                    {
                        bestFrequency = freq;
                        bestString = subStr;
                    }
                    else if (freq == bestFrequency && subStr.CompareTo(bestString) < 0 )
                        bestString = subStr;
                }
                else dict.Add(subStr, 1);
            }

            
            if(bestFrequency > 1)
                Console.WriteLine(bestString);
            else Console.WriteLine("Solution was not found");
            
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
