using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {

            string input = Console.ReadLine();
            List<object> lst = new List<object>();
            while (input != "0 0 0 0")
            {
                string[] p = input.Split(' ');
                int mnt = 0;

                int hh = int.Parse(p[2]) - int.Parse(p[0]);
                int mm = int.Parse(p[3]) - int.Parse(p[1]);

                if (hh > 0)
                {
                    mnt += 60 * hh;
                    mnt += int.Parse(p[3]);
                    mnt -= int.Parse(p[1]);
                }
                else if (hh < 0)
                {
                    mnt += (24 + hh) * 60;
                    mnt += int.Parse(p[3]);
                    mnt -= int.Parse(p[1]);
                }
                else
                {
                    if (mm < 0) mnt = 1440 + mm;
                    else mnt = mm;
                }
                

                lst.Add(mnt);
                input = Console.ReadLine();                
            }
            foreach (object var in lst)
            {
                Console.WriteLine(var);
            }
            Console.ReadLine();
        }
    }
}
