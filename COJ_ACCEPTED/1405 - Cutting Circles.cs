using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace COJ
{
    class Program
    {   
        static void Main(string[] args)
       {        
            int tc = int.Parse(Console.ReadLine());
            for (int t = 0; t < tc; t++)
            {
                double n = double.Parse(Console.ReadLine());
                Console.WriteLine ( (1 + ( (n*(n-1)/2)   *  (1+ ((n-2)*(n-3)/12)) )  )  );
            }

            Console.ReadLine();
        }

    }
}
