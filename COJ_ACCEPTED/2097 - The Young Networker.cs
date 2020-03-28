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
		* Problem: 2097 - The Young Networker
		*
		* Idea: Ad-Hoc watch when connecting 2 hubs
		**/
        static void Main(string[] args)
        {
			TextReader tr = Console.In;
			//Console.SetIn(new StreamReader(@"d:\x.in"));
			
            string [] data = Console.ReadLine().Split(new char[] {' '},StringSplitOptions.RemoveEmptyEntries);
			int users = int.Parse(data[0]);
			int hubs = int.Parse(data[1]);
			
			Pair [] collection = new Pair[hubs];
			
			data = Console.ReadLine().Split(new char[] {' '},StringSplitOptions.RemoveEmptyEntries);
			for (int i = 0; i < data.Length; i++) {
				
				collection[i] = new Pair(int.Parse(data[i]),i+1);
				
			}
			
			List<int> hubsIndexes = new List<int>();
			
			Array.Sort(collection);
			
			for (int i = 0; i < collection.Length; i++) 
			{
				if(i>0)
				{
					collection[i].Val--;
				}
				
				if(users<=collection[i].Val)
				{
					hubsIndexes.Add(collection[i].Index);
					users = 0;
					break;
				}
				else
				{
					hubsIndexes.Add(collection[i].Index);
					users -= collection[i].Val -1;
				}
			}
			
			if(users > 0)
				Console.WriteLine ("Epic fail");
			else
			{
				//hubsIndexes.Sort();
				Console.WriteLine (hubsIndexes.Count);
				for (int i = 0; i < hubsIndexes.Count; i++) 
				{
					if(i==0)
						Console.Write(hubsIndexes[ i]);
					else Console.Write(" "+hubsIndexes[i]);
				}				
			}
			
			
			Console.SetIn(tr);
				
			Console.ReadLine();
        }		
		
    }
	
	class Pair:IComparable<Pair>
	{
		public int Val,Index;
		public Pair(int x,int y)
		{
			this.Val = x;
			this.Index = y;
		}
		
		public int CompareTo(Pair other)
		{
			if(this.Val == other.Val)
				return other.Index.CompareTo(this.Index);
			return other.Val.CompareTo(this.Val);
		}
	}
		
		
	
}