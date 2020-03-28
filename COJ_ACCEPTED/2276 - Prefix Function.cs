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
         * Author: Luis Manuel Díaz Barón (LUISMO)
         * Problem: 2276 - Prefix Function
         * Online Judge: COJ
         * Idea: Use the prefix function of KMP and a cumulative sum table for the value of the strings.
         * 
         * */


        static void Main(string[] args)
        {
            TextReader tr = Console.In;
            // Console.SetIn(new StreamReader(@"d:\lmo.in"));

            SolveSingleProblem();
            
            Console.SetIn(tr);
            Console.ReadLine();

            //string[] data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
        }
                
        static void SolveSingleProblem()
        {
            int tc = int.Parse(Console.ReadLine());
            for (int t = 0; t < tc; t++)
            {
                string text = Console.ReadLine();
                int[] sums = new int[text.Length + 1];
                for (int i = 1; i < sums.Length; i++)
                {
                    sums[i] = sums[i - 1] + ( (IsVowel(text[i - 1])) ? 5 : 3 );
                }

                // maximun of the function
                int max = 0;

                // Finding Prefix-Function (Knuth Morris Pratt)
                int cnt = 0; // number of matched characters
                int[] table = new int[text.Length];

                for (int i = 1; i < table.Length; i++)
                {
                    // while having matched at least 1 char
                    // and can't be foud a greater sufix that is also prefix
                    // shift to the next sufix that is also prefix of the current
                    // prefix
                    while (cnt > 0 && text[cnt] != text[i])
                        cnt = table[cnt - 1];

                    // if a match  is foud the number of matched chars increases
                    if (text[cnt] == text[i])
                        cnt++;

                    // updating the table
                    table[i] = cnt;

                    // updating the maximmun value
                    if (cnt > 0)
                    {
                        int aux = sums[cnt] - sums[0];
                        if (aux > max)
                            max = aux;
                    }
                }

                Console.WriteLine(max);

            }
        }

        #region Auxiliar Methods
        static int Max(int a, int b)
        {
            return (a > b) ? a : b;
        }

        static int Min(int a, int b)
        {
            return (a < b) ? a : b;
        }

        static void Swap(ref int a, ref int b)
        {
            int tmp = a;
            a = b;
            b = tmp;
        }

        static bool IsVowel(Char c)
        {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        }
        #endregion
        
    }

}