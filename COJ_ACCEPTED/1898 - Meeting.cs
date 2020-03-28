using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace COJ
{
    class Program
    {
		//1898 - Meeting
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            for (int i = 0; i < n; i++)
            {
                string[] p = Console.ReadLine().Split(' ');
                double a = double.Parse(p[0]), b = double.Parse(p[1]), d = double.Parse(p[2]);
                
                Console.WriteLine("{0:f4}",Math.Round( d/(a+b),4));
            }

            Console.ReadLine();
        }


    }

}
