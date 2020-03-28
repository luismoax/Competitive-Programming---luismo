using System;
using System.Collections.Generic;

namespace ConsoleApplication1
{ 
    class Program
    {
        static void Main(string[] args)
        {
		
		int numberOfCases = int.Parse(Console.ReadLine());
            int[] pieces = { 1, 1, 2, 2, 2, 8 };
            int[] results = new int[6 * numberOfCases];
            int resindex = 0;
            for (int i = 0; i < numberOfCases; i++)
            {
                string[] p = Console.ReadLine().Split(' ');
                for (int c = 0; c < p.Length; c++)
                {
                    int res = pieces[c] - int.Parse(p[c]);
                    results[resindex] = res;
                    resindex++;
                }
            }
            for (int d = 0; d < results.Length; d++)
            {
                Console.Write(results[d]+" ");
                if (d > 1 && d % 6 == 5) Console.WriteLine();
            }
		
		
        }
				
    }
	
}