using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace COJ
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = Console.ReadLine();
            while (s != "-1")
            {
                Console.WriteLine(ToTernary(int.Parse(s)));
                s = Console.ReadLine();
            }
            Console.ReadLine();
        }        

        static string ToTernary(int n)
        {
            if (n == 0) return "0";
            string s = "";
            while (n>0)
            {
                s= (n%3)+s;
                n = n / 3;
            }
            return s;
        }

    }

}
