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
            int smallestP = 0;
            for (int i = 0; i < tc; i++)
            {
                string[] p = Console.ReadLine().Split(' ');
                int a = int.Parse(p[0]);
                int b = int.Parse(p[1]);
                int c = int.Parse(p[2]);

                if (a < b + c && b < a + c && c < a + b)
                {
                    int per = a + b + c;
                    if (smallestP == 0 || per < smallestP) smallestP = per;
                }

            }
            Console.WriteLine(smallestP);

            Console.ReadLine();
        }
    }
}
