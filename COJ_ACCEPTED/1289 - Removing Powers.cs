using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace COJ
{
    class Program
    {
        static void Main(string[] args)
        {
            TextReader tr = Console.In;
            //Console.SetIn(new StreamReader(@"f:\PrOGrAmaCiÓn\COJ\DataSets & Own Solutions\TestData\cowrow\5.in"));
            string xin = "";
            while (!String.IsNullOrEmpty(xin = Console.ReadLine()))
            {
                int n = int.Parse(xin);
                
                int[] marks = new int[n]; // Lleva las macas de en que ronda se eliminan
                int[] roundsEliminated = new int[n]; // lleva la cantidad de eliminados por ronda

                for (int i = 0; i < n; i++)
                {
                    //Si esta posicion es potencia de 2
                    int k =i+1;         
                    double aux = Math.Log(k, 2);
                    if (aux == Math.Truncate(aux)) // Busco si la posición es potencia de 2
                    {
                        marks[i] =1;
                        roundsEliminated[0]++;
                    }
                    else
                    {
                        // Voy quitándole a la posición que estoy verificando, la cantidad de eliminados por
                        // cada una de las rondas y verifico en cada paso que no se convierta en una posición
                        // potencia de 2
                        for (int j = 0; j < roundsEliminated.Length && roundsEliminated[j]>0; j++)
                        {
                            k -= roundsEliminated[j]; // elimino la cantidad de esta ronda
                            aux = Math.Log(k, 2);
                            if (aux == Math.Truncate(aux)) // verifico que sea potencia de 2
                            {
                                marks[i] =j+2;
                                roundsEliminated[j+1]++;
                                break;
                            }
                        }
                    }
                }

                // Buscando el último máximo
                int max = 0,idx =-1;
                for (int i = 0; i < marks.Length; i++)
                {
                    if (marks[i] >= max)
                    {
                        max = marks[i];
                        idx = i;
                    }
                }
                Console.WriteLine(idx+1);
            }

            Console.SetIn(tr);
            Console.ReadLine();
        }


    }
}
