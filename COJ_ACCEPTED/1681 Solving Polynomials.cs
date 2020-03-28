using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] p = Console.ReadLine().Split(' ');
            int a = int.Parse(p[0]);
            int b = int.Parse(p[1]);
            int c = int.Parse(p[2]);

            if ((b * b - 4 * a * c) >= 0) Console.WriteLine("YES");
            else Console.WriteLine("NO");

        }
    }
}
