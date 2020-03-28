using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
	    //1595 Multiples of Nine
            string xin = Console.ReadLine();
            while (xin !="0")
            {
                string s1 = (string)xin.Clone();
                                
                int deg = 0;
                while (s1.Length>1)
                {
                    int n = 0;
                    for (int i = 0; i < s1.Length; i++)
                    {
                        n += int.Parse(s1[i].ToString());
                    }
                    s1 = n.ToString();
                    deg++;
                }
                if (s1 == "9" && deg == 0) Console.WriteLine("{0} is a multiple of 9 and has 9-degree 1.", xin);
                else if(s1=="9")
                    Console.WriteLine("{0} is a multiple of 9 and has 9-degree {1}.",xin,deg);
                else Console.WriteLine("{0} is not a multiple of 9.",xin);
                xin = Console.ReadLine();
            }

        }
    }
}
