using System;
using System.IO;
using System.Text;

namespace COJ
{
    class Program
    {        
        static void Main(string[] args)
        {   
            int tc = int.Parse(Console.ReadLine());
            for (int i = 0; i < tc; i++)
            {
                string[] p = Console.ReadLine().Split(' ');
                double b = double.Parse(p[0]);
                double c = double.Parse(p[1]);

                double l = b * c / (c + b);
                l = l * l;
                Console.WriteLine( Math.Round(l, 4));                
            }
            Console.ReadLine();
        }


    }

}
