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
			//1539 Code Number
            int tc = int.Parse(Console.ReadLine());
            for (int c = 0; c < tc; c++)
            {
                string xin = Console.ReadLine();
                while (xin != null && xin != "")
                {
                    string[] p = xin.Split(' ');
                    for (int i = 0; i < p.Length; i++)
                    {
                        for (int j = 0; j < p[i].Length; j++)
                        {
                            Console.Write(Decode(p[i][j], j == 0));
                        }
                        if (i != p.Length - 1) Console.Write(' ');
                    }
                    Console.WriteLine();
                    xin = Console.ReadLine();
                }
                Console.WriteLine();
            }

            Console.ReadLine();
        }

        static char Decode(char c, bool beginning)
        {
            switch (c)
            {
                case '1':
                    return 'I';
                case '2':
                    return 'Z';                    
                case '3':
                    return 'E';
                case '4':
                    return 'A';
                case '5':
                    return 'S';
                case '6':
                    return 'G';
                case '7':
                    return 'T';
                case '8':
                    return 'B';
                case '9':
                    return 'P';
                case '0':
                    return 'O';
                default:
                    return c;
            }
            return c;
        }

    }
}
