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
		 * Problema: 2077
		 
		 * Idea: Had-Hoc
		 * 
		 * */
		
		
		public static void Main (string[] args)
		{
			int tc = int.Parse(Console.ReadLine());
			for (int k = 0; k < tc; k++) {
				
				int [,] mtHorz = new int[5,5]; // Matriz para las sumas horizontales
				int [,] mtVert = new int[5,5]; // Matriz para las sumas verticles
				
				int [,] mainDiag = new int[5,5]; // MAtriz para la diagonal principal
				int [,] secDiag = new int[5,5]; // MAtriz para la diagonal principal
				
				int [,] game = new int[5,5];
				
				bool Artuhum = false;
				bool Breece = false;
				
				for (int i = 0; i < 5; i++) 
				{
					string s = Console.ReadLine();
					for (int j = 0; j < s.Length; j++) 
					{
						if(s[j] == 'B')	
						{
							//Marcamos que hay una B
							game[i,j] = 0;
							if(j>0 && mtHorz[i,j-1] <0)
								mtHorz[i,j] = mtHorz[i,j-1]-1;
							else mtHorz[i,j] = -1;							
														
								
							//Verificando Vertical
							if(i>0 && mtVert[i-1,j]<0)
							{
								mtVert[i,j] = mtVert[i-1,j]-1;
							}
							else mtVert[i,j] = -1;
							
							
							//Verificando Diagonal principal
							if(i>0 && j>0 && mainDiag[i-1,j-1] <0)
							{
								mainDiag[i,j] = mainDiag[i-1,j-1]-1;
							}
							else mainDiag[i,j]= -1;
							
							// Verificando segunda Diagonal
							if(i>0 && j<4 && secDiag[i-1,j+1] <0)
							{
								secDiag[i,j] = secDiag[i-1,j+1]-1;
							}
							else secDiag[i,j]= -1;
							
							if(mtHorz[i,j] == -3 || mtVert[i,j] == -3 || secDiag[i,j]==-3 || mainDiag[i,j] == -3)
								Breece = true;
							
						}
						else
						{
							//Marcamos que hay una A
							game[i,j] = 1;
							if(j>0 && mtHorz[i,j-1] >0)
								mtHorz[i,j] = mtHorz[i,j-1]+1;	
							else mtHorz[i,j] = 1;
							
							
							//Verificando Vertical
							if(i>0 && mtVert[i-1,j]>0)
							{
								mtVert[i,j] = mtVert[i-1,j]+1;
							}
							else mtVert[i,j] = 1;
							
							
							
							
							//Verificando Diagonal principal
							if(i>0 && j>0 && mainDiag[i-1,j-1] >0)
							{
								mainDiag[i,j] = mainDiag[i-1,j-1]+1;
							}
							else mainDiag[i,j]= 1;
							
							// Verificando segunda Diagonal
							if(i>0 && j<4 && secDiag[i-1,j+1] >0)
							{
								secDiag[i,j] = secDiag[i-1,j+1]+1;
							}
							else secDiag[i,j]= 1;
							
							if(mtHorz[i,j] == 3 || mtVert[i,j] == 3 || secDiag[i,j]==3 || mainDiag[i,j] == 3)
								Artuhum = true;
							
						}
					}
				}
				
				//PrintMt(game);
				//Console.WriteLine ();
				//PrintMt(mtVert);
				//Console.WriteLine ();
				//PrintMt(mtHorz);
				
				if(Artuhum && Breece)
					Console.WriteLine ("draw");
				else if(Artuhum)
					Console.WriteLine ("A wins");
				else Console.WriteLine ("B wins");
				
				
			}
			Console.ReadLine();
		}
		
		static void PrintMt(int [,] mt)
		{
			for (int i = 0; i < mt.GetLength(0); i++)
			{
				for (int j = 0; j < mt.GetLength(1); j++)
				{
					Console.Write(mt[i,j]+" ");
				}	
				Console.WriteLine ();
			}
			Console.WriteLine ();
		}
		
		
	}
	
}

