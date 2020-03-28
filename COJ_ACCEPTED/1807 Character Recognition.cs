using System;
using System.Collections.Generic;
using System.Text;
using System.IO;


namespace COJ
{
    class Program
    {
        static void Main(string[] args)
        {

            //Radio = R/A;
            string xin = "";
            int tc = int.Parse(Console.ReadLine());
            for (int t = 0; t < tc; t++)
            {
                double r = 0;
                double a = 0;
                xin = Console.ReadLine();
                while (xin != "" && xin != null)
                {
                    a += xin.Length;
                    for (int i = 0; i < xin.Length; i++)
                    {
                        if (xin[i] != '#')
                            r++;
                    }
                    xin = Console.ReadLine();
                }
                double percent = r * 100 / a;
                if (Math.Floor(percent) == percent)
                    Console.WriteLine("Efficiency ratio is {0}%.",Math.Round( percent));
                else Console.WriteLine("Efficiency ratio is {0}%.", Math.Round(percent,1));
            }

            Console.ReadLine();
        }

    }

}