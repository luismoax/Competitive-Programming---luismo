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
            //1086 Eliminating Numbers
			//Criba de Eratostenes
            for (int i = 0; i < 10; i++)
            {
                int n = int.Parse(Console.ReadLine());
                                
                bool[] b = new bool[n+1];                
                b[0] = true;
                b[1] = true;
                
                int primesCnt = 0;
                for (int c = 2; c <= Math.Sqrt(n+1); c++)
                {
                    if (!b[c])
                    {   
                        for (int d = c+c; d < b.Length; d+=c)
                        {
                            b[d] = true;
                        }
                    }
                }
                //Contando los primos finales
                for (int c = 0; c < b.Length/2; c++)
                {
                    if (!b[c]) primesCnt++;
                    if (!b[b.Length - 1 - c]) primesCnt++;
                }
                if (b.Length % 2 == 1 && !b[b.Length / 2 ]) primesCnt++;

                Console.WriteLine(primesCnt);                
            }            
            Console.ReadLine();
        }        

    }


}
