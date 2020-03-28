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
            //1466 Vasha Game
            string[] p = Console.ReadLine().Split(' ');
            int x100 = int.Parse(p[0]);
            int y10 = int.Parse(p[1]);

            bool posible = true;
            bool vasha = true;
            while (posible)
            {
                if (y10 < 2 || (x100 == 0 && y10 < 22) || (x100 == 1 && y10 < 12)) posible = false;
                else if (vasha)
                {
                    if (x100 >= 2) { x100 -= 2; y10 -= 2; }
                    else if (x100 == 1) { x100--; y10 -= 12; }
                    else y10 -= 22;
                }
                else
                {
                    if (y10 >= 22) y10 -= 22;
                    else if (y10 >= 12) { y10 -= 12; x100 -= 1; }
                    else { y10 -= 2; x100 -= 2; }
                }
                vasha = !vasha;
            }

            if (vasha) Console.WriteLine("Vasha");
            else Console.WriteLine("Golek");
            Console.ReadLine();
        }

    }
}
