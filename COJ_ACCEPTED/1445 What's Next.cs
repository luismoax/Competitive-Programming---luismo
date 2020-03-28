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
            while (input!="0 0 0")
            {
                string[] p = input.Split(' ');
                int a = int.Parse(p[0]);
                int b = int.Parse(p[1]);
                int c = int.Parse(p[2]);

                if(c == a+(2*(b-a)))
                    lst.Add("AP "+(c+(b-a)));
                else lst.Add("GP " + c * b / a);
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
