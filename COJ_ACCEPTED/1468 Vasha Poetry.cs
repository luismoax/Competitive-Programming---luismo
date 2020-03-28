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
            //1468 Vasha Poetry
            int tc = int.Parse(Console.ReadLine());
            for (int c = 0; c < tc; c++)
            {
                bool b= true;
                for (int d = 0; d < 3; d++)
                {
                    Console.ReadLine();
                    int cnt = 0;
                    string line = Console.ReadLine();
                    for (int i = 0; i < line.Length; i++)
                    {
                        if (line[i] == 'a' || line[i] == 'e' || line[i] == 'i' || line[i] == 'o' || line[i] == 'u') cnt++;
                    }
                    if(d%2==0 && cnt!=5) b =false;
                    if (d % 2 == 1 && cnt != 7) b = false;
                }
                if (b) Console.WriteLine("YES");
                else Console.WriteLine("NO");
            }            
            Console.ReadLine();
        }

    }
}
