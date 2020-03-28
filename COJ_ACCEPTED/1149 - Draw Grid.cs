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
		 * Problema: 1149 - Draw Grid
		 * 
		 * Idea: Had-Hoc
		 * 
		 * */
		
		
		public static void Main (string[] args)
		{
			string xin="";
			int testCase =1;
			while (true)
			{
				
				string [] data = Console.ReadLine().Split(new char [] {' '},StringSplitOptions.RemoveEmptyEntries);
				int size = int.Parse(data[0]);
				int thickness = int.Parse(data[1]);
				int sizeOfTheGrid = int.Parse(data[2]);
				if(size+ sizeOfTheGrid+ thickness ==0)
					break;
			
				if(size+ thickness + sizeOfTheGrid == 0)
					break;
				Console.WriteLine("Case {0}:",testCase);
				string line = "";
				// Pintando por niveles
				for (int i = 0; i < sizeOfTheGrid; i++) 
				{					
					//Pintando l?neas superiores
					for(int j =0; j<thickness;j++)
					{
					
						for(int k =0; k<thickness*(sizeOfTheGrid+1) + size*sizeOfTheGrid;k++)
							//Console.Write("*");
							line+="*";
					
						Console.WriteLine (line);
						line="";
					}
				
					//Dibujando ahora la celda
					for (int j = 0; j < size; j++)
					{
						bool star = true;
						int cnt=1;
						for(int k =0; k<thickness*(sizeOfTheGrid+1) + size*sizeOfTheGrid;k++)
						{
						
							if(star)
								line+="*";
							else line+=".";
													
							
							if(star && cnt==thickness)
							{
								star = false;
								cnt =1;
							}
							else if(!star && cnt == size)
							{
								star = true;
								cnt=1;
							}
							else cnt++;
						
						}
						Console.WriteLine (line);
						line = "";
					}
					
				}
			
				//Dibujando ?ltimas l?neas
				for(int j =0; j<thickness;j++)
				{
				
					for(int k =0; k<thickness*(sizeOfTheGrid+1) + size*sizeOfTheGrid;k++)			
						line+="*";
					Console.WriteLine (line);
					line= "";
				}
				testCase++;
				Console.WriteLine ();
			
			}
			Console.ReadLine();
		}
		
		
	}
	
}
