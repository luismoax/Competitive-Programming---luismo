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
            List<long> lst = new List<long>();
            lst.Add(1);
            int tc = int.Parse(Console.ReadLine());
            long[] p = new long[2];
            p[0] = 1;
            p[1] = 1;
            for (int i = 1; i <= 1000000; i++)
            {
                lst.Add((p[0] + p[1]) % 1000000007);
                p[0] = p[1];
                p[1] = lst[lst.Count - 1];
            }
            for (int c = 0; c < tc; c++)
            {
                Console.WriteLine(lst[int.Parse(Console.ReadLine())]);                
            }
            Console.ReadLine();
        }        

    }
}
