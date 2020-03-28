using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace COJ
{
    class Program
    {
		/*
		* Author: Luismo
		*
		* Problem: 2094 Blots on Paper
		*
		* Idea: Lee's Algorithm and while finding spot, turning it into false
		* (spot's cells will be true)
		*/
        static void Main(string[] args)
        {
            string [] data = Console.ReadLine().Split(new char[] {' '},StringSplitOptions.RemoveEmptyEntries);
			int m = int.Parse(data[0]);
			int n= int.Parse(data[1]);
			
			bool [,] mt = new bool[m,n]; // Table
			for (int i = 0; i < m; i++) // Filling table matrix
			{
				string xin = Console.ReadLine();
				for (int j = 0; j < xin.Length; j++)
				{
					if(xin[j] == '1')	
						mt[i,j] = true;
				}
			}
			
			int cnt = 0;
			int max = 0;
			for (int i = 0; i < m; i++) // Filling table matrix
			{
				
				for (int j = 0; j < n; j++)
				{
					if(mt[i,j])
					{   
						cnt++;
						int k = SpotArea(mt,i,j);
						if(k > max)
							max = k;
					}
				}
			}
			
			Console.WriteLine ("{0} {1}",cnt,max);
			
				
			Console.ReadLine();
        }
		
		static int SpotArea(bool [,] mt, int x,int y)
		{
			int k=0;
			Queue<Pair> q = new Queue<Pair>();
			q.Enqueue(new Pair(x,y));
			//k++;
			
			// Direction arrays
			int [] xfor = {1,-1,0,0};
			int [] yfor = {0,0,1,-1};
			
			mt[x,y] = false;
			
			while(q.Count>0)
			{
				Pair p = q.Dequeue();
				//mt[p.x,p.y] = false;
				k++;
				for (int i = 0; i < 4; i++) 
				{
					int tmpx = p.x+xfor[i];
					int tmpy = p.y + yfor[i];
					
					// If is a valid position
					if(tmpx >=0 &&  tmpx< mt.GetLength(0) && tmpy>=0 && tmpy < mt.GetLength(1) && mt[tmpx,tmpy])
					{
						mt[tmpx,tmpy] = false;
						q.Enqueue(new Pair(tmpx,tmpy));
					}
				}
			}				
			
			return k;
		}
    }
	
	class Pair
	{
		public int x,y;
		public Pair(int x,int y)
		{
			this.x = x;
			this.y = y;
		}
	}
		
		
	
}