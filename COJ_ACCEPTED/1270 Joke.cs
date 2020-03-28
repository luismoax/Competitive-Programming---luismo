using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace COJ
{
    class Program
    {
        static int[] di;
        static void Main(string[] args)
        {
            string[] p = Console.ReadLine().Split(' ');
            decimal x = decimal.Parse(p[0]);
            decimal y = decimal.Parse(p[1]);

            decimal d = x / y;

            Console.WriteLine(Math.Floor(d));
            Console.ReadLine();
        }

    }

    


}
