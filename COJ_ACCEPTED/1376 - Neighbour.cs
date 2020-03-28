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
		 * Idea: Se hace un backtrack permutando las posiciones de los digitos
		 * y nos vamos quedando con la mejor opcion en el caso base.		 * 
		 * 
		 * 
		 * */
		
		static int minMax = 1999999;
		static int sNumb=0;
		static bool [] mark;
		
		public static void Main (string[] args)
		{
			string s = Console.ReadLine();
			sNumb = int.Parse(s);
			mark = new bool[s.Length];
			
			BackTrack(s,"");
			if(minMax==1999999)
				Console.WriteLine (0);
			else Console.WriteLine (minMax);
						
			
			Console.ReadLine();
		}
		
		
		static void BackTrack(string s,string comp)			
		{
			if(comp.Length == s.Length)
			{
				int compNum = int.Parse(comp);
				if(compNum>sNumb && compNum < minMax)
					minMax = int.Parse(comp);				
				return;
			}
			
			for (int i = 0; i < s.Length; i++)
			{
				if(!mark[i])
				{
					mark[i] = true;
					BackTrack(s,comp+s[i]);
					mark[i] = false;
				}
			}
		}
	}
	
}
