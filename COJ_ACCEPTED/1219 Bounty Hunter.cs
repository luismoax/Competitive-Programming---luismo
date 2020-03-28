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
            //1219 Bounty Hunter
            int tc = int.Parse(Console.ReadLine());
            for (int c = 0; c < tc; c++)
            {
                string[] p = Console.ReadLine().Split(' ');
                int b = int.Parse(p[0]);
                int a = int.Parse(p[1]);
                int[] rewards = new int[a];
                for (int i = 0; i < a; i++)
                {
                    string[] pp = Console.ReadLine().Split(' ');
                    rewards[i] = int.Parse(pp[0]);
                }
                Array.Sort(rewards);
                long totalReward = 0;
                for (int i = 0; i < b; i++)
                {
                    totalReward += rewards[rewards.Length - 1 - i];
                }
                Console.WriteLine(totalReward);

            }
            
                      
            Console.ReadLine();
        }

    }
}
