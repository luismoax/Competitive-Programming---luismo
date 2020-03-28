using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
		/*
		 * Autor: luismo
		 * 
		 * Idea: Mientras estoy leyendo los valores voy dinamicamente actualizando
		 * en la fila inferior si alguna de sus casillas tiene menor valor que el actual,
		 * luego este valor que leo se lo sumo al que ya tengo previamente calculado con el mismo
		 * procedimiento
		 * 
		 * Costo: O(n^2)
		 * 
		 * */
        static void Main(string[] args)
        {
            int tc = int.Parse (Console.ReadLine());
			for (int t = 0; t < tc; t++)
			{
				string [] data = Console.ReadLine().Split(new char[]{' '},StringSplitOptions.RemoveEmptyEntries);
				int h= int.Parse(data[0]);
				int w = int.Parse(data[1]);
				
				int mx=0;
				int [,] mt = new int[h,w];
				
				for (int i = 0; i < h; i++)
				{
					data = Console.ReadLine().Split(new char[]{' '},StringSplitOptions.RemoveEmptyEntries);
					for (int j = 0; j < data.Length; j++)
					{
						// Anyando el valor leido al anteriormente precalculado como maximo
						mt[i,j] += int.Parse(data[j]);
						// En caso de que no sea la ultima fila
						if(i<h-1)
						{
							// Voy actulizando los valores
							for (int k = -1; k < 2; k++)
							{
								if(j+k >=0 && j+k<w && mt[i,j] > mt[i+1,j+k])	
									mt[i+1,j+k] = mt[i,j];
							}
						}
					}
				}
				//Busco el maximo de la ultima fila	
				mx =0;
				for (int i = 0; i < w; i++)
				{
					if(mt[h-1,i]>mx)					
						mx = mt[h-1,i];
				}
				
				Console.WriteLine (mx);
			}

            Console.ReadLine();
        }

    }
}
