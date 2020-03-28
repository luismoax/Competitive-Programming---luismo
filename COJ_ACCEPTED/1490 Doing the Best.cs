    using System;
    using System.Collections.Generic;
    using System.IO;
    using System.Text;

    namespace ConsoleApplication1
    {
        class Program
        {
            //1490 Doing the Best
            static void Main(string[] args)
            {
                int n = int.Parse(Console.ReadLine());
                for (int i = 0; i < n; i++)
                {
                    //Total monedas
                    int k = int.Parse(Console.ReadLine());
                    //Numero de monedas para ganar
                    int f = (k / 2) + 1;
                    
                    //Cantidad de combinaciones sin repeticiones ganadoras
                    int w = k - f+1;
                    
                    //Combi posibles sin repeticions
                    k++;
                    
                    //Probabilidad
                    double d = (double) (w)/ (double)k;

                    Console.WriteLine("{0:f6}",d);
                }

                Console.ReadLine();
            }

        }
    }
