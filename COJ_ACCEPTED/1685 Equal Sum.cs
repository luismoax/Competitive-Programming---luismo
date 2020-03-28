using System;
using System.Collections.Generic;
using System.Text;
using System.IO;


namespace COJ
{
    class Program
    {
        //
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            string[] p = Console.ReadLine().Split(' ');
            int x = int.Parse(Console.ReadLine());

            bool[] array = new bool[1000001];

            for (int i = 0; i < p.Length; i++)
            {
                int f = int.Parse(p[i]);
                array[f] = true;
            }
            int cnt = 0;

            for (int i = 0; i < p.Length; i++)
            {
                int f = int.Parse(p[i]);
                int g = x - f;
                if (f <= x && array[f] && array[x - f] && f!=x-f)
                {
                    cnt++;
                    

                    array[f] = false;
                    array[x - f] = false;
                }
            }

            Console.WriteLine(cnt);
            Console.ReadLine();
        }


    }

}