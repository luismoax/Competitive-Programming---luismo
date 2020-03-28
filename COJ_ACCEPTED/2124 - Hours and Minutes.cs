using System;
using System.Globalization;
using System.IO;

namespace ter
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			TextReader tr = Console.In;
			//Console.SetIn(new StreamReader("/media/KIEV/in.lmo"));
			
			string xin="";
			while ((xin = Console.ReadLine())!=null)
			{	
				int n = int.Parse(xin.Trim());
				if(n%6==0)
					Console.WriteLine ("Y");
				else Console.WriteLine ("N");
			}
				
			Console.SetIn(tr);
			Console.ReadLine();
		}
	}
}
