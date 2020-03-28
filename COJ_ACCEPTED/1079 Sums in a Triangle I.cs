using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {            
            int tc = int.Parse(Console.ReadLine());
            List<int> lst = new List<int>();
            for (int c = 0; c < tc; c++)
            {
                int dimension = int.Parse(Console.ReadLine());
                int[,] mt = new int[dimension, dimension];
                for (int i = 0; i < dimension; i++)
                {
                    string[] p = Console.ReadLine().Split(' ');
                    for (int j = 0; j < p.Length; j++)
                    {
                        mt[i, j] = int.Parse(p[j]); 
                    }
                }
                lst.Add(MaxSumTri(mt));
            }
            foreach (int item in lst)
            {
                Console.WriteLine(item);
            }

            Console.ReadLine();
        }


        static int MaxSumTri(int [,] mt)
        {
            for (int i = mt.GetLength(1)-1; i > 0; i--)
            {
                for (int c = 0; c < mt.GetLength(0)-1; c++)
                {
                    mt[i - 1, c] += Math.Max(mt[i, c], mt[i, c+1]);
                }
            }
            return mt[0, 0];
        }

    }
}
