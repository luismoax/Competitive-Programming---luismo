using System;
using System.Collections.Generic;
using System.Text;
using System.IO;


namespace COJ
{
    class Program
    {
        //
        static void Main(string[] args)
        {
            string xin = "";
            while ((xin = Console.ReadLine()) != "*")
            {
                long mcm = 1;
                long mcd = 1;
                for (int i = 1; i < xin.Length; i++)
                {
                    if (xin[i] == 'Y')
                    {
                        mcd = Euclid(mcm, i + 1);
                        mcm = mcm * (i + 1) / mcd;
                    }
                }

                for (int i = 0; i < xin.Length; i++)
                {
                    if (xin[i] == 'N' && mcm % (i + 1) == 0) { mcm = -1; break; }
                }

                Console.WriteLine(mcm);
            }


            Console.ReadLine();
        }

        static long Euclid(long a, long b)
        {
            if (b == 0) return a;
            else return Euclid(b, a % b);
        }


    }

}