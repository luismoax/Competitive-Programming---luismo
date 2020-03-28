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
            for (int c = 0; c < tc; c++)
            {
                string s = ToBinary(long.Parse(Console.ReadLine()));
                int x = 0;
                for (int d = s.Length-1; d >=0; d--)
                {
                    if (s[d].ToString() == "1") break;
                    x++;
                }
                Console.WriteLine(Math.Pow(2,x));
            }
            Console.ReadLine();
        }



        static string ToBinary(long n)
        {
            string s = "";
            while (n > 0)
            {
                s = (n % 2) + s;
                n = n / 2;
            }
            return s;
        }
    }
}
