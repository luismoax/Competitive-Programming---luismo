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
            
            //1609 Sum Decomposition
            int tc = int.Parse(Console.ReadLine());
            for (int c = 0; c < tc; c++)
            {
                int n = int.Parse(Console.ReadLine());                
                PrintDescomposition(n);
                //En la ultima línea no se debe imprimir una línea en blanco
                if(c<tc-1) Console.WriteLine();
            }            
            
            Console.ReadLine();
        }

        static void PrintDescomposition(int n)
        {
            PrintDescomposition(n,1, n, "");
        }

        static void PrintDescomposition(int n,int digitToRest, int upon, string display)
        {
            if (upon == 0)
            {
                Console.WriteLine(n+" = "+display);
                return;
            }

            for (int i = digitToRest; i <= upon; i++)
            {
                string k = (string)display.Clone();
                if (k.Length > 0) k += " + " + i;
                else k += i;
                PrintDescomposition(n,i, upon - i, k);
            }

        }
    }
}
