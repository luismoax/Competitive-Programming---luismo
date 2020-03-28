using System;

namespace ConsoleApp
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			string xin = "";
			while ((xin = Console.ReadLine()) !="END") 
			{
				
				int i=0;
				while (xin!="1") {
					i++;
					xin = xin.ToString ().Length.ToString();
				}
				Console.WriteLine (i+1);
			}
			
			Console.ReadLine();
		}
	}
}
