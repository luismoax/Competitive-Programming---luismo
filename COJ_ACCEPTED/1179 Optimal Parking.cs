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
            //1179 Optimal Parking
            int tc = int.Parse(Console.ReadLine());
            for (int c = 0; c < tc; c++)
            {
                int n = int.Parse(Console.ReadLine());
                string[] p = Console.ReadLine().Split(' ');
                int[] arr = new int[n];
                for (int i = 0; i < p.Length; i++)
                {
                    arr[i] = int.Parse(p[i]);
                }
                Array.Sort(arr);
                int mn = 2 * (arr[arr.Length - 1] - arr[0]);
                for (int i = 1; i < arr.Length; i++)
                {
                    int dt = 2 * (arr[i] - arr[0]) + 2 * (arr[arr.Length - 1] - arr[i]);
                    if (dt < mn) mn = dt;
                }
                Console.WriteLine(mn);
            }
            
                      
            Console.ReadLine();
        }

    }
}
