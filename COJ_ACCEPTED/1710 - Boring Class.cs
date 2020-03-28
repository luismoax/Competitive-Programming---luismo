using System;
using System.Collections.Generic;
using System.Text;

namespace coj
{
    class Program
    {
        static void Main(string[] args)
        {
            int tc = int.Parse(Console.ReadLine());
            for (int t = 0; t < tc; t++)
            {
                long n = long.Parse(Console.ReadLine());

                Console.WriteLine(CNT(n));
            }
            Console.ReadLine();
        }

        static int CNT(long n)
        {
            int cnt=0;
            if (n % 2 == 0)
            {
                cnt++;
                while (n%2==0)
                {
                    n /= 2;
                }
            }

            for (int i = 3; i*i< n; i+=2)
            {
                if (n % i == 0)
                    cnt++;

                while (n%i==0)
                {
                    n /= i;
                }
            }
            if (n == 1)
                return cnt;
            return cnt+1;
        }



    }
}
