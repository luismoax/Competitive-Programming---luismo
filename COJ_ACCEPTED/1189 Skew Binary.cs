using System;
using System.Collections.Generic;
using System.Text;

namespace COJ
{
    class Program
    {
        static void Main(string[] args)
        {
            string xin = Console.ReadLine();
            while (xin != "0")
            {
                int k = 0;
                for (int i = 0; i < xin.Length; i++)
                {
                    int ax = int.Parse(xin[xin.Length - 1 - i].ToString());
                    k += ax * (int)(Math.Pow(2, i + 1) - 1);
                }
                Console.WriteLine(k);
                xin = Console.ReadLine();
            }

            Console.ReadLine();
        }
    }
}
