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
            //1357 Being Late
            string xin = Console.ReadLine();
            while (xin!=null)
            {
                int sc = int.Parse(xin);
                int total = 0;
                for (int c = 0; c < sc; c++)
                {
                    string[] p = Console.ReadLine().Split(' ');
                    int dif = (int.Parse(p[2]) - int.Parse(p[0])) * 60 + (int.Parse(p[3]) - int.Parse(p[1]));
                    if (dif > 0) total += dif;
                }
                Console.WriteLine(total/sc);
                xin = Console.ReadLine();
            }


            Console.ReadLine();
        }


    }
}
