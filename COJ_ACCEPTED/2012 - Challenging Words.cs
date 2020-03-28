using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Collections;
using System.Globalization;
using System.Linq;


namespace COJ
{
    class Program
    {
        /*
         * Author LUISMO
         * El problema se resume a contar el valor de c\palabra e ir llevando un máximo
         * junto con los índices donde se rinde este valor máximo
        */

        static void Main(string[] args)
        {
            TextReader tr = Console.In;
            //Console.SetIn(new StreamReader(@"d:\in.lmo"));


            string xin = "";
            List<int> bestIndexes = new List<int>();
            int bestValue = 0;
            char[] alfabet = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
            int index = 1;
            while ((xin = Console.ReadLine()) != null)
            {
                //xin.Split('k',StringSplitOptions.None);
                string[] data = xin.Split(new char []{ ' '}, StringSplitOptions.RemoveEmptyEntries);
                for (int nd = 0; nd < data.Length; nd++)
                {
                    int value = 0;
                    for (int i = 0; i < data[nd].Length; i++)
                    {
                        int k = Array.BinarySearch(alfabet, data[nd][i]);
                        if (k >= 0)
                            value += k;
                    }
                    if (value > bestValue)
                    {
                        bestIndexes.Clear();
                        bestIndexes.Add(index);
                        bestValue = value;
                    }
                    else if (value == bestValue)
                        bestIndexes.Add(index);

                    index++;
                }
            }
            Console.WriteLine(bestValue);
            foreach (var item in bestIndexes)
            {
                Console.WriteLine(item);
            }

            Console.SetIn(tr);
            Console.ReadLine();
        }

    }

}
