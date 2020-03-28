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
            string[] p = Console.ReadLine().Split(' ');
            int a = int.Parse(p[0]);
            int b = int.Parse(p[1]);
            int c = int.Parse(p[2]);
            int d = int.Parse(p[3]);

            p = Console.ReadLine().Split(' ');
            int postman = int.Parse(p[0]);
            int mailman = int.Parse(p[1]);
            int garbageman = int.Parse(p[2]);

            int [] n = new int[3];
            if (postman % (a + b)>0 && postman % (a + b) <= a) n[0]++;
            if (postman % (c + d)>0 && postman % (c + d) <= c) n[0]++;

            if (mailman % (a + b) >0 && mailman % (a + b) <= a) n[1]++;
            if (mailman % (c + d) >0 &&mailman % (c + d) <= c) n[1]++;

            if (garbageman % (a + b) > 0 && garbageman % (a + b) <= a) n[2]++;
            if (garbageman % (c + d) > 0 && garbageman % (c + d) <= c) n[2]++;

            foreach (var item in n)
            {
                if (item == 1) Console.WriteLine("one");
                else if (item == 2) Console.WriteLine("both");
                else Console.WriteLine("none");
            }
            Console.ReadLine();
        }
    }
}
