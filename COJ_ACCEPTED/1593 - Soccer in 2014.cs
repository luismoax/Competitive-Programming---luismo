using System;
using System.Collections.Generic;
using System.Collections;

namespace COJ
{
	class MainClass
	{
		/**
	 	* @author LUISMO
	 	* 
	 	* Problem: Soccer In 2014
	 	* 
	 	* Idea: La idea sobre este problema es tomar los intervalos
	 	* y ordenarlos despu?s por el tiempo de inicio, una vez hecho
	 	* esto se reduce el problema a Longest Increasing Sequence (LIS) 
	 	* 
	 	* Complejidad: O(n^2)	 	 
	 	*/
		public static void Main (string[] args)
		{	
			int tc = int.Parse (Console.ReadLine());
			for (int t = 0; t < tc; t++)
			{
				int c = int.Parse (Console.ReadLine())	;				
				Interval [] intervals = new Interval[c];  
				for (int i = 0; i < c; i++)
				{
					string [] data = Console.ReadLine().Split(new char[]{' '},StringSplitOptions.RemoveEmptyEntries);
					int t1 = int.Parse (data[1]);
					int t2 = int.Parse (data[2]);
					intervals[i] = new Interval(t1,t1+t2 );					
				}
								
				// Sort the intervals then apply LIS
				Array.Sort(intervals);
				
				int[] arr = new int[c];				
				int max = 0;
				for (int i = c-1; i >=0; i--)
				{
					for (int j = i+1; j < c; j++)
					{
						if(intervals[i].t2 <= intervals[j].t1)							
						{
							if(arr[i] < 1+ arr[j])
								arr[i] = arr[j]+1;
						}
					}
					if(arr[i]>max)
						max = arr[i];
				}
				Console.WriteLine (max+1);
				if(t<tc-1)
					Console.WriteLine ();				
			}			
			
			Console.ReadLine();
		}
	}
	
	class Interval:IComparable<Interval>
	{
		public int t1,t2;
		public Interval(int t1,int t2)
		{
			this.t1 = t1;
			this.t2 = t2;
		}
		
		public int CompareTo (Interval other)
		{
			return this.t1.CompareTo(other.t1);
		}
		
		public override string ToString ()
		{
			return string.Format ("[{0},{1}]",t1,t2);
		}		
	}
}
