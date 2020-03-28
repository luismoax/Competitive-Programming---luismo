using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Collections;
using System.Globalization;
// good one
//using C = System.Console;

namespace COJ
{
    class MainClass
    {
        /// <summary>
        /// Author: Luismo
        /// Idea:
        /// </summary>
        /// <param name="args"></param>
        public static void Main(string[] args)
        {
            
            TextReader tr = Console.In;
            //Console.SetIn(new StreamReader(@"d:\lmo.in"));

            SolveSingleProblem();

            Console.SetIn(tr);
            Console.ReadLine();
        }


        static void SolveSingleProblem()
        {
            int n = int.Parse(Console.ReadLine());
            int[] arr = new int[n];
            string[] data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            for (int i = 0; i < arr.Length; i++)
            {
                arr[i] = int.Parse(data[i]);
            }
            // reading queries
            int q = int.Parse(Console.ReadLine());
            int[] queries = new int[q];
            data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            for (int c = 0; c < queries.Length; c++)
            {
                queries[c] = int.Parse(data[c]);
                int k = queries[c];
                
                // factor descomposition
                List<int> descomposition = new List<int>();
                  
                while (k % 2 == 0)
                {
                    descomposition.Add(2);
                    k /= 2;
                }
                
                for (int i = 3; i <= k; i+=2)
                {                    
                    while (k % i == 0)
                    {
                        descomposition.Add(i);
                        k /= i;
                    }                    
                }
                // descomposition ended

                int[] aux = new int[n];
                for (int i = 0; i < n; i++)
                {
                    aux[i] = arr[i];
                }

                bool flag = true;
                for (int i = 0; i < descomposition.Count; i++)
                {
                    flag = false;
                    for (int j = 0; j < aux.Length; j++)
                    {
                        if (aux[j] % descomposition[i] == 0)
                        {
                            aux[j] /= descomposition[i];
                            flag = true;
                            break;
                        }
                    }
                    if (!flag)
                        break;
                }


                if(flag)
                    Console.WriteLine("YES");
                else Console.WriteLine("NO");


            }

        }


    }

}
