using System;
using System.IO;
using System.Text;

namespace COJ
{
    class Program
    {
        static void Main(string[] args)
        {
            string kinput = Console.ReadLine();
            while (kinput!=null && kinput!="")
            {
                string[] p = kinput.Split(' ');
                long n = long.Parse(p[0]);
                long k = long.Parse(p[1]);

                Console.WriteLine((((n-1)*k)*n)/2);
                kinput = Console.ReadLine();
            }            
            Console.ReadLine();
        }

    }

}
