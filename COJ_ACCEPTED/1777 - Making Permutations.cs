using System;
using System.Collections.Generic;
using System.Text;

namespace COJ
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            string[] p = Console.ReadLine().Split(' ');
            bool[] arrB = new bool[p.Length];
            int cnt = 0;
            for (int i = 0; i < p.Length; i++)
            {
                long k = long.Parse(p[i]);
                if (k <= arrB.Length && !arrB[k - 1])
                {
                    arrB[k - 1] = true;
                }
                else cnt++;
            }
            Console.WriteLine(cnt);

            Console.ReadLine();
        }

    }
}
