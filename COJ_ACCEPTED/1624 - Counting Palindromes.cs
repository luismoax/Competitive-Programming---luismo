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
		 * Idea: Esto es una dinamica, 
		 * Uso un arreglo de int, donde la posicion i-esima tiene la menor cantidad de palindromos en
		 * lo que puedo descompones la cadena desde la primera posicion hasta la posicion i
		 * Lo que hago es para la i-esima posicion de la cadena
		 * comienzo a verificar desde la posicion j, primera posicion hasta ella misma, i, 
		 * si se puede formar un palindormo con los indices en la cadena desde j hasta i, 
		 * en tal caso la menor cantidad de descomponer en palindormos la cadena hasta la posicion i 
		 * seria equivalente a la menor manera de descomponer en palindromos desde la posicion 0 
		 * hasta j-1 (ya precalculada y almacenada en la posicion j-1) esto lo verifico para todo los
		 * palindromos que se me puedan formar entre la primera posicion e i y actualizo en el arreglo
		 * el menor resultado.
		 * El resultado final estara en la ultima posicion que indica la menor cantidad de palindromos en
		 * que se descompone la cadena completa [0....n-1]
		 * 
		 * Costo: O(n^3)
		 * 
		 * */
        static void Main(string[] args)
        {
            string s = Console.ReadLine();
			int [] arr = new int[s.Length];
			
			for (int i = 0; i < s.Length; i++)
			{				
				for (int j = 0; j <=i; j++)
				{					
					// Si es palindorme actualizo la suma
					if(IsPalindrome(s,j,i-j+1))
					{
						if(j==0)
							arr[i] = 1;
						else if(arr[j-1]+1 < arr[i] || arr[i]==0)
							arr[i] = arr[j-1]+1;						
					}
				}		
			}
			
			Console.WriteLine (arr[arr.Length-1]);			
			
			
            Console.ReadLine();
        }
		
		static bool IsPalindrome(string s,int idx,int count)
		{
			for (int i = 0; i < count/2; i++) 
			{
				if(s[i+idx]!= s[idx+count-i-1])	
					return false;
			}
			return true;
		}

    }
}
