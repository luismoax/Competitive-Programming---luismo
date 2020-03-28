using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace cp
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            long sm = 0;

            for (int i = 0; i < n; i++)
            {
                long x = long.Parse(Console.ReadLine());
                int k = 0;
                while (x > 0)
                {
                    if (x % 2 == 1)
                        k++;
                    x >>= 1;
                }
                sm += k;
            }
            Console.WriteLine(sm);



        }
    }
}
