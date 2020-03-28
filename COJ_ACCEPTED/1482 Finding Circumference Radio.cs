using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static long[] di;
        static void Main(string[] args)
        {
            Console.BackgroundColor = ConsoleColor.Blue;
            Console.ForegroundColor = ConsoleColor.White;
            TextReader tr = Console.In;
            //Console.SetIn(new StreamReader(@"d:\in.lmo"));

            string xin;
            double a, b, c;
            while (!String.IsNullOrEmpty (xin= Console.ReadLine()))
            {
                string[] arr = xin.Split(' ');
                a = double.Parse(arr[0]);
                b = double.Parse(arr[1]);
                c = double.Parse(arr[2]);
                //Comprobando desigualdad triangular
                if (a + b < c || a + c < b || c + b < a)
                {
                    Console.WriteLine("ERROR");
                }
                else
                {   
                    double p = (a + b + c) / 2;
                    double aTriang = Math.Sqrt(p * (p - a) * (p - b) * (p - c));
                    if(aTriang == 0)
                        Console.WriteLine("0.00 {0:f2}",p/2);
                    else Console.WriteLine("{0:f2} {1:f2}", aTriang / p, (a * b * c) / (4 * aTriang));
                }
            }
            Console.SetIn(tr);
            Console.ReadLine();
        }

    }

}
