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
		* Problem: 2099 - Roman Cities
		*
		* Idea: Ad-hoc, convert from decimal to roman, and figure out how to convert
		* from Roman years to ours. Return the long of  the longest roman number
		*
		**/
		
        static void Main(string[] args)
        {
			TextReader tr = Console.In;
			
			//Console.SetIn(new StreamReader(@"d:\x.in"));
			
			string [] data = Console.ReadLine().Split(new char[]{'-'},StringSplitOptions.RemoveEmptyEntries);
			int year1 = int.Parse(data[0].Substring(0,data[0].Length-2));
			int year2 = int.Parse(data[1].Substring(0,data[1].Length-2));
			
			if(data[0].Substring(data[0].Length-2,2) == "BC")
			{
				year1 = Math.Abs(year1 - 753) + 1;
			}
			else
			{
				year1 = Math.Abs(year1+753);
			}
			
			
			if(data[1].Substring(data[1].Length-2,2) == "BC")
			{
				year2 = Math.Abs(year2 - 753) + 1;
			}
			else
			{
				year2 = Math.Abs(year2+753);
			}
			
			char [] Cha = {'I','V','X','L','C','D','M'};
			bool [] arr = new bool[Cha.Length];
			int cnt = 0;
			
			//Console.WriteLine (year1 + " "+year2);
			for (int i = year1; i <= year2; i++)
			{
				string s = ToRoman(i);
				if(s.Length > cnt)
					cnt = s.Length;
			}
			
			
            Console.WriteLine (cnt);
			
			Console.SetIn(tr);
				
			Console.ReadLine();
        }
		
	
		static string ToRoman(int n)
		{
			if(n==1)
				return "I";
			
			int millars = n/1000;
			
			n%=1000;
			
			int cents = n/100;
			
			n%=100;
			
			int dec = n/10;
			
			n%=10;
			
			int units = n;
			
			string s= "";
			
			//Adding M
			for (int i = 0; i < millars; i++)
				s+="M";
			//Adding Cents
			if(cents == 9)
				s+="CM";
			else if(cents == 8)
				s+="DCCC";
			else if(cents == 7)
				s+="DCC";
			else if(cents == 6)
				s+="DC";
			else if(cents == 5)
				s+="D";
			else if(cents == 4)
				s+="CD";
			else 
			{
				for (int i = 0; i < cents; i++)
					s+="C";
				
			}
			
			
			// Adding Decenes
			
			
			if(dec == 9)
				s+="XC";
			else if(dec == 8)
				s+="LXXX";
			else if(dec == 7)
				s+="LXX";
			else if(dec == 6)
				s+="LX";
			else if(dec == 5)
				s+="L";
			else if(dec == 4)
				s+="XL";
			else 
			{
				for (int i = 0; i < dec; i++)
					s+="X";				
			}
			
			// Adding Units
			
			if(units == 9)
				s+="IX";
			else if(units == 8)
				s+="VIII";
			else if(units == 7)
				s+="VII";
			else if(units == 6)
				s+="VI";
			else if(units == 5)
				s+="V";
			else if(units == 4)
				s+="IV";
			else 
			{
				for (int i = 0; i < units; i++)
					s+="I";				
			}
			
			
			return s;
			
		}
		
		
    }
	
	
}