using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            int k = int.Parse(Console.ReadLine());
            int cs = 1;
            while (k != 0)
            {
                long afd = 1;
                for (int i = 2; i <= k; i++)
                {
                    afd += i * i;                    
                }
                Console.WriteLine("Case {0}:", cs);
                Console.WriteLine("n = {0}, diamonds = {1}",k,afd);
                cs++;
                k = int.Parse(Console.ReadLine());
            }

            Console.ReadLine();
        }
    }
}
