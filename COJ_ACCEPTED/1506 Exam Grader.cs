using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            int nq = int.Parse(Console.ReadLine());
            string answers = Console.ReadLine();
            int ns = int.Parse(Console.ReadLine());

            for (int i = 0; i < ns; i++)
            {
                double d = 0;
                string s = Console.ReadLine();
                for (int j = 0; j < answers.Length; j++)
                {
                    if (s[j] != '#' && answers[j] == s[j]) d += 1;
                    else if (s[j] != '#' && answers[j] != s[j]) d -= 0.25;
                }
                Console.WriteLine("{0:f2}",d);
            }

            Console.ReadLine();
        }
    }
}
