using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            int tc = int.Parse(Console.ReadLine());
            double d = 0;
            int adev = 0;
            for (int c = 1; c <= tc; c++)
            {
                double x = double.Parse(Console.ReadLine());
                if (x >= d)
                {
                    d = x;
                    adev = c;
                }
            }
            Console.WriteLine(adev);
            Console.ReadLine();
        }
    }
}
