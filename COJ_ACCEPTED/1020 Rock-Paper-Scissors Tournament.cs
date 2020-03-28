using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace COJ
{
    class Program
    {
        static void Main(string[] args)
        {
            //1020 Rock-Paper-Scissors Tournament
            string xinput = Console.ReadLine();
            while (xinput != "0")
            {
                string[] p = xinput.Split(' ');
                int n = int.Parse(p[0]);
                int k = int.Parse(p[1]);

                double[] wonGames = new double[n];
                double[] lostGames = new double[n];

                for (int i = 0; i < k * n * (n - 1) / 2; i++)
                {
                    xinput = Console.ReadLine();
                    p = xinput.Split(' ');
                    int pa = int.Parse(p[0]);
                    int pb = int.Parse(p[2]);

                    #region Segun lo que sacaron
                    //Gana el primero
                    if ((p[1] == "scissors" && p[3] == "paper") || (p[1] == "paper" && p[3] == "rock") || (p[1] == "rock" && p[3] == "scissors"))
                    {
                        wonGames[pa - 1]++;
                        lostGames[pb - 1]++;
                    }
                    else if ((p[1] == "paper" && p[3] == "scissors") || (p[1] == "rock" && p[3] == "paper") || (p[1] == "scissors" && p[3] == "rock"))
                    {
                        wonGames[pb - 1]++;
                        lostGames[pa - 1]++;
                    }
                    //En caso de que haya empate no afecta el averge
                    #endregion
                }

                //Imprimiendo el averge
                for (int i = 0; i < n; i++)
                {
                    //Si el Avergae es indefinido (solo empato juegos)
                    if (wonGames[i] == 0 && lostGames[i] == 0) Console.WriteLine("-");
                    else
                        Console.WriteLine("{0:f3}", wonGames[i] / (wonGames[i] + lostGames[i]));
                }
                //Leo el input
                xinput = Console.ReadLine();

                if (xinput!="0")                    
                    Console.WriteLine();
                
            }
            Console.ReadLine();
        }


    }

}
