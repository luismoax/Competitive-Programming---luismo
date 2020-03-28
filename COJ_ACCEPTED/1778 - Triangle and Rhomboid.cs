using System;
using System.Collections.Generic;
using System.Text;

namespace coj
{
    class Program
    {
        //1778 - Triangle and Rhomboid
        static void Main(string[] args)
        {
            int tc = int.Parse(Console.ReadLine());
            for (int i = 0; i < tc; i++)
            {
                string[] p = Console.ReadLine().Split(' ');
                double ac = double.Parse(p[0]);
                double ab = double.Parse(p[1]);

                double A1 = (ab / 2 * ac / 2) / 2;
                double A2 = (ab / 4 * ac / 2) / 2;

                Console.WriteLine("{0:f8}",A1+A2);
            }

            Console.ReadLine();
        }
    }
}
