using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace COJ
{
    class Program
    {
        //1875 - Analysis & Deftness (A&D)
        static void Main(string[] args)
        {
            int tc = int.Parse(Console.ReadLine());
            for (int t = 0; t < tc; t++)
            {
                double r = int.Parse(Console.ReadLine());
                double a = Math.Sqrt(r * r - (r / 2) * (r / 2));
                double atr = (r / 2 * a) / 2;
                atr *= 12;
                Console.WriteLine("{0:f2}",atr);

            }
            Console.ReadLine();
        }

    }
}
