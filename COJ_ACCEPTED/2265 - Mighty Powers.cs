using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Collections;
using System.IO;

namespace consoleApp
{
    class Program
    {
    	// Author: LUISMO
    	// Idea: EASY Dynamic solution
        static void Main(string[] args)
        {

            string[] data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            int n = int.Parse(data[0]);
            long po = long.Parse(data[1]);
            data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);

            List<long> achieved = new List<long>(); // list of possible sums
            bool flag = false;

            // foreach number a add it to the last possible sums with the previous ones and save that sum
            // until i find the demanded sum
            for (int i = 0; i < n && !flag; i++)
            {
                long x = long.Parse(data[i]);
                if (x == po)
                {
                    flag = true;
                }

                if (!flag)
                {
                    int cnt = achieved.Count;
                    for (int j = 0; j < cnt && !flag; j++)
                    {
                        long k2 = achieved[j] + x;
                        if (k2 == po)
                        {
                            flag = true;
                            break;
                        }
                        achieved.Add(achieved[j] + x);
                    }
                }
                
                achieved.Add(x);
            }

            if(flag)
                Console.WriteLine("YES");
            else Console.WriteLine("NO");


            Console.ReadLine();
        }
    }


}
