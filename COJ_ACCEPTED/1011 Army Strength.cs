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
            Console.ReadLine();
            for (int c = 0; c < tc; c++)
            {
                string[] p = Console.ReadLine().Split(' ');
                long GodzillaStrongest = 0;
                long MechaGodzillaStrongest = 0;
                string []forces = Console.ReadLine().Split(' ');
                for (long i = 0; i < long.Parse(p[0]); i++)
                {
                    if (long.Parse(forces[i]) > GodzillaStrongest) GodzillaStrongest = long.Parse(forces[i]);
                }
                forces = Console.ReadLine().Split(' ');
                for (long i = 0; i < long.Parse(p[1]); i++)
                {
                    if (long.Parse(forces[i]) > MechaGodzillaStrongest) MechaGodzillaStrongest = long.Parse(forces[i]);
                }
                if (MechaGodzillaStrongest > GodzillaStrongest) Console.WriteLine("MechaGodzilla");
                else Console.WriteLine("Godzilla");
                Console.ReadLine();
            }            
           
            Console.ReadLine();
        }

    }

}
