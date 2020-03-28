using System;
using System.Collections.Generic;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            //1181 Bee
            string xin = Console.ReadLine();
            while (xin!="-1")
            {
                int m = 0;
                int f = 1;
                for (int i = 0; i < int.Parse(xin); i++)
                {
                    int kf = m + 1;
                    int km = m + f;
                    
                    f = kf;
                    m = km;
                }
                Console.WriteLine(m +" "+ (m+f));
                xin = Console.ReadLine();
            }

            Console.ReadLine();
        }

    }
}
