using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

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
                Console.WriteLine(LastDigitOf(int.Parse(p[0]), int.Parse(p[1])));
            }
            Console.ReadLine();
        }

        static int LastDigitOf(int a, int b)
        {
            if (b == 0) return 1;            
            if (b % 2 == 0)
            {
                int x = LastDigitOf(a, b / 2);
                return (x * x) % 10;
            }
            else
            {
                int x = LastDigitOf(a, (b - 1) / 2);
                return (((x * x) % 10) * (a % 10))%10;
            }
        }
    }
}
