using System;
using System.Collections.Generic;
using System.Text;

namespace COJ
{
    class Program
    {
        static void Main(string[] args)
        {
            //1025 Democracy in danger
            int n = int.Parse(Console.ReadLine());
            string[] p = Console.ReadLine().Split(' ');
            int[] arr = new int[p.Length];
            for (int i = 0; i < p.Length; i++)
            {
                arr[i] = int.Parse(p[i]);
            }
            //Ordeno el arreglo
            Array.Sort(arr);
            //para la mitad del arreglo
            int mid = -1;
            
            //if (p.Length % 2 == 0) mid = p.Length / 2 + 1;
            //else mid = p.Length - (p.Length / 2);
            mid = arr.Length / 2 + 1;

            int cantMax = 0;
            for (int i = 0; i < mid; i++)
            {
                cantMax += arr[i]/ 2 + 1;                
            }
            Console.WriteLine(cantMax);

            Console.ReadLine();
        }
    }
}
