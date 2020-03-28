using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace COJ
{
    class Program
    {
        static void Main(string[] args)
        {
            int tc = int.Parse(Console.ReadLine());

            string[] rst = new string[tc];
            for (int c = 0; c < tc; c++)
            {

                int n = int.Parse(Console.ReadLine());
                bool[] b = new bool[n];
                int open = 0;
                for (int d = 0; d < n; d++)
                {
                    for (int i = 0; i < n; i++)
                    {
                        if ((i + 1) % (d + 1) == 0)
                        {
                            b[i] = !b[i];
                            if (b[i]) open++;
                            else open--;
                        }
                    }
                }
                Console.WriteLine(open);

            }            
            
            Console.ReadLine();
        }        

    }
}
