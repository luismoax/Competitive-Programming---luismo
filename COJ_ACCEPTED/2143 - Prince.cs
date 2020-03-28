using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace COJ
{
    class Program
    {
        /*
         * Author: Luismo
         * Idea: KnapSack Problem at the face
         * 
         * */


        static void Main(string[] args)
        {
            TextReader tr = Console.In;
            //Console.SetIn(new StreamReader(@"d:\lmo.in"));

            SolveSingleProblem();
            
            Console.SetIn(tr);
            Console.ReadLine();

            //string[] data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
        }

        
        static void SolveSingleProblem()
        {
            int robberies = int.Parse(Console.ReadLine());
            int amount = 0;
            for (int t = 0; t < robberies; t++)
            {
                string[] data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                int n = int.Parse(data[0]);
                int m = int.Parse(data[1]);

                int[,] mt = new int[n+1, m+1];
                for (int i = 1; i <= n; i++)
                {
                    data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                    int wb = int.Parse(data[0]);
                    int cb = int.Parse(data[1]);

                    for (int k = 1; k < m+1; k++)
                    {
                        int aux1 = mt[i - 1, k];
                        int aux2 =  (k>=wb)? mt[i - 1, k - wb] + cb: 0;
                        mt[i, k] = Max(aux1, aux2);
                    }
                }

                amount += mt[n, m];
            }

            Console.WriteLine(amount);
        }

        static int Max(int a, int b)
        {
            return (a > b) ? a : b;
        }

    }


}
