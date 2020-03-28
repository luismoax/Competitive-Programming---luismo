using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace COJ
{
    class Program
    {
        static void Main(string[] args)
        {   
            double d = 6.789;
            for (int i = 0; i <= 9; i++)
                Console.WriteLine("{0:f2}", double.Parse(i.ToString() + d.ToString()) / 72);            
            Console.ReadLine(); 
        }
    }
}
