using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        //1655 Xtreme Encription
        static void Main(string[] args)
        {  
            string xin = Console.ReadLine();
            while (xin !=null)
            {
                string[] p = xin.Split(' ');
                int asd = 0;
                int k = 0;
                for (int i = 0; i < p[0].Length; i++)
                {
                    if(asd >= p[1].Length) break;
                    for (int j = asd; j < p[1].Length; j++)
                    {
                        if (p[0][i] == p[1][j]) { k++; asd = j + 1; break; }
                    }
                }
                if (k == p[0].Length) Console.WriteLine("Yes");
                else Console.WriteLine("No");                    

                xin = Console.ReadLine();
            }
            Console.ReadLine();
        }

    }

}

