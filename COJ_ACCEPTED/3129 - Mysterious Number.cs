/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3129 - Mysterious Number
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
            Console.SetIn(new StreamReader(@"e:\lmo.in"));

            int tc = int.Parse(Console.ReadLine());

            while (tc-- > 0)
            {
                string[] data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);

                int N = int.Parse(data[0]);
                string trick = data[1];
                int P = int.Parse(data[2]);

                if (trick == "odd")                
                    Console.WriteLine(P << 1);
                else Console.WriteLine((P << 1) - 1);
            }

            
            Console.SetIn(tr);
            Console.ReadLine();
        }
    }
}
