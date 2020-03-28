using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace COJ
{
    class Program
    {
        static void Main(string[] args)
        {         
            string[] p = Console.ReadLine().Split(' ');
            int rooms = int.Parse(p[0]);
            int groups = int.Parse(p[1]);
            int[] beds = new int[rooms];
            int bdind = 0;
            for (int c = 0; c < groups; c++)
            {
                int cnt = int.Parse(Console.ReadLine());
                while (cnt>0)
                {
                    bdind = bdind % beds.Length;
                    if (beds[bdind]==0)
                    {
                        if (cnt >= 2) { cnt -= 2; beds[bdind] = 2; }
                        else { cnt--; beds[bdind] = 1; }
                    }
                    else if (beds[bdind]== 1)
                    {
                        cnt--;
                        beds[bdind] = 2;
                    }
                    bdind++;
                }
            }
            foreach (object item in beds)
            {
                Console.WriteLine(item);
            }            
            Console.ReadLine();
        }

    }

}
