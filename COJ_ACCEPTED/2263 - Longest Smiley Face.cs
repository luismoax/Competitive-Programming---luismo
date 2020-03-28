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
    	// This solution is ugly but works lol LUISMO
        static void Main(string[] args)
        {
            string[] data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            int tc = int.Parse(data[0]);
            // foreach test case
            for (int i = 0; i < tc; i++)
            {
                string s = Console.ReadLine();
                
                int cnt = 0; // length of the current smile
                int largest = 0; // largest smile

		// true for Jennifer false for Alan
                bool winner = true;
                bool current = true;

		// 
                for (int j = 0; j <= s.Length; j++)
                {
                    if (j > 0)
                    {
                    	// if the current position marks a change of player or the end of the game
                        if (j==s.Length ||  s[j] == ':' && s[j - 1] == ')')
                        {
                            if (cnt > largest)
                            {
                                largest = cnt;
                                winner = current;
                            }
                            cnt = 1;
                            current = !current;
                        }
                        else cnt++;
                    }
                    else cnt++;
                }

                if (winner)
                    Console.WriteLine("Jennifer");
                else Console.WriteLine("Alan");

            }

            Console.ReadLine();
        }


    }
}
