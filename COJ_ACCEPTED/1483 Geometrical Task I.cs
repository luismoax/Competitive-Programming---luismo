using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] p = Console.ReadLine().Split(' ');

            if (p[0] == "rectangle") Console.WriteLine(int.Parse(p[1])*int.Parse(p[2]));
            else Console.WriteLine(int.Parse(p[1])*int.Parse(p[1]));
            Console.ReadLine();
        }
    }
}
