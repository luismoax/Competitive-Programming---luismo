using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace COJ
{
    class Program
    {
		/*
		 * Author: Luismo
		 * 
		 * Problem: 1524 - WikiSpy F1
		 * 
		 * Idea: Backtrack forming numbers with the gigits, through all permutations
		 * the if a permutation is a prime number and has not been examined (case of permutations 
		 * with repetitions) count it.
		 * 
		 * */
		
		
		static string s="";
		static bool[] marks;
		static bool [] numbersTaken = new bool[10000000];
		static int cnt=0;
		
		
		
        static void Main(string[] args)
        {			
			int tc = int.Parse(Console.ReadLine());
		
			for (int i = 0; i < tc; i++) 
			{
				s = Console.ReadLine();
				marks = new bool[s.Length];
				cnt=0;
				numbersTaken = new bool[10000000];
			
				BackTrack("");
			
				Console.WriteLine (cnt);
			}
				
			Console.ReadLine();
        }
		
		static public void BackTrack(string build) 
		{			
			int k=-1;
			if(build!="")
				k = int.Parse(build);
			if(k>=2 && !numbersTaken[k]  && IsPrime(k) )
			{
				numbersTaken[k] = true;			
				cnt++;
			}
			// Case Base
			if(build.Length == s.Length)		
				return;		
		
			for (int i = 0; i < marks.Length; i++)
			{
				if(!marks[i])
				{					
					
					marks[i] = true;
									
					BackTrack(build+s[i]);					
					
					marks[i] = false;
				}
			}
				
		}
		
		
		static bool IsPrime(long n)
		{
			if(n==2 || n == 3)
				return true;
			if(n <2 || n%2==0 || n%3==0)
				return false;
			
			for (int i = 5; i*i <= n; i+=2)
			{
				if(n%i==0)	
					return false;
			}			
			return true;
		}
		
		
    }
	
	
}