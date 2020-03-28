using System.Linq;
using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.BackgroundColor = ConsoleColor.Blue;
            Console.ForegroundColor = ConsoleColor.White;
            //string[] data = Console.ReadLine().Split(new char[]{' '},StringSplitOptions.RemoveEmptyEntries);
            int tc = int.Parse(Console.ReadLine());
			for (int t = 0; t < tc; t++)
			{
				string[] data = Console.ReadLine().Split(new char[]{' '},StringSplitOptions.RemoveEmptyEntries);
				
				int n = int.Parse(data[0]);
				int k = int.Parse(data[1]);
				int cnt=0;
				data = Console.ReadLine().Split(new char[]{' '},StringSplitOptions.RemoveEmptyEntries);
				int pole = int.Parse(data[k-1]);
				if(pole>0)
				{
					cnt = k;
					for (int i = k; i < data.Length && int.Parse (data[i]) == pole; i++)					
						cnt++;					
				}
				else
				{
					for (int i = 0; i < k && int.Parse (data[i])>0; i++) 
						cnt++;
				}
				Console.WriteLine (cnt);
            }			
            Console.ReadLine();
        }
    }
	
}

