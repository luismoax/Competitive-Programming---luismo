using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace COJ
{
    class Program
    {
        static void Main(string[] args)
        {            
            List<string> lst = new List<string>();
            
            string input = Console.ReadLine();
            while (input != "0")
            {
                if (Div11(input)) lst.Add(input+" is a multiple of 11.");
                else lst.Add(input + " is not a multiple of 11.");
                input = Console.ReadLine();
            }
            foreach (string item in lst)
            {
                Console.WriteLine(item);
            }
            Console.ReadLine();
        }

        static bool Div11(string n)
        {
            int fn = 0;
            for (int c = 0; c < n.Length; c++)
            {
                if (c % 2 == 0) fn += int.Parse(n[c].ToString());
                else fn -= int.Parse(n[c].ToString());              
            }
            return fn %11== 0;
        }
        
    }
}
