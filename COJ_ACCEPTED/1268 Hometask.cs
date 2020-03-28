using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        //1268 Hometask
        static void Main(string[] args)
        {   
            int n = int.Parse(Console.ReadLine());
            if (n == 4 || IsPrime(n)) Console.WriteLine("NO");
            else Console.WriteLine("YES");
            Console.ReadLine();
        }

        //O(Sqrt(n))
        static bool IsPrime(int n)
        {
            if (n < 2) return false;
            for (int c = 2; c <= Math.Sqrt(n); c++)
            {
                if (n % c == 0) return false;
            }
            return true;
        }

    }

}
