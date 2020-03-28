using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = Console.ReadLine();
            List<object> lst = new List<object>();
            while (s != null)
            {
                string ax = "";
                string bug = "BUG";
                bool foundBUG;
                do
                {
                    ax = "";
                    foundBUG = false;
                    for (int c = 0; c < s.Length; c++)
                    {
                        bool ft = true;
                        for (int d = 0; d < 3; d++)
                        {
                            if (!(s[c + d] == bug[d])) { ft = false; break; }
                        }
                        if (!ft) ax += s[c];
                        else { c += 2; foundBUG = true; }
                    }
                    s = ax;
                }
                while (foundBUG);

                Console.WriteLine(ax);

                s = Console.ReadLine();
            }
            
            Console.ReadLine();
        }
    }
}
