using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace COJ
{
    class Program
    {
        static void Main(string[] args)
        {            
            int tc = int.Parse(Console.ReadLine());
            int[] rst = new int[tc];
            List<string> lst = new List<string>();
            
            for (int c = 0; c < tc; c++)
            {
                int dimension = int.Parse(Console.ReadLine());
                bool[,] mt = new bool[dimension, dimension];

                for (int i = 0; i < dimension; i++)
                {
                    string s = Console.ReadLine();
                    for (int j = 0; j < dimension; j++)
                    {
                        if (s[j] == '.')
                            mt[i, j] = true;
                        else mt[i, j] = false;
                    }
                }
                lst.Add(LarguestSqare(mt).ToString());
            }
            foreach (string item in lst)
            {
                Console.WriteLine(item);
            }
            
            Console.ReadLine();
        }

        static int LarguestSqare(bool[,] mt)
        {
            for (int c = mt.GetLength(0); c >= 0; c--)
            {
                for (int i = 0; i <= mt.GetLength(0)- c; i++)
                {
                    for (int j = 0; j <= mt.GetLength(1)-c; j++)
                    {
                        if (Check(mt, i, j, c))
                        {
                            return c;
                        }
                    }
                }
            }
            return 0;
        }

        static bool Check(bool[,] mt, int i, int j, int clargo)
        {
            for (int c = i; c < i+clargo; c++)
            {
                for (int d = j; d < j+clargo; d++)
                {
                    if (!mt[c, d]) return false;
                }
            }
            return true;
        }

    }
}
