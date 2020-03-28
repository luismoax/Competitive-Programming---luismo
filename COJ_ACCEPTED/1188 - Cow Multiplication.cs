using System;
using System.Collections.Generic;

using System.Text;

namespace ConsoleApplication1
{ 
    class Program
    {
        static void Main(string[] args)
        {
           string[] p = Console.ReadLine().Split(' ');
            long suma = 0;
            for (int c = 0; c < p[0].Length; c++)
            {
                for (int d = 0; d < p[1].Length; d++)
                {
                    suma += int.Parse(p[0][c].ToString()) * int.Parse(p[1][d].ToString());
                }
            }
            Console.WriteLine(suma);
            
        }
        

    }    
}