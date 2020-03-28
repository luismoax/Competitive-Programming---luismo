/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3125 - Oktalni
    Online Judge: COJ
    Idea: Easy Ad-Hoc
*/

using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CompetitiveProgramming
{
    class Program
    {
        static void Main(string[] args)
        {
            TextReader tr = Console.In;
            //Console.SetIn(new StreamReader(@"e:\lmo.in"));

            Dictionary<string, string> dict = new Dictionary<string, string>();
            dict.Add("000", "0");
            dict.Add("001", "1");
            dict.Add("010", "2");
            dict.Add("011", "3");
            dict.Add("100", "4");
            dict.Add("101", "5");
            dict.Add("110", "6");
            dict.Add("111", "7");

            string str = Console.ReadLine();

            while (str.Length % 3 != 0)
                str = "0" + str; 

            string answ = "";

            for (int i = 0; i < str.Length; i+= 3)
            {
                answ+= dict[str.Substring(i,3)];
            }

            Console.WriteLine(answ);
            
            Console.SetIn(tr);
            Console.ReadLine();
        }
    }
}