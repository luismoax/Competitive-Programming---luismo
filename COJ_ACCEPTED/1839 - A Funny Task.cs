using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace COJ
{
    class Program
    {
		//1839 - A Funny Task
        static void Main(string[] args)
        {
            int tc = int.Parse(Console.ReadLine());
            for (int t = 0; t < tc; t++)
            {
                Console.WriteLine(8*(int.Parse(Console.ReadLine()))+42);
            }
            Console.ReadLine();
        }
    }
}
