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


			//Console.WriteLine (Char.ConvertFromUtf32(97));


			int tc = int.Parse(Console.ReadLine());
			for (int t = 0; t < tc; t++) 
			{
				string [] data = Console.ReadLine().Split(new char[]{' '},StringSplitOptions.RemoveEmptyEntries);					
				int [] freq = new int[data.Length];



				for (int i = 0; i < freq.Length; i++) 
				{
					freq[i] = int.Parse(data[i]);
				}

				Array.Sort(freq);
				// use of this class
				StringBuilder sb = new StringBuilder();

				for (int i = freq.Length-1; i >= 0; i--) 
				{
					//string xty = Char.ConvertFromUtf32(97+i);
					sb.Append((char)(97+i),freq[i]);
				}

				Console.WriteLine (sb.ToString());

			}


	
	        //Console.Out.Close();
	        Console.SetIn (tr);
	        //Console.SetOut(tw);
	        Console.ReadLine();
	    }
	}

}