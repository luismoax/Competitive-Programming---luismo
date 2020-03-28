using System;
using System.Collections.Generic;
using System.Text;
using System.IO;


namespace ConsoleApplication1
{
    class Program
    {
        static int total = 0;
        static void Main(string[] args)
        {
            int tc = int.Parse(Console.ReadLine());
            for (int i = 0; i < tc; i++)
            {
                string n = Console.ReadLine();
                string k = Console.ReadLine();
                total = 0;
                Ssecuence(n, k, 0, 0);
                Console.WriteLine(total);
            }
            
            Console.ReadLine();
        }

        static void Ssecuence(string n, string k, int indexn, int indexk)
        {
            //Caso Base
            if (indexk == k.Length)
            {
                total++;
                return;
            }

            for (int i = indexn; i < n.Length; i++)
            {
                if (k[indexk] == n[i])
                {
                    Ssecuence(n, k, i + 1, indexk + 1);
                }
            }
        }
    }

}

