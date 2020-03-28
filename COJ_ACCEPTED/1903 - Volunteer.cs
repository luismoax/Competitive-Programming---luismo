using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Linq;

namespace COJ
{
    class Program
    {
        /*
        
        */
        static void Main(string[] args)
        {
            //StreamReader sr = new StreamReader(@"d:\in.lmo");
            
            int tc = int.Parse(Console.ReadLine());
            for (int t = 0; t < tc; t++)
            {
                string[] p = Console.ReadLine().Split(' ');
                int h = int.Parse(p[0]);
                int w = int.Parse(p[1]);

                int[,] mt = new int[h+1, w+1];
                //Leemos la matriz donde hay B pongo un 1
                //voy poniendo al final de c\fila o columna las cantidades de yerba
                for (int i = 0; i < h; i++)
                {
                    string xin = Console.ReadLine();
                    for (int j = 0; j < xin.Length; j++)
                    {
                        if (xin[j] == 'B')
                        {
                            mt[i, j] = 1;
                            mt[h, j]++;
                            mt[i, w]++;
                        }
                    }
                }
                Console.WriteLine(Mtd(mt));
            }
            Console.ReadLine();
        }

        static int Mtd(int[,] mt)
        {
            int filas = mt.GetLength(0);
            int columnas = mt.GetLength(1);
            int adev = 0;
            int[,] aux = new int[filas,columnas];
            int cnt = 0;

            //Cortando las filas enteras
            for (int i = 0; i < filas; i++)
            {
                bool b1 = false;
                for (int j = 0; j < columnas; j++)
                {
                    //copio los valores a la matriz auxiliar
                    aux[i,j] = mt[i,j];
                    if (mt[i, columnas - 1] == columnas-1)
                    {
                        mt[i, j] = 0;
                        b1 = true;
                    }
                }
                if (b1) cnt++;
            }
            //Cortando luego las columnas que donde queda yerba
            for (int i = 0; i < mt.GetLength(1)-1; i++)
            {   
                for (int j = 0; j < mt.GetLength(0)-1; j++)
                {
                    if (mt[j,i] == 1)
                    {
                        cnt++;
                        break;
                    }
                }
            }
            adev = cnt;

            mt = aux;
            //Cortamos las columnas primero
            cnt = 0;
            
            for (int i = 0; i < columnas; i++)
            {
                bool b1 = false;    
                for (int j = 0; j < filas; j++)
                {
                    //Si esta llena la columna
                    if (mt[filas - 1, i] == filas-1)
                    {
                        b1 = true;
                        mt[j, i] = 0;
                    }
                }
                if (b1) cnt++;
                    
            }
            //Recortando por las filas
            for (int i = 0; i < mt.GetLength(0)-1; i++)
            {
                for (int j = 0; j < mt.GetLength(1)-1; j++)
                {
                    if (mt[i, j] == 1)
                    {
                        cnt++;
                        break;
                    }
                }
            }
            if (cnt < adev)
                adev = cnt;
            
            return adev;
        }

    }

}
