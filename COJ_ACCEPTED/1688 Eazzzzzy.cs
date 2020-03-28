using System;
using System.Collections.Generic;
using System.Text;

namespace COJ
{
    class Program
    {
        static void Main(string[] args)
        {
            string xin = Console.ReadLine();
            //bool b = false;
            while (xin != "-1")
            {
                int c = int.Parse(xin);
                string[] p = Console.ReadLine().Split(' ');

                //  if (b) Console.WriteLine();
                // b = true;

                if (c == 1)
                {
                    DrawTriangle(int.Parse(p[0]));
                }
                else if (c == 2)
                {
                    DrawParalelogram(int.Parse(p[0]), int.Parse(p[1]));
                }
                else
                {
                    DrawRectangle(int.Parse(p[0]), int.Parse(p[1]));
                }
                Console.WriteLine();
                xin = Console.ReadLine();
            }

            Console.ReadLine();
        }

        static void DrawTriangle(int h)
        {
            int b = 2 * h - 1;
            //Pintamos los niveles
            for (int i = 1; i <= h; i++)
            {                
                for (int j = 0; j < b/2+i; j++)
                {
                    if (j > b / 2 -i )
                        Console.Write("*");
                    else Console.Write(" ");
                }                
                Console.WriteLine();
            }
        }

        static void DrawRectangle(int w, int h)
        {
            for (int i = 0; i < h; i++)
            {
                for (int j = 0; j < w; j++)
                {
                    Console.Write("*");
                }
                Console.WriteLine();
            }
        }

        static void DrawParalelogram(int w, int h)
        {
            for (int i = 0; i < h; i++)
            {                
                for (int j = 1; j < h - i + w; j++)
                {
                    if (j < h - i) Console.Write(" ");
                    else Console.Write("*");
                }                
                Console.WriteLine();
            }
        }

    }
}

