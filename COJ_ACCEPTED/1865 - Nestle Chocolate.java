// Author: Luis Manuel Díaz Barón
// Problem: 1865 - Nestle Chocolate
// Idea: Save each substring of each code into a Dictionary<string, int> (the key is the substring and the Value it's frequency), 
// then every question should be answered indexing in the dictionary


using System;
using System.Collections.Generic;
using System.Collections;
using System.IO;

namespace CP
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			// StreamReader sr = new StreamReader("/media/luismo/Trabajo/lmo.in");
			TextReader tr = Console.In;

			// Console.SetIn (sr);


			Dictionary<string, int> dict = new Dictionary<string, int> ();

			int N = int.Parse (Console.ReadLine ());
			// reading chocolate
			for (int ch = 0; ch < N; ch++) 
			{
				string str = Console.ReadLine ();

				for (int i = 0; i < str.Length; i++) 
				{
					// size
					for (int sz = 1; sz <= str.Length; sz++) 
					{
						if (i + sz - 1 >= str.Length)
							break;

						string substr = str.Substring (i, sz);

						if (dict.ContainsKey (substr))
							dict [substr]++;
						else
							dict.Add (substr, 1);
					}
				}
			}

			// questions
			int M = int.Parse (Console.ReadLine ());

			for (int q = 0; q < M; q++) 
			{
				string str = Console.ReadLine ();

				Console.WriteLine ( (dict.ContainsKey(str))? dict[str] : 0);
			}

			Console.SetIn (tr);
			Console.ReadLine ();

		}
	}
}
