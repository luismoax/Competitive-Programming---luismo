using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace COJ
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            for (int i = 0; i < n; i++)
            {
                string[] p = Console.ReadLine().Split(' ');
                double a = double.Parse(p[0]);
                double s = double.Parse(p[1]);

                double l = Math.Sqrt(0.25 * (s * s - 4 * a));
                Console.WriteLine("{0:f2}",l);
            }

            Console.ReadLine();
        }


    }

}
