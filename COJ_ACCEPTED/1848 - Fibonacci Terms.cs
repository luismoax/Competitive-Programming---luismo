using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace COJ
{
    class Program
    {
		//1848 Fibbonacci Terms		
        static void Main(string[] args)
        {
            int[] fibb = new int[10000];
            fibb[0] = 1;
            fibb[1] = 1;
            //Generamos los fibbonacis
            for (int i = 2; i < fibb.Length; i++)
            {
                fibb[i] = (fibb[i - 1] + fibb[i - 2]) % 10000;
            }

            
            int tc = int.Parse(Console.ReadLine());
            for (int t = 0; t < tc; t++)
            {
                int n = int.Parse(Console.ReadLine());

                if (n == 1) Console.WriteLine("0 0 1");
                else if (n == 2) Console.WriteLine("0 1 1");
                else Console.WriteLine("{0} {1} {2}",fibb[n-3],fibb[n-2],fibb[n-1]);
            }

            Console.ReadLine();
        }

    }

}
