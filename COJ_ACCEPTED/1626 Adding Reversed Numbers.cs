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
            //1626 Adding Reversed Numbers
            int tc = int.Parse(Console.ReadLine());
            for (int c = 0; c < tc; c++)
            {
                string[] p = Console.ReadLine().Split(' ');                
                p[0]= p[0].TrimEnd('0');
                p[1] = p[1].TrimEnd('0');
                //Console.WriteLine("{0} adiferença {1}",p[0],p[1]);
                string n1 = "";
                int carry = 0;
                for (int d = 0; d < Math.Max(p[0].Length,p[1].Length); d++)
                {
                    int p0 = 0;
                    int p1 = 0;
                    if (d < p[0].Length) p0 = int.Parse(p[0][d].ToString());
                    if (d < p[1].Length) p1 = int.Parse(p[1][d].ToString());
                    n1 = (p1 + p0 + carry) % 10 + n1;
                    carry = (p1 + p0 + carry) / 10;
                }
                if (carry > 0) n1 = carry + n1;
                n1=n1.TrimEnd('0');
                for (int d = 0; d < n1.Length; d++)
                {
                    Console.Write(n1[n1.Length-1-d]);
                }
                Console.WriteLine();
            }
            Console.ReadLine();
        }        

    }


}
