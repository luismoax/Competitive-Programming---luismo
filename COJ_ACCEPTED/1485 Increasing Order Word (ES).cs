using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            string k = Console.ReadLine();
            char[] p = new char[k.Length];
            for (int c = 0; c < k.Length; c++)
            {
                p[c] = k[c];
            }

            for (int c = 0; c < p.Length; c++)
            {
                for (int d = 0; d < p.Length; d++)
                {
                    if (p[d] > p[c])
                    {
                        char ax = p[d];
                        p[d] = p[c];
                        p[c] = ax;
                    }
                }
            }
            foreach (char var in p)
            {
                Console.Write(var);
            }


            Console.ReadLine();
        }

    }
}
