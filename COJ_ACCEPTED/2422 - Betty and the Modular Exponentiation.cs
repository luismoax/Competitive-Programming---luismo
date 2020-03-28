using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace COJ
{
    class Program
    {
        /*
         * Author: Luismo
         * Idea: Use the exponential method O(log n) with a modulos=1000000000
         * 
         * */

        static long mod = 1000000000;
        static void Main(string[] args)
        {
            //string[] data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            TextReader tr = Console.In;
            //Console.SetIn(new StreamReader(@"d:\lmo.in"));
            
            SolveSingleProblem();

            Console.SetIn(tr);
            Console.ReadLine();            
        }


        static void SolveSingleProblem()
        {
            int tc = int.Parse(Console.ReadLine());
            for (int i = 0; i < tc; i++)
            {
                string[] data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                long a = long.Parse(data[0]);
                long b = long.Parse(data[1]);

                Console.WriteLine(Pow(a,b));
            }            
        }
		// Power 
        static long Pow(long a, long b)
        {
            if (b == 0)
                return 1;
            if(b==1)
                return a%mod;

            long x = Pow(a, b / 2) % mod;
            if (b % 2 == 0)
                return (x * x) % mod;
            
            return ((x * x)%mod * a%mod) % mod;
        }        
    } 
}
