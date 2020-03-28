using System;
using System.Collections.Generic;
using System.Text;

namespace COJ
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            string[] p = Console.ReadLine().Split(' ');
            int [] arr = new int[n];
            for (int i = 0; i < p.Length; i++)
            {
                int k = int.Parse(p[i]);
                arr[k - 1] = i + 1;
            }

            for (int i = 0; i < arr.Length; i++)
            {
                if (i == 0) Console.Write(arr[i]);
                else Console.Write(" "+arr[i]);
            }

            Console.ReadLine();
        }

    }
}
