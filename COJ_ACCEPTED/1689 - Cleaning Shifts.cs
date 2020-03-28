using System;
using System.Collections.Generic;
using System.Collections;

namespace COJ
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			
			string [] data = Console.ReadLine().Split(new char[]{' '},StringSplitOptions.RemoveEmptyEntries);
			int n = int.Parse (data[0]);
			int t = int.Parse (data[1]);
			List<Interval> intervals = new List<Interval>(n);
			
			List<int> list = new List<int>(n);
			int [] arr = new int[1000000];
			
			for (int i = 0; i < n; i++)
			{
				data = Console.ReadLine().Split(new char[]{' '},StringSplitOptions.RemoveEmptyEntries);
				int t1 = int.Parse (data[0]);
				int t2 = int.Parse (data[1]);
				
				if(arr[t1-1]==0)				
				{
					arr[t1-1] = t2;
					list.Add(t1);
				}
				else if(arr[t1-1] < t2)
					arr[t1-1] = t2;
				
			}
			
			for (int i = 0; i < list.Count; i++)
			{
				intervals.Add(new Interval(list[i],arr[list[i]-1])	);
			}
			
			intervals.Sort();
			
			
			int lastBite = 0,cnt=0,idx =0;
			
			while (lastBite < t)
			{
				int tmp = lastBite;
				for (int i = idx; i < intervals.Count && intervals[i].t1<=lastBite+1; i++)
				{
					if(intervals[i].t2>tmp)
					{
						tmp = intervals[i].t2;						
					}
					idx++;
				}
				if(tmp == lastBite)
				{
					cnt = -1;
					break;
				}
				else
				{
					lastBite = tmp;
					cnt++;
				}
			}
			
			Console.WriteLine (cnt);
			
			
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
			if(this.t1==other.t1)
				return other.t2.CompareTo(this.t2);
			return this.t1.CompareTo(other.t1);
		}	
		
		public override string ToString ()
		{
			return string.Format ("[{0},{1}]",t1,t2);
		}		
	}
}
