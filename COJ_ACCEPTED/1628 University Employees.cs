using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {        
		//1628 University Employees
        static void Main(string[] args)
        {
            for (int i = 0; i < 1000; i++)
            {
                string[] p = Console.ReadLine().Split(' ');
                long l1 = long.Parse(p[0]);
                long l2 = long.Parse(p[1]);
                Console.WriteLine(l1+l2);
            }
            
            
            Console.ReadLine();
        }       

    }
}
