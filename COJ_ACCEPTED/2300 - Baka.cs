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
    	// Idea: Simple Ad-Hoc
        static void Main(string[] args)
        {
            
            string s = Console.ReadLine();
            int cnt = 0;
            for (int i = 0; i < s.Length; i++)
            {
                cnt += Time(s[i]);
            }
            Console.WriteLine(cnt);
            Console.ReadLine();
        }

        static int Time(char c)
        {
            if (c == 'A' || c == 'B' || c == 'C')
                return 3;

            if (c == 'D' || c == 'E' || c == 'F')
                return 4;

            if (c == 'G' || c == 'H' || c == 'I')
                return 5;

            if (c == 'J' || c == 'K' || c == 'L')
                return 6;

            if (c == 'M' || c == 'N' || c == 'O')
                return 7;

            if (c == 'P' || c == 'Q' || c == 'R' || c=='S')
                return 8;

            if (c == 'T' || c == 'U' || c == 'V')
                return 9;
            
            if (c == 'W' || c == 'X' || c == 'Y' || c=='Z')
                return 10;

            return 0;
        }


    }

    

}
