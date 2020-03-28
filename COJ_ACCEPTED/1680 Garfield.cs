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
            while ((xin = Console.ReadLine()) != null)
            {
                string[] p = xin.Split(' ');
                string cad = p[0];
                string pattern = p[1];

                while (cad.Contains(pattern))
                {
                    cad = cad.Replace(pattern, "");
                }
                Console.WriteLine(cad);
            }
            Console.ReadLine();
        }


    }

}