using System;
using System.Collections.Generic;

namespace ConsoleApplication1
{ 
    class Program
    {
        static void Main(string[] args)
        {
		int numberOFCases = int.Parse(Console.ReadLine());
            string[] s = new string[numberOFCases];
            for (int i = 0; i < numberOFCases; i++)
            {
                //Leo la cantidad de numero
                long[] CantEvenODD = new long[3];
                CantEvenODD[0] = int.Parse(Console.ReadLine());
                string[] p = Console.ReadLine().Split(' ');
                foreach (string item in p)
                {
                    if (long.Parse(item) % 2 == 0) CantEvenODD[1]++;
                    else CantEvenODD[2]++;
                }
                s[i] =CantEvenODD[1]+ " even and " + CantEvenODD[2] + " odd.";
            }
            foreach (string str in s)
            {
                Console.WriteLine(str);
            }
		
		
        }
				
    }
	
}