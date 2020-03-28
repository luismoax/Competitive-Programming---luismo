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
            //Parity
            string input = Console.ReadLine();
            while (input!="0")
            {
                int n = int.Parse(input);
                string[] bin = ToBinaryAndOnes(n).Split(' ');
                Console.WriteLine("The parity of "+bin[0]+" is "+int.Parse(bin[1])+" (mod 2).");
                input = Console.ReadLine();
            }
            Console.ReadLine();
        }
        /// <summary>
        /// Este metodo me devuelve la representacion binaria de un entero n
        /// y separado por un espacio la cantidad de unos en esa representacion binaria
        /// </summary>
        /// <param name="n">entero n</param>
        /// <returns></returns>
        static string ToBinaryAndOnes(int n)
        {
            int ones = 0;
            string s = "";
            while (n > 0)
            {
                s = (n % 2) + s;
                if (n % 2 == 1) ones++;
                n = n / 2;
            }
            return s + " "+ones;
        }
    }
}
