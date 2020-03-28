using System;
using System.Collections.Generic;
using System.Collections;
using System.Linq;

namespace ConsoleApp
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int tc = int.Parse(Console.ReadLine());
            for (int t = 0; t < tc; t++)
            {
                Dictionary<string, int> dictionary = new Dictionary<string, int>();
                int f = int.Parse(Console.ReadLine());
                List<string[]> relations = new List<string[]>();
                for (int i = 0; i < f; i++)
                {
                    string[] names = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                    if (!dictionary.ContainsKey(names[0]))
                    {
                        dictionary.Add(names[0], dictionary.Keys.Count);
                    }

                    if (!dictionary.ContainsKey(names[1]))
                    {
                        dictionary.Add(names[1], dictionary.Keys.Count);
                    }
                    relations.Add(names);
                }

                //Creo el DisjoinSet
                DisjoinSet ds = new DisjoinSet(dictionary.Keys.Count);
                for (int i = 0; i < relations.Count; i++)
                {
                    int k1 = dictionary[relations[i][0]];
                    int k2 = dictionary[relations[i][1]];

                    ds.Merge(k1, k2);
                }
            }

            Console.ReadLine();
        }

    }

    class DisjoinSet
    {
        long[] pi;
        
        public DisjoinSet(int n)
        {
            this.pi = new long[n];
            for (int i = 0; i < pi.Length; i++)
                pi[i] = -1;
        }

        public long SetOf(int i)
        {
            long k = i;
            while (pi[k] >= 0)
            {
                k = pi[k];
            }
            return k;
        }

        public void Merge(int i, int j)
        {
            long ki = SetOf(i);
            long kj = SetOf(j);

            if (ki == kj)
            {
                Console.WriteLine(pi[ki] * -1);
                return;
            }
            else Console.WriteLine((pi[kj] + pi[ki]) * -1);

            //Padre ki tiene mas peso que kj
            if (ki < kj)
            {
                pi[ki] += pi[kj];
                pi[kj] = ki;
            }
            else
            {
                pi[kj] += pi[ki];
                pi[ki] = kj;
            }
        }
    }

}
