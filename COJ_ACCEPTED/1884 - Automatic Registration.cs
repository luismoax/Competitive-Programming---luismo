using System.Linq;
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
            Console.BackgroundColor = ConsoleColor.Blue;
            Console.ForegroundColor = ConsoleColor.White;

            string[] p = Console.ReadLine().Split(' ');
            int n = int.Parse(p[0]);
            string keyWord = p[1];
            int t = int.Parse(Console.ReadLine());
            List<string> lst = new List<string>();
            for (int i = 0; i < t && n > 0; i++)
            {
                string ax = Console.ReadLine();
                if (ax.ToLower().Contains(keyWord.ToLower()))
                {
                    lst.Add(ax);
                    n--;
                }
            }
            lst.Sort();

            foreach (var item in lst)
                Console.WriteLine(item);

            Console.ReadLine();
        }
    }

}

