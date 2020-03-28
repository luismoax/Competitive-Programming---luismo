using System;
using System.Collections.Generic;


namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {    
            //1439 Alaska
            string xin = Console.ReadLine();
            while (xin!="0")
            {
                int gasStations = int.Parse(xin);
                int[] gS = new int[gasStations];
                for (int i = 0; i < gasStations; i++)
                {
                    gS[i] = int.Parse(Console.ReadLine());
                }
                Array.Sort(gS);
                bool posible = true;
                for (int c = 0; c < gS.Length-1; c++)
                {
                    if (gS[c + 1] - gS[c] > 200) { posible = false; break; };
                }
                if (posible && 2 * (1422 - gS[gS.Length - 1]) > 200) posible = false;
                if (posible) Console.WriteLine("POSSIBLE");
                else Console.WriteLine("IMPOSSIBLE");

                xin = Console.ReadLine();
            }            
            
            Console.ReadLine();
        }

    }
}
