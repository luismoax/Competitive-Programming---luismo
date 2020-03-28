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
            //StreamReader sr = new StreamReader(@"C:\Documents and Settings\Info\Escritorio\serial.txt");

            int tc = int.Parse( Console.ReadLine());
            for (int c = 0; c < tc; c++)
            {
                double amount = 0;
                for (int i = 0; i < 12; i++)
                {
                    amount += double.Parse(Console.ReadLine());
                }
                string adev = String.Format("{0:f2}",amount/12);
                string ax = adev.Substring(0, adev.Length - 3);
                string afd = "";
                for (int i = 0; i < ax.Length; i++)
                {
                    if (i > 0 && i % 3 == 0) afd = ',' + afd;
                    afd = ax[ax.Length - 1 - i] + afd;
                }
                afd = afd + "." + adev[adev.Length - 2] + adev[adev.Length - 1];
                Console.WriteLine("{0} ${1}",c+1,afd);

            }

            Console.ReadLine();
        }

    }
}
