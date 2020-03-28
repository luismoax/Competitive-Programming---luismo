using System;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {            
            string s = Console.ReadLine();
            while (s!="0.00")
            {
                double ff = double.Parse(s);
                double ax = 0.5;
                int x = 3;
                int n = 1;
                while (ax<ff)
                {
                    ax += (double)1 / x;
                    x++;
                    n++;
                }
                Console.WriteLine(n + " card(s)");
                s = Console.ReadLine();
            }
            Console.ReadLine();
        }
    }
}
