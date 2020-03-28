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
            //1621 Frames
            string xin = Console.ReadLine();
            while (xin!=null)
            {
                int n = int.Parse(xin);
                string[] p = Console.ReadLine().Split(' ');
                int[] arr = new int[p.Length];
                for (int c = 0; c < p.Length; c++)
                {
                    arr[c] = int.Parse(p[c]);
                }
                Array.Sort(arr);
                int pr = 1;
                int pairs=0;
                for (int c = 1; c < arr.Length; c++)
                {
                    if (pr == 1 && arr[c] == arr[c - 1]) { pairs++; pr = 0; }
                    else if (pr == 0) pr = 1;
                }
                Console.WriteLine(pairs/2);
                xin = Console.ReadLine();
            }
            Console.ReadLine();
        }

    }
}
