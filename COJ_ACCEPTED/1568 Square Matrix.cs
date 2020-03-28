using System;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] p = Console.ReadLine().Split(' ');
            long n = long.Parse(p[0]);
            long k = long.Parse(p[1]);
            long r = long.Parse(p[2]);
            long c = long.Parse(p[3]);

            Console.WriteLine(SquareMatrix(n,k,r,c));
            
            Console.ReadLine();
        }

        static long SquareMatrix(long n, long k , long r,long c)
        {
            long rs = 0;
            k = k % 4;

            if (k == 0)
            {
                rs = n * (r - 1) + c;
            }
            else if (k == 1 || k == -3)
            {
                rs = r + n * (n - c);
            }
            else if (k == 2 || k == -2)
            {
                rs = n * (n - r) + (n - c + 1);
            }
            else
            {
                rs = n * (c - 1) + (n - r + 1);
            }
            return rs;
        }

    }
}
