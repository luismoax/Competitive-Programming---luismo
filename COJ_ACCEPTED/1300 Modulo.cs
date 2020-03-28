using System;
using System.Collections.Generic;
using System.Text;

namespace COJ
{
    class Program
    {
        static void Main(string[] args)
        {
            //r2 = 2*S- r1
            string[] p = Console.ReadLine().Split(' ');
            Console.WriteLine(2*int.Parse(p[1]) - int.Parse(p[0]));


            Console.ReadLine();
        }
    }
}
