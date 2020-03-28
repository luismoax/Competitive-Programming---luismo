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
            //1604 Playing with the Bases
            int tc = int.Parse(Console.ReadLine());
            for (int c = 0; c < tc; c++)
            {   
                string n = Console.ReadLine();
                int xbase = 0;
                for (int j = 0; j < n.Length; j++)
                {
                    if (int.Parse(n[j].ToString()) > xbase) xbase = int.Parse(n[j].ToString());
                }

                long sum = 0;
                for (int d = 0; d < n.Length; d++)
                {
                    int xi = int.Parse(n[n.Length - 1 - d].ToString());
                    sum += xi * (long)Math.Pow(xbase + 1, d);
                    if (sum > int.MaxValue) break;
                }
                if (sum < int.MaxValue) Console.WriteLine(sum);
                else Console.WriteLine("-1");
                
            }

            Console.ReadLine();
        }
        
    }

}
