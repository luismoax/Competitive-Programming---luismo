using System;
using System.Collections.Generic;
using System.Collections;
using System.Globalization;

namespace COJ
{
	class MainClass
	{
		/**
	 	* Author LUISMO
	 	* 
	 	* Problem: 2062 - Pyramid's Maintenance
	 	* 
	 	* Idea: Se calcula a traves de la ley de los senos el valor de la cuerda para 
	 	* el triangulo original, luego este se reduce en altura y por tanto sus lados se reducen
	 	* con estas nuevas dimensiones repito el calculo hasta que el valor a sumar sea execivamente pequeno
	 	*
	 	* Complejidad: 
	 	*/
		public static void Main (string[] args)
		{
			int tc = int.Parse (Console.ReadLine());
			for (int t = 0; t < tc; t++)
			{
				string [] xin = Console.ReadLine ().Split(new char[]{' '},StringSplitOptions.RemoveEmptyEntries);
				int alfaGrados = int.Parse (xin[0]);
				int lado = int.Parse (xin[1]);
				// Valor execisvamente pequeno
				double epsilon = 0.000000001;				
				double c=0,b=lado,total=0;			
				
				do
				{
					// Angulo beta
					double betaGrados = 180 - (60+alfaGrados);
					double sinBeta = Math.Sin(ToRadians (betaGrados));
					double sinAlfa = Math.Sin(ToRadians (alfaGrados));
					// Calculamos el valor de la cuerda
					c= Math.Sqrt(3)/2 * b/sinBeta;
					total +=c;					
					// Actualizamos el valor de la base del nuevo triangulo					
					b -= sinAlfa*b/sinBeta;
				}
				while(c>epsilon);
											
				Console.WriteLine ("{0:#.0000}",total);
			}
			
			Console.ReadLine();
		}
		
		static double ToRadians(double angle)
		{
			return angle * Math.PI/180;
		}
		
	}
}
