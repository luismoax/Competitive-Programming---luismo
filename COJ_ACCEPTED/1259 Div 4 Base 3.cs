using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
			//1259 Div 4 Base 3
            int tc = int.Parse(Console.ReadLine());
            for (int i = 0; i < tc; i++)
            {
                string ax = Console.ReadLine();
                int imp = 0;
                int par = 0;
                for (int j = 0; j < ax.Length; j++)
                {
                    if (j % 2 == 0) par += int.Parse(ax[j].ToString());
                    else imp += int.Parse(ax[j].ToString());
                }

                if((imp-par)%4 ==0 ) Console.WriteLine("YES");
                else Console.WriteLine("NO");
            }

            Console.ReadLine();
        }
    }
}
