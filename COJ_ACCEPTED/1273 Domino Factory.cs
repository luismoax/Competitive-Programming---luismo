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
            for (int c = 0; c < tc; c++)
            {
                string[] p = Console.ReadLine().Split(' ');
                Console.WriteLine((((int.Parse(p[0]) + 1) * (int.Parse(p[0]) + 2)) / 2) * (int.Parse(p[1]) * int.Parse(p[2])));
            }
            Console.ReadLine();
        }
    }
}
