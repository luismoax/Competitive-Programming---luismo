using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Collections;
using System.Globalization;
using System.Linq;


namespace COJ
{
    class Program
    {
        /*
         * Author LUISMO
         * Este ejercicio no tiene nada en particular, m?s all? de seguir las reglas que pone
        */
        static int[] inDegg;        
        static List<List<int>> ady = new List<List<int>>();
        static int cant=0;
        static bool[] TakenBlocks;
        static void Main(string[] args)
        {
            int n=0, e=0;
            string[] data = Console.ReadLine().Split(new char[]{' '}, StringSplitOptions.RemoveEmptyEntries);
            n = int.Parse(data[0]);
            e = int.Parse(data[1]);
                        
            inDegg = new int[n];
            TakenBlocks = new bool[n];
            //Adyacencia
            for (int i = 0; i < n; i++)
                ady.Add(new List<int>());
            
            for (int i = 0; i < e; i++)
            {
                data = Console.ReadLine().Split(new char[]{' '}, StringSplitOptions.RemoveEmptyEntries);
                int x = int.Parse(data[0]);
                int y = int.Parse(data[1]);
                ady[x - 1].Add( y - 1);
                inDegg[y - 1]++;
            }

            BackTrack(n);

            Console.WriteLine(cant);

            Console.ReadLine();
        }

        static void BackTrack(int notTaken)
        {
            if (notTaken == 0)
            {
                cant++;
                return;
            }

            for (int i = 0; i < TakenBlocks.Length; i++)
            {
                if (!TakenBlocks[i] && inDegg[i] == 0)
                {
                    //"Desconecto sus adyacentes"
                    for (int j = 0; j < ady[i].Count; j++)                    
                        inDegg[ady[i][j]]--;
                    
                    TakenBlocks[i] = true;
                    
                    BackTrack(notTaken-1);
                    
                    TakenBlocks[i] = false;

                    for (int j = 0; j < ady[i].Count; j++)                    
                        inDegg[ady[i][j]]++;                    
                }
            }
        }
    }
}