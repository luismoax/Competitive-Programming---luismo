using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace COJ
{
    class Program
    {
        
        static void Main(string[] args)
        {
            //TextReader tr = Console.In;
            //Console.SetIn(new StreamReader(@"d:\lmo.in"));
            //string[] data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            
            
            string xin = "";
            while (!string.IsNullOrEmpty(xin = Console.ReadLine()))
            {
                int n = int.Parse(Console.ReadLine());
                for (int i = 0; i < n; i++)
                {
                    string aux = Console.ReadLine();
                    if (aux.Length < 4 || !aux.Contains(xin[4]))
                        Console.WriteLine("{0} is invalid", aux);
                    else
                    {
                        bool[] arr = new bool[xin.Length];
                        int k = aux.Length;
                        for (int j = 0; j < aux.Length; j++)
                        {
                            for (int c = 0; c < arr.Length; c++)
                            {
                                if (xin[c] == aux[j] && !arr[c])
                                {
                                    arr[c] = true;
                                    k--;
                                    break;
                                }
                            }
                        }
                        if(k==0)
                            Console.WriteLine("{0} is valid",aux);
                        else Console.WriteLine("{0} is invalid", aux);
                    }
                }
            }
            

            

            //Console.SetIn(tr);
            Console.ReadLine();
        }


        
        static int ABS(int a)
        {
            if (a < 0)
                a *= -1;
            return a;
        }

        static void PrintMt(int[,] mt)
        {
            for (int i = 0; i < mt.GetLength(0); i++)
            {
                for (int j = 0; j < mt.GetLength(1); j++)
                {
                    Console.Write(mt[i, j] + " ");
                }
                Console.WriteLine();
            }
        }


    }


}