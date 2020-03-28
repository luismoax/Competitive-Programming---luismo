using System;
using System.Collections.Generic;

namespace ConsoleApplication1
{ 
    class Program
    {
        static void Main(string[] args)
        {
		
		            int n = int.Parse(Console.ReadLine());
            if (n >= 0)
                Console.WriteLine(n * (n + 1) / 2);
            else Console.WriteLine((-1) * (n * (n - 1) / 2) + 1);
		
		
        }
				
    }
	
}