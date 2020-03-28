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
            int min = int.Parse(p[0]);
            int max = int.Parse(p[0]);
            int cnt = 0;
            for (int i = 1; i < p.Length; i++)
            {
                int k = int.Parse(p[i]);
                if (k < min)
                {
                    min = k;
                    cnt++;
                }
                else if (k > max)
                {
                    max = k;
                    cnt++;
                }
            }
            Console.WriteLine(cnt);

            Console.ReadLine();
        }

    }
}
