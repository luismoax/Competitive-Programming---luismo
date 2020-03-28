using System;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            //1441 Egypt
            string kinput = Console.ReadLine();            
            while (kinput!="0 0 0")
            {
                string[] p = kinput.Split(' ');
                int a = int.Parse(p[0]);
                int b = int.Parse(p[1]);
                int c = int.Parse(p[2]);
                if (a * a == b * b + c * c || b * b == a * a + c * c || c * c == a * a + b * b) Console.WriteLine("right");
                else Console.WriteLine("wrong");
                kinput = Console.ReadLine();
            }
            Console.ReadLine();
        }
    }
}
