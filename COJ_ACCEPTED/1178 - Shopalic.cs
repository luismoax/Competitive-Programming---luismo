using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace COJ
{
    class Program
    {   
        static void Main(string[] args)
       {
            TextReader tr = Console.In;
            //Console.SetIn(new StreamReader(@"f:\in.lmo"));
            
            int tc = int.Parse(Console.ReadLine());
            for (int t = 0; t < tc; t++)
            {
                int n = int.Parse(Console.ReadLine());
                string[] data = Console.ReadLine().Split(new char [] {' '});
                int[] arr = new int[data.Length];
                for (int i = 0; i < data.Length; i++)
                    arr[i] = int.Parse(data[i]);
                Array.Sort(arr);
                int cost = 0;
                for (int i = 2; i < arr.Length; i+=3)
                {
                    cost += arr[arr.Length-1-i];
                }
                Console.WriteLine(cost);
            }
            Console.SetIn(tr);
            Console.ReadLine();
        }
    }
}
