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
            //1630 He's offside!
            string xin = Console.ReadLine();
            while (xin!="0 0")
            {                                
                //Distancias de Atacantes                
                string[] p = Console.ReadLine().Split(' ');
                int nearestAttackerDistance = int.MaxValue;
                for (int c = 0; c < p.Length; c++)
                {
                    if (int.Parse(p[c]) < nearestAttackerDistance) nearestAttackerDistance = int.Parse(p[c]);
                }
                //Distancias de Defensas
                p = Console.ReadLine().Split(' ');
                int nearestDefenseDistance = Math.Min(int.Parse(p[0]), int.Parse(p[1]));
                int secondNearestDefenseDistance = Math.Max(int.Parse(p[0]), int.Parse(p[1]));
                for (int c = 2; c < p.Length; c++)
                {
                    if (int.Parse(p[c]) <= nearestDefenseDistance)
                    {
                        secondNearestDefenseDistance = nearestDefenseDistance;
                        nearestDefenseDistance = int.Parse(p[c]);
                    }
                    else if (int.Parse(p[c]) <= secondNearestDefenseDistance) secondNearestDefenseDistance = int.Parse(p[c]);
                }
                if (nearestAttackerDistance >= secondNearestDefenseDistance) Console.WriteLine("N");
                else Console.WriteLine("Y");
                xin = Console.ReadLine();
            }
            Console.ReadLine();
        }        

    }


}
