using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace COJ
{
    class Program
    {        
        static void Main(string[] args)
        {
            int tc = int.Parse(Console.ReadLine());
            for (int i = 0; i < tc; i++)
            {
                string[] p = Console.ReadLine().Split(' ');
                int n = int.Parse(p[0]);
                int m = int.Parse(p[1]);

                if (n == m && n % 2 == 0) Console.WriteLine("L");
                else if (n == m && n % 2 == 1) Console.WriteLine("R");

                else if (n > m && n % 2 == 0 && m%2 ==1) Console.WriteLine("D");
                else if (n > m && n % 2 == 1 && m%2 ==0) Console.WriteLine("U");

                else if (n < m && n % 2 == 0 && m%2 == 1) Console.WriteLine("L");
                else if (n < m && n % 2 == 1 && m%2 ==0) Console.WriteLine("R");

                else if (n > m && n % 2 == 0 && m % 2 == 0) Console.WriteLine("U");
                else if (n > m && n % 2 == 1 && m % 2 == 1) Console.WriteLine("D");

                else if (n < m && n % 2 == 0 && m % 2 == 0) Console.WriteLine("L");
                else if (n < m && n % 2 == 1 && m % 2 == 1) Console.WriteLine("R");
            }
			
            Console.ReadLine();
        }



    }


}
