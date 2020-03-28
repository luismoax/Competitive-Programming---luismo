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
            //Just Another Easy Problem            
            int tc = int.Parse(Console.ReadLine());
            string[] alf = { "0","1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F" };
            for (int c = 0; c < tc; c++)
            {
                string s = Console.ReadLine();
                for (int i = 0; i < alf.Length; i++)
                {
                    if (s[s.Length - 1].ToString() == alf[i])
                    {
                        if (i % 2 == 0) Console.WriteLine("NO");
                        else Console.WriteLine("YES");
                        break;
                    }
                }
            }
            Console.ReadLine();
        }

    }
}
