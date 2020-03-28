using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace COJ
{
    class Program
    {
        //1374 The Hotel
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[,] mt = new int[n, n];
            int cnt = 1;
            for (int i = n-1; i >= 0; i--)
            {
                int fil = 0;
                int col = i;
                while (fil<n && col <n)
                {
                    mt[fil, col] = cnt;
                    fil++;
                    col++;
                    cnt++;
                }                
            }

            for (int i = 1; i < n; i++)
            {
                int fil = i;
                int col = 0;
                while (fil < n && col < n)
                {
                    mt[fil, col] = cnt;
                    fil++;
                    col++;
                    cnt++;
                }        
            }

            //Imprimiendo la Matriz
            for (int i = 0; i < mt.GetLength(0); i++)
            {
                for (int j = 0; j < mt.GetLength(1); j++)
                {
                    if(j==0)
                        Console.Write(mt[i, j]);
                    else Console.Write(" "+mt[i, j]);
                }
                Console.WriteLine();
            }

            Console.ReadLine();
        }
        

    }

}