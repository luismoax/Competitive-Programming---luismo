using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace COJ
{
    class Program
    {        
        static Stack<int> dishes;

        static void Main(string[] args)
        {
            int tc = int.Parse(Console.ReadLine());

            string[] rst = new string[tc];
            for (int c = 0; c < tc; c++)
            {
                int k = int.Parse(Console.ReadLine());
                DescomposicioEnPowTwo(k);
                string s = "";
                while (dishes.Count > 0)
                {
                    s = dishes.Pop() + " " + s;
                }
                rst[c] = s;
            }
            foreach (string item in rst)
            {
                Console.WriteLine(item);
            }
            Console.ReadLine();
        }

        static void DescomposicioEnPowTwo(int n)
        {
            dishes = new Stack<int>();            
            bool bb = DescomposicioEnPowTwo(n,0,0);           
        }

        static bool DescomposicioEnPowTwo(int n, int suma,int inf)
        {            
            if (suma == n) return true;

            for (int c = inf; c <= 14; c++)
            {
                double pw = Math.Pow(2,c);
                if (suma + pw > n) return false;

                dishes.Push(c);
                if (DescomposicioEnPowTwo(n, (int)(suma+pw), c + 1)) return true;
                dishes.Pop();
            }
            return false;
        }

    }
}
