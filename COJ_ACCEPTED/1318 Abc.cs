using System;
using System.Collections.Generic;
using System.Text;

namespace smtp
{
    class Program
    {
        static void Main(string[] args)
        {
            string input = Console.ReadLine();            
            int[] k = new int[3];
            for (int c = 0; c < 3; c++)
			{
                k[c] = int.Parse(input.Split(' ')[c]);
			}
            //O(9) - O(1)
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (k[j] > k[i]) 
                    {
                        int x = k[j];
                        k[j] = k[i];
                        k[i] = x;
                    }
                }
            }
            input = Console.ReadLine();
            string s = "";
            for (int i = 0; i < input.Length; i++)
            {
                if (input[i] == 'A') s += k[0] + " ";
                else if (input[i] == 'B') s += k[1] + " ";
                else if (input[i] == 'C') s += k[2] + " ";
            }
            Console.WriteLine(s);


            Console.ReadLine();
        }
    }
}

