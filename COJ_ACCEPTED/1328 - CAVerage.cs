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


            int tc = int.Parse(Console.ReadLine());
            for (int i = 0; i < tc; i++)
            {
                double totalSum = 0;
                int children = int.Parse(Console.ReadLine());
                int[] notes = new int[children];
                for (int j = 0; j < 2 * children; j++)
                {
                    int k = int.Parse(Console.ReadLine());
                    notes[j % children] += k;
                    totalSum += k;
                }

                totalSum = totalSum / children;
                int r = 0;

                for (int j = 0; j < notes.Length; j++)
                {
                    if (notes[j] < totalSum) r++;
                }
                Console.WriteLine(r);
            }

            Console.ReadLine();
        }
    }
}
