using System;
using System.Text;

namespace COJ
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] p = Console.ReadLine().Split(' ');
            Console.WriteLine(2*(long.Parse(p[0])+long.Parse(p[1])));
            Console.ReadLine();
        }
    }
}