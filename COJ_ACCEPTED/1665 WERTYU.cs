using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        //1665 WERTYU
        static void Main(string[] args)
        {
            string[] p1 = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=" };
            string[] p2 = { "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "[", "]", @"\" };
            string[] p3 = { "A", "S", "D", "F", "G", "H", "J", "K", "L", ";", "'"};
            string[] p4 = { "Z", "X", "C", "V", "B", "N", "M", ",", ".", "/" };
            string[][] pp = { p1,p2,p3,p4};
            string xin = Console.ReadLine();
            while (xin !=null)
            {
                for (int i = 0; i < xin.Length; i++)
                {
                    if (xin[i] == ' ') Console.Write(' ');
                    else
                    {
                        bool found = false;
                        for (int j = 0; j < pp.Length; j++)
                        {
                            for (int k = 0; k < pp[j].Length; k++)
                            {
                                if (xin[i].ToString() == pp[j][k])
                                {
                                    if (k > 0) Console.Write(pp[j][k - 1]);
                                    else Console.Write(pp[j][0]);
                                    found = true;
                                    break;
                                }
                            }
                            if (found) break;
                        }
                    }
                }
                Console.WriteLine();
                xin = Console.ReadLine();
            }
            Console.ReadLine();
        }

    }

}

