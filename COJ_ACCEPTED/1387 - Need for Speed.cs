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
		 * Problem: 1387 - Need for Speed (Caribbean Online Judge)
		 * 
		 * Idea: Find the best permutation such tha the sum of all force divided by the
		 * sum of all mass is maximun
		 *
		 * */
		
		static double tmpMass,tmpForce,mass,force;
		
		static double acceleration;
		
		static CarPart [] parts;
		
		static int n;
		
		static List<int> bestIndexes = new List<int>();
		
		
        static void Main(string[] args)
        {
			TextReader tr = Console.In;
			
			string [] data = Console.ReadLine().Split(new char[]{' '});
			force = double.Parse(data[0]);
			mass = double.Parse(data[1]);
			
			n = int.Parse(data[2]);
			
			parts = new CarPart[n];
			
			for (int i = 0; i < n; i++)
			{
				data = Console.ReadLine().Split(new char[]{' '});
				parts[i] = new CarPart(double.Parse(data[0]),double.Parse(data[1]));
			}
			
			tmpForce = force;
			tmpMass  = mass;
			
			BessieBackTrack(0);
			
			for (int i = 0; i < bestIndexes.Count; i++)
			{
				if(i==0)
					Console.Write ((bestIndexes[i]+1));
				else Console.Write (" "+(bestIndexes[i]+1));
			}
			
			if(bestIndexes.Count==0)
				Console.WriteLine ("NONE");
						
			Console.SetIn(tr);
				
			Console.ReadLine();
        }
		
		static public void BessieBackTrack(int idx) 
		{	
			if(tmpForce/tmpMass>acceleration)
			{
				bestIndexes.Clear();
				for (int i = 0; i < parts.Length; i++)
					if(parts[i].enabled)
						bestIndexes.Add(i);
				
				acceleration = tmpForce/tmpMass;
			}
			
			if(idx==n)				
				return;
			
			parts[idx].enabled = true;
			tmpForce+=parts[idx].fi;
			tmpMass+=parts[idx].mi;
			
			BessieBackTrack(idx+1);
			
			parts[idx].enabled = false;
			tmpForce-=parts[idx].fi;
			tmpMass-=parts[idx].mi;
			
			BessieBackTrack(idx+1);			 
		}		
		
    }
	
	class CarPart
	{
		public double fi,mi;
		public bool enabled;
		
		public CarPart(double fi,double mi)
		{
			this.fi = fi;
			this.mi = mi;
			this.enabled = false;
		}
	}
	
	
}