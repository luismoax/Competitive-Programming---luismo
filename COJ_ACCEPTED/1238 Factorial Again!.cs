using System;
using System.Collections.Generic;
using System.Text;

namespace COJ
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = Console.ReadLine();
            List<string> lst = new List<string>();
            while (s!="-1")
            {
                string asd = "";
                int x = int.Parse(s);
                while (x > 1)
                {
                    asd = (x % 3) +asd;
                    x = x / 3;
                }
                asd = 1+asd;
                if (x == 0) asd = "0";
                lst.Add(asd);
                s = Console.ReadLine();
            }
            foreach (string var in lst)
            {
                Console.WriteLine(var);
            }
            
            
            Console.ReadLine();
        }
    }
}
