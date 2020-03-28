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
            string[] data = Console.ReadLine().Split(new char[]{' '},StringSplitOptions.RemoveEmptyEntries);
            int p = int.Parse(data[0]);
            int q = int.Parse(data[1]);
            List<int> pss = new List<int>();
            for (int i = 1; i*i <=p ; i++)
            {
                if (i * i == p)
                    pss.Add(i);
                else if (p % i == 0)
                {
                    pss.Add(i);
                    pss.Add(p / i);
                }
            }
            List<int> qss = new List<int>();
            for (int i = 1; i * i <= q; i++)
            {
                if (i * i == q)
                    qss.Add(i);
                else if (q % i == 0)
                {
                    qss.Add(i);
                    qss.Add(q / i);
                }
            }
			pss.Sort();
			qss.Sort();
			for (int i = 0; i < pss.Count; i++)
			{
				for (int j = 0; j < qss.Count; j++)
				{
					Console.WriteLine ("{0} {1}",pss[i],qss[j]);	
				}
			}
			
            Console.ReadLine();
        }
    }
	
}

