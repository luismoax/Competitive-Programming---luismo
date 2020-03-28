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
            int[] arr = new int[p.Length];
            for (int i = 0; i < p.Length; i++)
            {
                arr[i] = int.Parse(p[i]);
            }

            Array.Sort(arr);
            double[] areas = new double[arr.Length];
            for (int i = 0; i < areas.Length; i++)
            {
                areas[i] = Math.PI * arr[i] * arr[i]; 
            }
            double greenArea = areas[areas.Length - 1];
            for (int i = areas.Length-2; i >=0; i--)
            {
                if ((areas.Length - 1 - i) % 2 == 1)
                    greenArea -= areas[i];
                else greenArea += areas[i];
            }
            Console.WriteLine("{0:f4}",greenArea);
            Console.ReadLine();
        }

    }
}
