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
            for (int i = 0; i < n; i++)
            {
                string[] p = Console.ReadLine().Split(' ');
                string gender = p[0];
                string bCity = p[2];
                string bCountry = p[3];
                string rndNumb = p[4];
                p = p[1].Split('/');

                Console.WriteLine("{0}-{1}-{2}-{3}-{4}-{5}-{6}",gender,p[2].PadLeft(4,'0'),p[1].PadLeft(2,'0'),p[0].PadLeft(2,'0'),bCity.PadLeft(4,'0'),bCountry.PadLeft(3,'0'),rndNumb.PadLeft(4,'0'));
            }

            Console.ReadLine();
        }


    }

}
