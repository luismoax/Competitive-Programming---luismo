using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        //1631 Triple Fat Ladies
		static void Main(string[] args)
        {   
			int[] arr = { 192, 442, 692, 942 };

            int tc = int.Parse(Console.ReadLine());
            for (int c = 0; c < tc; c++)
            {
                ulong n = ulong.Parse(Console.ReadLine());
                if (n <= 4) Console.WriteLine(arr[n - 1]);
                else
                {
                    ulong k1 = n/4;
                    ulong k2 = n % 4;
                    if (k2 == 0) { k2 = 4;  k1--; };
                    Console.WriteLine((k1).ToString()+arr[k2-1]);
                }
            }

            Console.ReadLine();
        }
    }
}
