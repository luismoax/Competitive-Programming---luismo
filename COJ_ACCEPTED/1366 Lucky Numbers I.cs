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
            //1366 Lucky Numbers I
            List<long> luckyNumbers = new List<long>();
            luckyNumbers.Add(5);
            int power = 2;
            for (int i = 1; i < 8000; i++)
            {
                luckyNumbers.Add((long)Math.Pow(5, power));
                int lim = luckyNumbers.Count - 1;
                for (int c = 0; c < lim; c++)
                {
                    luckyNumbers.Add(luckyNumbers[c]+luckyNumbers[lim]);
                }
                power++;
                i = luckyNumbers.Count;
            }

            int tc = int.Parse(Console.ReadLine());
            for (int c = 0; c < tc; c++)
            {
                Console.WriteLine(luckyNumbers[int.Parse(Console.ReadLine()) - 1]);
            }
            
            Console.ReadLine();
        }

    }
}
