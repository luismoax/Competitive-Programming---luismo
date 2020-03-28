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
            //1610 Hubulullu
            int tc = int.Parse(Console.ReadLine());
            string[] players = {"Airborne", "Pagfloyd" };
            for (int c = 0; c < tc; c++)
            {
                string[] p = Console.ReadLine().Split(' ');
                int ax = int.Parse(p[1]);
                Console.WriteLine("{0} wins.",players[ax]);
            }
            Console.ReadLine();
        }
        
    }

}
