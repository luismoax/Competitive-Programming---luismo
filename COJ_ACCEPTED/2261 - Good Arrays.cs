using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Collections;
using System.IO;

namespace consoleApp
{
    class Program
    {
        static void Main(string[] args)
        {

            //Console.WriteLine(long.MaxValue>1000000000000);
            // Generate all the prime number int the given interval
            List<int> primes = new List<int>();
            for (int i = 2 ; i <= 2310; i++)
            {
                if (IsPrime(i))
                    primes.Add(i);
            }

            string[] data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            int n = int.Parse(data[0]);            
            data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);

            bool ok = true;
            // Chack if every given number is divisible for at least 3 of the prime numbers
            for (int i = 0; i < data.Length; i++)
            {
                int x = int.Parse(data[i]);
                int cnt = 0;
                for (int j = 0; cnt<3 && primes[j]<x; j++)
                {
                    if (x % primes[j] == 0)
                        cnt++;
                }
                if (cnt < 3)
                {
                    ok = false;
                    break;
                }
            }

            if(ok)
                Console.WriteLine("YES");
            else Console.WriteLine("NO");


            Console.ReadLine();
        }


        static bool IsPrime(int n)
        {
            if (n < 2)
                return false;
            if (n == 2 || n == 3)
                return true;
            
            if (n % 2 == 0 || n % 3 == 0)
                return false;

            for (int i = 3; i*i <= n; i+=2)
            {
                if (n % i == 0)
                    return false;
            }
            return true;
        }


    }

}
