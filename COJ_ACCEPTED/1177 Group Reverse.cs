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
            string input = Console.ReadLine();
            while (input!="0")
            {
                string[] p = input.Split(' ');
                string adev = "";
                string ax = "";
                for (int c = 0; c < p[1].Length; c++)
                {
                    ax = p[1][c] + ax;
                    if ((c+1) % (p[1].Length / int.Parse(p[0])) == 0)
                    {
                        adev += ax;
                        ax = "";
                    }                    
                }
                adev += ax;
                Console.WriteLine(adev);
                input = Console.ReadLine();
            }
            Console.ReadLine();
        }
    }
}
