using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        //1658 Longest Increasing Subsequence
        static void Main(string[] args)
        {
            int tc = int.Parse(Console.ReadLine());
            for (int c = 0; c < tc; c++)
            {
                //Solucion Dinamica
                int n = int.Parse(Console.ReadLine());
                string[] p = Console.ReadLine().Split(' ');
                //Copio los numeros de la entrada en este arreglo
                int[] numbers = new int[p.Length];
                //este arreglo en la i-esima posicion guarda el tamanyo
                //de la mayor LIS que comienza con el.
                int[] mx = new int[numbers.Length];
                //Copiando los valores de la entrada
                for (int i = 0; i < p.Length; i++)
                {
                    numbers[i] = int.Parse(p[i]);
                }
                //el valor de la ultima posicion es uno (pues solo podre formar)
                //una LIS de un #                
                mx[mx.Length - 1] = 1;
                //en esta variable se almacena el valor maximo de una LIS
                int longestSubsequenceLenght = 1;
                //A partir de c\# busco de los que le siguen mayores que el
                //cual es inicio de la mayor LIS q puedo formar
                for (int i = mx.Length-2; i >= 0; i--)
                {
                    int maximunLong = 0;
                    for (int j = i+1; j < numbers.Length; j++)
                    {
                        if (numbers[j] > numbers[i] && mx[j] > maximunLong) maximunLong = mx[j];
                    }
                    mx[i] = 1 + maximunLong;
                    if (mx[i] > longestSubsequenceLenght) longestSubsequenceLenght = mx[i];
                }
                Console.WriteLine(longestSubsequenceLenght);
            }
            Console.ReadLine();

        }

    }

}

