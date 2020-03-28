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
            
            string[] p = Console.ReadLine().Split(' ');
            int h = int.Parse(p[0]);
            int w = int.Parse(p[1]);

            bool b = false;
            string xin = "";
            double suma = 0;
            for (int i = 0; i < h; i++)
            {
                xin = Console.ReadLine();    
                for (int j = 0; j < xin.Length; j++)
                {
                    if (xin[j] == '\\' || xin[j] == '/')
                    {
                        suma += 0.5;
                        b = !b;
                    }
                    else
                    {
                        if (b) suma += 1;
                    }
                }
            }
            Console.WriteLine(suma);
            Console.ReadLine();
        }

    }

}
