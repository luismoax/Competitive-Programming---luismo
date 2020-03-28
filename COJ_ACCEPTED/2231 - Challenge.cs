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
          Problem: 2231 - Challenge
          Online Judge: COJ
          Idea: Easy Ad-Hoc          
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
            int n = int.Parse(Console.ReadLine());
            int acnt = 0,bcnt=0;

            for (int i = 0; i < n; i++)
            {
                string[] data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                int k = Compare(data[0], data[1]);
                if (k > 0)
                    acnt++;
                else if(k < 0)
                    bcnt++;
            }

            if (acnt > bcnt)
                Console.WriteLine("A win");
            else if(bcnt > acnt)
                Console.WriteLine("B win");
            else Console.WriteLine("tied");


        }

        static int Compare(string a, string b)
        {
            if (a == b)
                return 0;

            if (a == "rock")
            {
                if (b == "scissors")
                    return 1;
                if (b == "paper")
                    return -1;
            }
            else if (a == "paper")
            {
                if (b == "rock")
                    return 1;
                if (b == "scissors")
                    return -1;
            }
            else
            {
                if (b == "paper")
                    return 1;
                if (b == "rock")
                    return -1;
            }

            return 0;
        }

    }    

}
