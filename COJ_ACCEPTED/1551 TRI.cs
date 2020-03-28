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
            string kinput = Console.ReadLine();
            int ind = 1;
            while (kinput!=null)
            {
                string[] p = kinput.Split(' ');
                int a = int.Parse(p[0]);
                int b = int.Parse(p[1]);
                int c = int.Parse(p[2]);

                #region A o B = C
                if (a + b == c) Console.WriteLine("Case "+ind+": "+a+"+"+b+"="+c);
				else if(a == b+c)  Console.WriteLine("Case "+ind+": "+a+"="+b+"+"+c);
				
                else if (a - b == c) Console.WriteLine("Case " + ind + ": " + a + "-" + b + "=" + c);
				else if (a == b - c) Console.WriteLine("Case " + ind + ": " + a + "=" + b + "-" + c);
				
                else if (a * b == c) Console.WriteLine("Case " + ind + ": " + a + "*" + b + "=" + c);
				else if (a == b * c) Console.WriteLine("Case " + ind + ": " + a + "=" + b + "*" + c);
                else if (b != 0 && a / b == c) Console.WriteLine("Case " + ind + ": " + a + "/" + b + "=" + c);
				else if (c!=0 && a == b / c) Console.WriteLine("Case " + ind + ": " + a + "=" + b + "/" + c);
                #endregion
                

                ind++;
                kinput = Console.ReadLine();
            }
            Console.ReadLine();
        }

        

    }
}
