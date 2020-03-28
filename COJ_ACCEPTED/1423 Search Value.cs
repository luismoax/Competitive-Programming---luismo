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
            //1423 Search Value
            string xin = Console.ReadLine();
            while (xin!=null)
            {
                double d = double.Parse(xin);
                double answer = (d / 2) * Math.Sin(Math.PI/3);
                Console.WriteLine("{0:f6}",answer);
                xin = Console.ReadLine();
            }
            
            Console.ReadLine();
        }

    }
}
