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
            //StreamReader sr = new StreamReader(@"d:\PrOGrAmaCi?n\Taller\COJ\COJ\COJ\bin\Debug\in.lmo");
            string xin = Console.ReadLine();
            while (xin != "0 0 0")
            {
                string[] p = xin.Split(' ');
                int n = int.Parse(p[0]);
                int m = int.Parse(p[1]);
                int y = int.Parse(p[2]);

                List<int> lst = new List<int>();

                for (int i = 0; i < m; i++)
                {
                    //Calculo la potencia
                    int x = 1;
                    for (int j = 0; j < n; j++)
                    {
                        x = x * i;
                        x = x % m;
                    }
                    if (x == y) lst.Add(i);
                }

                if (lst.Count == 0) Console.WriteLine("-1");
                else
                {
                    for (int i = 0; i < lst.Count; i++)
                    {
                        if (i == 0) Console.Write(lst[i]);
                        else Console.Write(" " + lst[i]);
                    }
                    Console.WriteLine();
                }
                xin = Console.ReadLine();
            }

            Console.ReadLine();

        }

    }

}

