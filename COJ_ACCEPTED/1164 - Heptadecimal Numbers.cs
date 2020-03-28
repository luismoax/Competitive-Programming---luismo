using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace COJ
{
    class Program
    {
        static void Main(string[] args)
        {
            //1164 Heptadecimal Numbers
            string kinput = Console.ReadLine();
            while (kinput != "* *")
            {
                string[] p = kinput.Split(' ');
                string n1 = "";
                string n2 = "";
                bool bc = false;

                n1 = p[0].TrimStart('0');
                n2 = p[1].TrimStart('0');

                if (n1.Length > n2.Length) Console.WriteLine(">");
                else if (n2.Length > n1.Length) Console.WriteLine("<");
                else
                {
                    bc = true;
                    for (int i = 0; i < n1.Length; i++)
                    {
                        if (n1[i] > n2[i]) { Console.WriteLine(">"); bc = false; break; }
                        else if (n2[i] > n1[i]) { Console.WriteLine("<"); bc = false; break; }
                    }
                    if (bc) Console.WriteLine("=");
                }
                kinput = Console.ReadLine();
            }
            Console.ReadLine();
        }

    }
}
