using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            //1598 Determination of Series
            string xin = Console.ReadLine();            
            while (xin != null)
            {
                string[] p = xin.Split(' ');
                int f0 = int.Parse(p[0]);
                int f1 = int.Parse(p[1]);
                int f2 = int.Parse(p[2]);

                int B = (4 * f1 - 3 * f0 - f2)/2;
                int A = f1 - f0 - B;
                int C = f0;

                int f3 = A * 9 + B * 3 + C;
                int f4 = A * 16 + B * 4 + C;
                int f5 = A * 25 + B * 5 + C;
                                
                Console.WriteLine("{0} {1} {2}",f3,f4,f5);
                xin = Console.ReadLine();
            }
            Console.ReadLine();
        }

    }
}
