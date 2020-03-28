using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        
        static int maxCant = 0;
        static int H = 0;
        static void Main(string[] args)
        {
            long[] fb = new long[50];
            fb[0] = 1;
            fb[1] = 2;
            for (int i = 2; i < fb.Length; i++)
            {
                fb[i] = fb[i - 1] + fb[i - 2];
            }
            string xin = Console.ReadLine();
            while (xin!="0")
            {
                Console.WriteLine(fb[int.Parse(xin)-1]);
                xin = Console.ReadLine();
            }

        }

    }
}
