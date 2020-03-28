	using System;
using System.Collections.Generic;
	using System.Linq;
	using System.Text;
	using System.IO;


namespace COJ
{
	class MainClass
	{
	    /// <summary>
	    /// Author: Luismo
	    /// Idea:
	    /// </summary>
	    /// <param name="args"></param>
		public static void Main(string[] args)
	    {
	        TextReader tr = Console.In;
	        //TextWriter tw = Console.Out;
	        //Console.SetIn(new StreamReader(@"/media/luismo/Trabajo/lmo.in"));
	        //Console.SetOut(new StreamWriter(@"d:\lmo.out"));
	        //string [] data = Console.ReadLine().Split(new char[]{' '},StringSplitOptions.RemoveEmptyEntries);

			string [] data = Console.ReadLine().Split(new char[]{' '},StringSplitOptions.RemoveEmptyEntries);

			int a = int.Parse(data[0].Replace("5","6")) + int.Parse(data[1].Replace("5","6"));
			int b = int.Parse(data[0].Replace("6","5")) + int.Parse(data[1].Replace("6","5"));

			Console.WriteLine ("{0} {1}",b,a);
	
	        //Console.Out.Close();
	        Console.SetIn (tr);
	        //Console.SetOut(tw);
	        Console.ReadLine();
	    }
	}

}