using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace COJ
{
    class Program
    {
        //1052 SuperPrime Rib
        static void Main(string[] args)
        {
            int[] impares = { 1,3,5,7,9};
            Queue<int> SuperPrimeRib = new Queue<int>();

            string xin = "";
            while ((xin = Console.ReadLine()) != null)
            {
                int n = int.Parse(xin);

                //Limpiamos la cola
                SuperPrimeRib.Clear();
                //Encolamos los primeros superprimos
                SuperPrimeRib.Enqueue(2);
                SuperPrimeRib.Enqueue(3);
                SuperPrimeRib.Enqueue(5);
                SuperPrimeRib.Enqueue(7);


                for (int i = 1; i < n; i++)
                {
                    //Por cada uno de los Superprimo de longitud i
                    int k = SuperPrimeRib.Count;
                    for (int j = 0; j < k; j++)
                    {
                        //Sacamos el superprimo en la punta de la cola
                        int p = SuperPrimeRib.Dequeue();
                        //Probamos concatenarle algun numero impar
                        for (int f = 0; f < impares.Length; f++)
                        {
                            if (EsPrimo(p * 10 + impares[f])) SuperPrimeRib.Enqueue(p * 10 + impares[f]);
                        }

                    }
                }

                foreach (var item in SuperPrimeRib)
                {
                    Console.WriteLine(item);
                }

            }

            Console.ReadLine();
        }

        static bool EsPrimo(int n)
        {
            if (n < 2) return false;
            for (int i = 2; i <= Math.Sqrt(n); i++)
            {
                if (n % i == 0) return false;
            }
            return true;
        }

    }

}