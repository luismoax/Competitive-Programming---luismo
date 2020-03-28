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
            string xin = "";
            while ((xin = Console.ReadLine())!= "X")
            {
                string xin2 = Console.ReadLine();
                int cnt = 0;
                for (int i = 0; i < xin.Length; i++)
                {
                    if (xin[i] != xin2[i])
                        cnt++;
                }
                Console.WriteLine("Hamming distance is {0}.", cnt);
            }

            Console.ReadLine();
        }        
        
    }

}