using System;
using System.Collections.Generic;
using System.Collections;
using System.IO;

namespace ConsoleApp
{
	class MainClass
	{
		/*
		 * Autor: Luismo
		 * 
		 * Idea: Had-Hoc
		 * 
		 * */
		
		
		public static void Main (string[] args)
		{
			string xin="";
			while ((xin = Console.ReadLine())!="0 0")
			{
				string [] data = xin.Split(new char [] {' '},StringSplitOptions.RemoveEmptyEntries);
				if(data[0].Length > data[1].Length)
				{
					string aux = data[0];
					data[0] = data[1];
					data[1] = aux;
				}
				data[0] = data[0].PadLeft(data[1].Length,'0');
				
				int cnt =0,carry=0;
				
				for (int i = 0; i < data[1].Length; i++)
				{
					
					int x = int.Parse(data[0][data[0].Length-1-i].ToString());
					int y = int.Parse(data[1][data[1].Length-1-i].ToString());					                  
				
					
					carry = ( x+ y + carry) /10;
				
					if(carry>=1)
						cnt++;
				}
				if(cnt ==0)
					Console.WriteLine ("No carry operation.");
				else if(cnt == 1)
					Console.WriteLine ("1 carry operation.");
				else Console.WriteLine ("{0} carry operations.",cnt);
			}
			Console.ReadLine();
		}
		
		
	}
	
}
