using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace COJ
{
    class Program
    {
        //1283 Pole Position
        static void Main(string[] args)
        {
            string xin = "";
            while ((xin = Console.ReadLine()) !="0")
            {
                int n = int.Parse(xin);
                int[] c = new int[n];//numero del carro
                int[] p = new int[n];//Posiciones ganadas o perdidas
                //Leyendo
                for (int i = 0; i < n; i++)
                {
                    string[] ax = Console.ReadLine().Split(' ');
                    c[i] = int.Parse(ax[0]);
                    p[i] = int.Parse(ax[1]);
                }

                bool reconstruible = true; //para saber si es recontruible
                //para representar la matriz inicial
                int[] initialGrid = new int[n];
                //Vamos recontruyendo
                for (int i = 0; i < n; i++)
                {
                    int posInic = i + p[i];
                    //Si esta fuera de rango devuelvo -1 y salgo
                    //O si en esta posicion ya hay un carro
                    if (posInic < 0 || posInic > n - 1 || initialGrid[posInic] != 0)
                    {
                        reconstruible = false;
                        break;
                    }
                    //Sino lo coloco ahi
                    initialGrid[posInic] = c[i];
                }
                if (!reconstruible) Console.WriteLine("-1");
                else
                {
                    for (int i = 0; i < n; i++)
                    {
                        if (i == 0) Console.Write(initialGrid[i]);
                        else Console.Write(" "+initialGrid[i]);
                    }
                    Console.WriteLine();
                }
                
            }

            Console.ReadLine();
        }

    }

}