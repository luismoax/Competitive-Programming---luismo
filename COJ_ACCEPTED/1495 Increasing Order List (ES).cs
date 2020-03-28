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
            int[] p = new int[tc];
            for (int c = 0; c < tc; c++)
            {
                p[c] = int.Parse(Console.ReadLine());
            }

            for (int c = 0; c < p.Length; c++)
            {
                for (int d = 0; d < p.Length; d++)
                {
                    if (p[d] > p[c])
                    {
                        int ax = p[d];
                        p[d] = p[c];
                        p[c] = ax;
                    }
                }
            }
            foreach (int var in p)
            {
                Console.WriteLine(var);                    
            }


            Console.ReadLine();
        }

        
    }
}
