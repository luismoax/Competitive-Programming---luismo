using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] a = Console.ReadLine().Split(' ');
            if (a[0] == "circle")
            {
                double d = double.Parse(a[1]);
                Console.WriteLine("{0:f2}", 3.14 * Math.Pow(d, 2));
            }
            else if (a[0] == "triangle")
            {
                double b = double.Parse(a[1]);
                double h = double.Parse(a[2]);
                Console.WriteLine("{0:f2}", b * h / 2);
            }
            else if (a[0] == "rhombus")
            {
                double d1 = double.Parse(a[1]);
                double d2 = double.Parse(a[2]);
                Console.WriteLine("{0:f2}", (d1 * d2) / 2);
            }

            Console.ReadLine();
        }
    }
}