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
         * Generamos todas las permutaciones de los dígitos del número
         * y en c\una de ellas verificamos la primalidad
        */
        
        static int n;
        static string number = "";
        static BitArray ba = new BitArray(100000000);
        static void Main(string[] args)
        {
            number = Console.ReadLine();
            Permutations(new bool[number.Length], "");
            Console.WriteLine(n);
        }

        static bool IsPrime(int n)
        {
            if (n < 2)
                return false;
            if (n == 2 || n==3)
                return true;
            if (n % 2 == 0 || n % 3 == 0)
                return false;
            for (int i = 5; i*i <= n; i+=2)
            {
                if (n % i == 0)
                    return false;
            }
            return true;
        }

        static void Permutations(bool [] mark,string build)
        {
            if (build.Length == number.Length)
            {
                int k = int.Parse(build);
                if (IsPrime(k) && !ba[k-1])
                {
                    n++;
                    ba[k - 1] = true;
                }
                return;
            }            
            for (int i = 0; i < number.Length; i++)
            {   
                if (!mark[i])
                {
                    mark[i] = true;                    
                    Permutations(mark, build+number[i]);
                    mark[i] = false;
                }
            }
        }

    }
  
}
