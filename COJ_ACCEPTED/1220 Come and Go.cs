using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        //1220 Come and Go
		static void Main(string[] args)
        {
            //StreamReader sr = new StreamReader(@"d:\PrOGrAmaCi”n\Taller\COJ\COJ\COJ\bin\Debug\in.lmo");
            string xin = Console.ReadLine();
            while (xin != "0 0")
            {
                string[] split = xin.Split(' ');
                int n = int.Parse(split[0]);
                int m = int.Parse(split[1]);
                bool[,] adyMt = new bool[n, n];

                //Leo las aristas
                for (int c = 0; c < m; c++)
                {
                    split = Console.ReadLine().Split(' ');
                    //Coloco la arista
                    int v = int.Parse(split[0]);
                    int w = int.Parse(split[1]);
                    int p = int.Parse(split[2]);

                    adyMt[v - 1, w - 1] = true;
                    //Si es de doble sentido coloco la arista inversa;
                    if (p == 2) adyMt[w - 1, v - 1] = true;

                }
                //Por c\ vertice  si en un dfs a partir de el no se visitan
                //todos los vertices entonces el grafo no es fuertemente conexo
                bool flag = true;
                for (int i = 0; i < n; i++)
                {
                    int cnt = 0;
                    DFSVisitados(adyMt, i, new bool[n],ref cnt);
                    if (cnt < n) { flag = false; break; }
                }
                if (flag) Console.WriteLine(1);
                else Console.WriteLine(0);


                xin = Console.ReadLine();
            }

            Console.ReadLine();
        }

        static void DFSVisitados(bool[,] adyMt, int runner, bool[] visited,ref int cnt)
        {
            visited[runner] = true;
            cnt++;
            for (int c = 0; c < adyMt.GetLength(1); c++)
            {
                if (adyMt[runner, c] && !visited[c])
                {
                    DFSVisitados(adyMt,c, visited,ref cnt);
                }
            }            
        }


    }
}

