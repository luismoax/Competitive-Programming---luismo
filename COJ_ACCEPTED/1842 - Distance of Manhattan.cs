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
            for (int t = 0; t < tc; t++)
            {
                string []p = Console.ReadLine().Split(' ');
                int x1 =int.Parse(p[0]);
                int y1 = int.Parse(p[1]);
                int x2 = int.Parse(p[2]);
                int y2 = int.Parse(p[3]);

                Console.WriteLine(Math.Abs(x1-x2) + Math.Abs(y1-y2));
                
            }

            Console.ReadLine();

        }
    }
}
