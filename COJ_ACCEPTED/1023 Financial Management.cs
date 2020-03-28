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
            double amount = 0;
            for (int c = 0; c < 12; c++)
            {
                amount += double.Parse(Console.ReadLine());
            }
            amount = amount / 12;
            string s = amount.ToString();            
            Console.Write("$");
            Console.WriteLine("{0:f2}", s);

            Console.ReadLine();
        }
    }
}
