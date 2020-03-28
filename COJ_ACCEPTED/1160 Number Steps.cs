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
            int tc = int.Parse(Console.ReadLine());
            List<object> rlst = new List<object>();
            for (int i = 0; i < tc; i++)
			{
                string[] p = Console.ReadLine().Split(' ');
                int x = int.Parse(p[0]);
                int y = int.Parse(p[1]);

                if ((x + y) % 2 == 1) rlst.Add("No Number");
                else if ((x - y) > 2 || x-y<0) rlst.Add("No Number");
                else if (x % 2 == 0) rlst.Add(x + y);
                else rlst.Add(x + y - 1);
			}
            foreach (object var in rlst)
            {
                Console.WriteLine(var);
            }
            Console.ReadLine();
        }
    }
}
