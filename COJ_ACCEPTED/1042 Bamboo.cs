using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            int tc = int.Parse(Console.ReadLine());
            double total = 0;
            for (int i = 0; i < tc; i++)
            {
                string[] p = Console.ReadLine().Split(' ');
                double h = double.Parse(p[0]);
                double d = double.Parse(p[1]);
                double x1 = (d * d + h * h) / (2 * h);
                Console.WriteLine("{0:f1}", h - x1);
                total += h - x1;
            }
            Console.WriteLine("{0:f1}",total/tc);

            Console.ReadLine();
        }
    }
}
