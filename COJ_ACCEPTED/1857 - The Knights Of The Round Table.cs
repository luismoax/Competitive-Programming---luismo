using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace COJ
{
    class Program
    {
        //1857 - The Knights Of The Round Table
        static void Main(string[] args)
        {
            string xin = "";
            while ((xin = Console.ReadLine())!=null)
            {
                string[] arrStr = xin.Split(' ');
                double a = double.Parse(arrStr[0]);
                double b = double.Parse(arrStr[1]);
                double c = double.Parse(arrStr[2]);

                double p = (a + b + c) / 2;
                double r = Math.Sqrt(p * (p - a) * (p - b) * (p - c)) / p;

                //Si el mayor de todos es igual al semiperimetro
                double mx = 0;
                if (a > b && a > c)
                    mx = a;
                if (b > a && b > c)
                    mx = b;
                else mx = c;

                if (mx == p)
                    r = 0;

                Console.WriteLine("The radius of the round table is: {0:f3}",r);
            }

            Console.ReadLine();
        }

    }
}
