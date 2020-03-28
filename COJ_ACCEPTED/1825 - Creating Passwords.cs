using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace COJ
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            for (int t = 0; t < n; t++)
            {
                string[] p = Console.ReadLine().Split(' ');
                string name = "";
                for (int i = 1; i < p.Length; i++)
                {
                    if(i==1)
                        name+=p[1];
                    else name += "*"+p[i];
                }

                Console.WriteLine("{0}{1}{2}",p[0].Substring(0,3),name,p[0].Substring(3,3));
            }

            Console.ReadLine();
        }

    }

}
