using System.Linq;
using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.BackgroundColor = ConsoleColor.Blue;
            Console.ForegroundColor = ConsoleColor.White;
            string[] data = Console.ReadLine().Split(new char[]{' '},StringSplitOptions.RemoveEmptyEntries);
            int a = int.Parse(data[0]);
			int b = int.Parse(data[1]);
			Console.WriteLine ("{0}\n{1}\n{2}\n{3}\n{4}",a+b,a-b,a*b,a/b,a%b);
						
            Console.ReadLine();
        }
    }
	
}

