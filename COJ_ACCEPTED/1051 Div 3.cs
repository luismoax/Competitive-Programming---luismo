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

            int rmd = n % 3;
            if(n==0)
                Console.WriteLine(2*n/3);
            else if(n==1)
                Console.WriteLine(2*(n-1)/3);
            else
                Console.WriteLine(2*(n-2)/3 + 1);
            Console.ReadLine();
        }


    }

}
