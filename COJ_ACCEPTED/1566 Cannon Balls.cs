using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = Console.ReadLine();
            while (s != "0")
            {
                int sm = 0;
                for (int i = 1; i <= int.Parse(s); i++)
                {
                    sm += i * i;
                }
                Console.WriteLine(sm);
                s = Console.ReadLine();
            }

            Console.ReadLine();
        }
    }
}