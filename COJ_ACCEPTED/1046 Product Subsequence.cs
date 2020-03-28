using System;
using System.Collections.Generic;

using System.Text;

namespace COJ
{
    class Program
    {
        static void Main(string[] args)
        {
            int t = int.Parse(Console.ReadLine());
            int[] sol = new int[t];
            for (int c = 0; c < t; c++)
            {
                string[] p = Console.ReadLine().Split(' ');
                
                int sm = 0;
                for (int i = int.Parse(p[0]); i <= int.Parse(p[1]); i++)
                {
                    sm += i * (i + 1) * (i + 2);
                    sm = sm % 100;
                }
                sol[c] = sm;
            }
            foreach (int item in sol)
            {
                Console.WriteLine(item);
            }
            Console.ReadLine();
        }

        

        
    }
}
