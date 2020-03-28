using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace COJ
{
    class Program
    {
        static void Main(string[] args)
        {  
            /*
             * La talla es que vamos llevando la suma parcial congruente modulo d
             * cada vez que tenga dos de estas sumas con el mismo resto modulo d
             * al restarlas tendre un intervalo de numeros donde las suma sera divisible
             * por d (propiedades de congruencia) una vez con esto aumento la cantidad en
             * la cantidad de valores con ese modulo - 1 pues es analogo a formar con la nueva suma
             * intervalos con las anteriores que había.
             * */
            int tc = int.Parse(Console.ReadLine());
            string[] p = null;
            for (int t = 0; t < tc; t++)
            {
                p = Console.ReadLine().Split(' ');
                int d = int.Parse(p[0]);
                int n = int.Parse(p[1]);

                p = Console.ReadLine().Split(' ');
                
                //En este arreglo guardamos los valores de las sumas parciales
                //modulo d
                int[] sumRemainders = new int[d];
                //Para ir llevando la suma modulo d
                int smr = 0;
                //Contador
                int cnt = 0;
                for (int i = 0; i < p.Length; i++)
                {
                    //Hallamos la suma parcial modulo d
                    int x = int.Parse(p[i]);
                    smr += x % d;
                    smr %= d;

                    sumRemainders[smr]++;
                    //Aumentamos el contador
                    cnt += sumRemainders[smr]-1;
                    //Si la suma parcial modulo d era congruente 0
                    //aumentamos 1 mas
                    if (smr == 0)
                        cnt++;
                }
                Console.WriteLine(cnt);
            }
            
            Console.ReadLine();
        }
    }

    

}