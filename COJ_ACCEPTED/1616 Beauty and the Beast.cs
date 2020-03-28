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
            //1616 Beauty and the Beast
            string xin = Console.ReadLine();
            while (xin != null && xin!="")
            {
                string[] p = xin.Split(':');

                //Quito los cero al principio
                p[0] = p[0].TrimStart('0');
                p[1] = p[1].TrimStart('0');
                //Si al Trimear era 00 me que do "" y verifico
                int p1 = 0;
                if (p[1] != "") p1 = int.Parse(p[1]);
                int p0 = 0;
                if (p[0] != "") p0 = int.Parse(p[0]);

                //Calculo el valor de m y de h
                double m = p1 * 6.0;
                double h = (p0 % 12) * 30 + (p1 * 0.5);

                Console.WriteLine("{0:f1} {1:f1}", h, m);
                xin = Console.ReadLine();
            }
            Console.ReadLine();
        }

    }
}
