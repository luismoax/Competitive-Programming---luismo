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
         
         Author: Luis Manuel Díaz Barón (LUISMO)
         Problem: 1500 - An Express Taxi
         Online Judge: COJ
         Idea: Dynamic.
         
        */

        static void Main(string[] args)
        {
            TextReader tr = Console.In;
            // Console.SetIn(new StreamReader(@"d:\lmo.in"));

            SolveSingleProblem();

            Console.SetIn(tr);
            Console.ReadLine();
            //string[] data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
        }


        // static variables        

        // solution

        static void SolveSingleProblem()
        {
            string[] data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);

            // prices per distances
            int[] distancesPrices = new int[10];
            for (int i = 0; i < data.Length; i++)
                distancesPrices[i] = int.Parse(data[i]);

            // distance to cover
            int toCover = int.Parse(Console.ReadLine());

            // array to store dynamic values
            // dyn stores for the i-th kilometer the cheapest way to get there
            int[] dyn = new int[toCover + 1];
            for (int i = 1; i < dyn.Length; i++)
                dyn[i] = -1;

            // pi[i] stores what distance was the last picked to get to distance i
            int[] pi = new int[dyn.Length];
            // stores the minimun amount of tickets to get with the cheapest to distance i
            int[] ticketsAmount = new int[dyn.Length];

            // 
            for (int i = 1; i < dyn.Length; i++)
            {
                for (int j = 0; j < distancesPrices.Length && i >= j + 1; j++)
                {
                    // if a cheaper way can be achived using the distance (j + 1) to get to distance i, or none has been achieved yet
                    if (dyn[i - (j + 1)] + distancesPrices[j] < dyn[i] || dyn[i] == -1)
                    {
                        dyn[i] = dyn[i - (j + 1)] + distancesPrices[j];

                        ticketsAmount[i] = ticketsAmount[i - (j + 1)] + 1;

                        pi[i] = (j + 1);
                    }
                    // if there is a way as cheap as the cheapest one to get to distance i
                    else if (dyn[i - (j + 1)] + distancesPrices[j] == dyn[i])
                    {
                        // if can be achieved with less tickets , pick this one
                        if (ticketsAmount[i - (j + 1)] + 1 < ticketsAmount[i])
                        {
                            dyn[i] = dyn[i - (j + 1)] + distancesPrices[j];

                            ticketsAmount[i] = ticketsAmount[i - (j + 1)] + 1;

                            pi[i] = (j + 1);
                        }
                    }
                }

            }

            int[] kms = new int[10];

            int idx = dyn.Length - 1;
            while (idx > 0)
            {
                kms[pi[idx] - 1]++;
                idx -= pi[idx];
            }

            for (int i = 0; i < kms.Length; i++)
            {
                for (int j = 0; j < kms[i]; j++)
                {
                    Console.WriteLine("{0} {1}", i + 1, distancesPrices[i]);
                }
            }

            Console.WriteLine(dyn[dyn.Length - 1]);
        }


        #region Helpers
        static int Abs(int x)
        {
            return (x < 0) ? x * -1 : x;
        }

        static int Min(int a, int b)
        {
            return (a < b) ? a : b;
        }

        static int Max(int a, int b)
        {
            return (a > b) ? a : b;
        }

        static void PrintArr<T>(T[] arr)
        {
            for (int i = 0; i < arr.Length; i++)
            {
                if (i == 0)
                    Console.Write(arr[i].ToString());
                else Console.Write(" " + arr[i].ToString());
            }
        }
        #endregion

    }



}
