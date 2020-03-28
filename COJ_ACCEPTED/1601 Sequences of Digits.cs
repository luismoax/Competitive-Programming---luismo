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
            //1601 Sequences of Digits
            int tc = int.Parse(Console.ReadLine());
            for (int c = 0; c < tc; c++)
            {
                string[] p = Console.ReadLine().Split(' ');
                bool[] bArr = new bool[10];
                List<int> lst = new List<int>();
                //Recorro la lista de numeros
                for (int i = 0; i < p.Length; i++)
                {
                    //voy tomando los numeros de atras en adelante
                    int ax = int.Parse(p[p.Length - 1 - i]);
                    //Le doy patras en el arrelgo de bool
                    for (int j = 9; j >= 9 - ax; j--)
                    {
                        //Si tengo alguno marcado corro el limite
                        if (bArr[j]) ax++;
                    }
                    bArr[9 - ax] = true;
                    lst.Add(9 - ax);
                }
                Console.WriteLine("{0} {1} {2} {3} {4} {5} {6} {7} {8} {9}",lst[9],lst[8],lst[7],lst[6],lst[5],lst[4],lst[3],lst[2],lst[1],lst[0]);                
            }
            Console.ReadLine();
        }

    }
}
