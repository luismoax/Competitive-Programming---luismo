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
            //StreamReader sr = new StreamReader(@"C:\Documents and Settings\Info\Escritorio\serial.txt");

            int tc = int.Parse( Console.ReadLine());
            Console.WriteLine("Lumberjacks:");
            for (int k = 0; k < tc; k++)
            {
                string[] p = Console.ReadLine().Split(' ');
                bool incDec = true;
                bool decInc = true;
                for (int c = 0; c < p.Length-1; c++)
                {
                    if (int.Parse(p[c]) > int.Parse(p[c + 1])) { incDec = false; break; }
                }
                for (int c = 0; c < p.Length - 1; c++)
                {
                    if (int.Parse(p[c]) < int.Parse(p[c + 1])) { decInc = false; break; }
                }
                if (!decInc && !incDec) Console.WriteLine("Unordered");
                else Console.WriteLine("Ordered");
            }

            Console.ReadLine();
        }


    }
}
