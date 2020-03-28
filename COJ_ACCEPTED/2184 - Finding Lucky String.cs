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
         Problem: 2184 - Finding Lucky String
         Online Judge: COJ
         Idea: Easy, the solution can only be 4 or 7, the one of them with most frequency
         
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
            int tc = int.Parse(Console.ReadLine());
            while (tc-->0)
            {
                string number = Console.ReadLine();
                int four = 0;
                int seven = 0;
                for (int i = 0; i < number.Length; i++)
                {
                    if (number[i] == '4')
                        four++;
                    if (number[i] == '7')
                        seven++;
                }

                if(four ==0 && seven ==0)
                    Console.WriteLine(-1);
                else if(four > seven)
                    Console.WriteLine(4);
                else if (seven > four)
                    Console.WriteLine(7);
                else
                {
                    Console.WriteLine(4);
                }

            }
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
