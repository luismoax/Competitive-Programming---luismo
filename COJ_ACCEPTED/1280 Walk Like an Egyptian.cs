using System;
using System.Collections.Generic;
using System.Text;

namespace COJ
{
    class Program
    {
        static void Main(string[] args)
        {
			//1280 Walk Like an Egyptian
            int[] arr = new int[1000];
            arr[0] = 1;
            arr[1] = 3;
            for (int i = 1; i < arr.Length; i++)
            {
                arr[i] = arr[i-1] + 2 * i ;
            }
            string xin = Console.ReadLine();
            while (xin!="0")
            {
                int ax = int.Parse(xin);
                Console.WriteLine(xin +" => "+arr[ax-1]);
                xin = Console.ReadLine();
            }

            Console.ReadLine();
        }
    }
}
