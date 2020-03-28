using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace COJ
{
    class Program
    {
        static void Main(string[] args)
        {            
            int tc = int.Parse(Console.ReadLine());
            int[] rst = new int[tc];
            List<int> lst = new List<int>();

            for (int c = 0; c < tc; c++)
            {
                int totalAmount = int.Parse(Console.ReadLine());
                int numberOfTrans = int.Parse(Console.ReadLine());
                for (int d = 0; d < numberOfTrans; d++)
                {
                    string[] p = Console.ReadLine().Split(' ');
                    if (p[0] == "C") totalAmount += int.Parse(p[1]);
                    else totalAmount -= int.Parse(p[1]);
                }
                lst.Add(totalAmount);
            }
            foreach (int item in lst)
            {
                Console.WriteLine(item);
            }
            
            Console.ReadLine();
        }

    }
}
