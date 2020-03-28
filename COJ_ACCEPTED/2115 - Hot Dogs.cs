using System;
using System.Globalization;

namespace ter
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			string xin="";
			while ((xin = Console.ReadLine())!=null)
			{
				
				string [] data = xin.Split(new char[]{' '},StringSplitOptions.RemoveEmptyEntries);
				Console.WriteLine ("{0:0.00}",double.Parse(data[0])/double.Parse(data[1]));						
			}
			Console.ReadLine();
		}
	}
}
