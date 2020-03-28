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
                int x = int.Parse(Console.ReadLine());

                int sum = 0;
                for (int i = 1; i <= Math.Sqrt(x); i++)
                {
                    if (x % i == 0)
                    {
                        sum += i;
                        if (i != 1 && i != x / i) sum += x / i;
                    }
                }
                if (sum < x) Console.WriteLine("Deficient");
                else if (sum > x) Console.WriteLine("Abundant");
                else Console.WriteLine("Perfect");

            }
            Console.ReadLine();
        }
    }
}
