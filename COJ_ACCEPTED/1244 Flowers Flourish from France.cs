using System;
using System.Collections.Generic;
using System.Text;

namespace COJ
{
    class Program
    {
        static void Main(string[] args)
        {
            List<int> rslt = new List<int>();
            string s = Console.ReadLine();
            while (s!="0")
            {
                int k = 0;
                int fct = 1;
                for (int c = 0; c < s.Length; c++)
                {
                    fct = (c+1)*fct;
                    k += int.Parse(s[s.Length-1- c].ToString()) * fct;
                }
                rslt.Add(k);
                s = Console.ReadLine();
            }
            foreach (int var in rslt)
            {
                Console.WriteLine(var);                    
            }
            
            Console.ReadLine();
        }
    }
}
