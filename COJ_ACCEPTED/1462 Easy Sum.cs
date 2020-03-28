using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace COJ
{
    class Program
    {
        static void Main(string[] args)
        {
            int total = 0;
            int tc = int.Parse(Console.ReadLine());
            for (int c = 0; c < tc; c++)
            {
                string xinput = Console.ReadLine();
                string ax = "";
                for (int i = 0; i < 7; i++)
                {
                    if (xinput.Length - 1 - i >= 0)
                    {
                        ax = xinput[xinput.Length - 1 - i] + ax;
                    }
                    else break;
                }
                total += int.Parse(ax) % 128;
            }
            Console.WriteLine(total%128);
            Console.ReadLine();
        }

    }
}
