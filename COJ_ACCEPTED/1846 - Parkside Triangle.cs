using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace COJ
{
    class Program
    {
        //
        static void Main(string[] args)
        {
            string[] p = Console.ReadLine().Split(' ');
            int n = int.Parse(p[0]);
            int s = int.Parse(p[1]);

            int[,] mt = new int[n, n];
            //Seed
            int k = s;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j <= i; j++)
                {
                    mt[j, i] = k;
                    k = (k + 1) % 10;
                    if (k == 0)
                        k++;
                }
            }

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j <n; j++)
                {
                    if (mt[i, j] == 0)
                    {
                        if(j==0)
                            Console.Write(" ");
                        else Console.Write("  ");
                    }
                    else
                    {
                        if(j==0)
                            Console.Write(mt[i, j]);
                        else Console.Write(" "+mt[i,j]);
                    }
                }
                Console.WriteLine();
            }            
            Console.ReadLine();
        }



    }

}
