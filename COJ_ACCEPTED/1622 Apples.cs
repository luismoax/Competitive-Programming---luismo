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
            //Apples
            string xin = Console.ReadLine();
            while (xin!=null)
            {
                int n = int.Parse(xin);
                string[] p = Console.ReadLine().Split(' ');
                int even = 0;
                int odd = 0;
                int sum = 0;
                for (int c = 0; c < p.Length; c++)
                {
                    int ax = int.Parse(p[c]);
                    sum += ax;
                    if (ax % 2 == 0) even++;
                    else odd++;                    
                }
                if (sum % 2 == 0) Console.WriteLine(even);
                else Console.WriteLine(odd);
                xin = Console.ReadLine();
            }
            Console.ReadLine();
        }

    }
}
