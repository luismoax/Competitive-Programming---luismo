using System;
using System.Collections.Generic;
using System.Text;

namespace CA
{
    class Program
    {

        static void Main(string[] args)
        {
            string input = Console.ReadLine();
            List<string> lst = new List<string>();
            while (input!="0")
            {
                int nCol = int.Parse(input);
                string s = Console.ReadLine();

                string k = "";
                for (int c = 0; c < s.Length/nCol; c++)
                {
                    for (int d = 0; d < nCol; d++)
                    {
                        Console.WriteLine(s[d*s.Length/nCol + c]);
                    }
                }
                
                lst.Add(k);
                input = Console.ReadLine();
            }
            foreach (string var in lst)
            {
                Console.WriteLine(var);
            }



            Console.ReadLine();            
        }

    }
}