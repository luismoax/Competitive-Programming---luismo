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
         * Problem: 2250 - Substring Frequency
         * Online Judge: COJ
         * Idea: KMP classic use
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
                KnuthMorrisPratt kmp = new KnuthMorrisPratt(Console.ReadLine());
                Console.WriteLine("Case {0}: {1}",t+1,kmp.MatchingIndexes(Console.ReadLine()).Count);
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
        #endregion
        
    }


    class KnuthMorrisPratt
    {
        string text;

        public KnuthMorrisPratt(string text)
        {
            this.text = text;
        }

        public List<int> MatchingIndexes(string pattern)
        {
            List<int> indexes = new List<int>();

            int[] table = PartialMatchTable(pattern);

            int q = 0; // numer of characters matched

            for (int i = 0; i < text.Length; i++)
            {
                // while no matching
                // scan for the next possible preffix - suffix
                while (q > 0 && pattern[q] != text[i])
                {
                    q = table[q - 1];
                }

                if (pattern[q] == text[i])
                    q++;

                if (q == pattern.Length)
                {
                    indexes.Add(i - pattern.Length + 1);
                    q = table[q - 1];
                }
            }

            return indexes;
        }

        int[] PartialMatchTable(string pattern)
        {
            // 0-based index
            int[] table = new int[pattern.Length];

            int k = 0; // number of currently matched characters

            // foreach position in table
            for (int i = 1; i < pattern.Length; i++)
            {
                // while amount is greater than 0
                // and no matching foud
                while (k > 0 && pattern[k] != pattern[i])
                {
                    // k will be the next greater match for a
                    // prefix of length less than the previos one
                    k = table[k - 1];
                }
                // if match found
                if (pattern[i] == pattern[k])
                {
                    k++;
                }

                table[i] = k;
            }
            // return the prefix table
            return table;
        }

    }

}
