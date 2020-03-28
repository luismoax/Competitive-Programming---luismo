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
            //1629 Common Permutation
            string xin = Console.ReadLine();
            while (xin != null)
            {
                string a = xin;
                string b = Console.ReadLine();
                List<char> lst = new List<char>(Math.Min(a.Length, b.Length));

                bool[] aArray = new bool[a.Length];
                bool[] bArray = new bool[b.Length];
                for (int c = 0; c < a.Length; c++)
                {
                    for (int d = 0; d < b.Length; d++)
                    {
                        if (!bArray[d] && !aArray[c] && b[d] == a[c])
                        {
                            lst.Add(b[d]);
                            bArray[d] = true;
                            aArray[c] = true;
                        }
                    }
                }

                lst.Sort();
                foreach (char item in lst)
                {
                    Console.Write(item);
                }
                Console.WriteLine();
                xin = Console.ReadLine();
            }
            Console.ReadLine();
        }

    }


}
