using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            //StreamReader sr = new StreamReader(@"d:\in.lmo");
            string[] p = Console.ReadLine().Split(' ');
            char[,] mt = new char[p[1].Length, p[0].Length];
            int ai=0, bj=0;
            for (int i = 0; i < p[0].Length; i++)
            {
                if (p[1].Contains(p[0][i].ToString()))
                {
                    ai = i;
                    bj = p[1].IndexOf(p[0][i]);
                    break;
                }

            }
            //Poniendo letras
            for (int i = 0; i < mt.GetLength(0); i++)
            {
                for (int j = 0; j < mt.GetLength(1); j++)
                {
                    mt[i, j] = '.';
                }
            }


            for (int i = 0; i < p[0].Length; i++)
            {
                mt[bj, i] = p[0][i];
            }
            for (int i = 0; i < p[1].Length; i++)
            {
                mt[i, ai] = p[1][i];
            }

            for (int i = 0; i < mt.GetLength(0); i++)
            {
                for (int j = 0; j < mt.GetLength(1); j++)
                {
                    Console.Write(mt[i,j]);                    
                }
                Console.WriteLine();
            }

            Console.ReadLine();
        }

    }
}
