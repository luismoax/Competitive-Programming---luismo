using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        //1662 Run-Length Encoding-Decoding
        static void Main(string[] args)
        {
            int tc = int.Parse(Console.ReadLine());
            for (int c = 0; c < tc; c++)
            {
                string xin = Console.ReadLine();
                string adev = "";                
                for (int i = 0; i < xin.Length; i++)
                {
                    int afd = i + 1;
                    string nm = "";
                    while (afd < xin.Length && IsNumber(xin[afd]))
                    {
                        nm += xin[afd];
                        afd++;
                    }
                    
                    for (int fc = 0; fc <int.Parse( nm); fc++)
                    {
                        adev += xin[i];
                    }
                    i = afd - 1;
                }
                Console.WriteLine("Case {0}: {1}",c+1,adev);
            }
            Console.ReadLine();

        }

        static bool IsNumber(char c)
        {
            return c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '0';
        }

    }

}

