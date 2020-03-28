using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        //1663 Error Correction
        static void Main(string[] args)
        {  
            string xin = Console.ReadLine();
            while (xin !="0")
            {
                int n = int.Parse(xin);
                int[] sumaFilas = new int[n];
                int[] sumaColumnas = new int[n];

                //Leo y guardo los valores de la suma
                for (int c = 0; c < n; c++)
                {
                    string[] p = Console.ReadLine().Split(' ');
                    for (int d = 0; d < n; d++)
                    {
                        int xx = int.Parse(p[d]);
                        sumaFilas[c] += xx;
                        sumaColumnas[d] += xx;
                    }
                }
                bool b = true;
                int filaImpar = -1;
                int columnaImpar = -1;
                for (int c = 0; c < n; c++)
                {
                    if (sumaFilas[c] % 2 == 1 && filaImpar != -1) {b = false; break;}
                    else if (sumaFilas[c] % 2 == 1) filaImpar = c;

                    if (sumaColumnas[c] % 2 == 1 && columnaImpar != -1) { b = false; break; }
                    else if (sumaColumnas[c] % 2 == 1) columnaImpar = c;                    
                }
                if (!b) Console.WriteLine("Corrupt");
                else if ((filaImpar == -1 && columnaImpar != -1) || (filaImpar != -1 && columnaImpar == 1)) Console.WriteLine("Corrupt");
                else if (filaImpar == -1 && columnaImpar == -1) Console.WriteLine("OK");
                else Console.WriteLine("Change bit ({0},{1})",filaImpar+1,columnaImpar+1);

                xin = Console.ReadLine();
            }

            Console.ReadLine();
        }

    }

}

