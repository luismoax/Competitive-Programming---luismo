using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;
using System.IO;
using System.Linq;


namespace ConsoleApplication1
{
    class Program
    {
        
        static void Main(string[] args)        
        {
            TextReader tr = Console.In;
            //Console.SetIn(new StreamReader(@"d:\in.lmo"));

            int n = int.Parse(Console.ReadLine());
            Console.WriteLine("{0:#}",n+1);

            Console.SetIn(tr);
            Console.ReadLine();
        }


    }


}
