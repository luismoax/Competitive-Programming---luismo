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
            //string[] data = Console.ReadLine().Split(new char[]{' '},StringSplitOptions.RemoveEmptyEntries);
            int a = int.Parse(Console.ReadLine());
			for (int i = 0; i < a; i++) {
				string s = Console.ReadLine();
				if(int.Parse (s[s.Length-1].ToString ())%2==0)
					Console.WriteLine ("even");
				else Console.WriteLine ("odd");
			}			
            Console.ReadLine();
        }
    }
	
}

