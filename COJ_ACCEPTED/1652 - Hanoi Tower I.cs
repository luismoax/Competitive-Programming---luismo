using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        //1652 Hanoi Tower I
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int moves = 0;
            HanoiTowers(n, 1, 2, 3,ref moves);
            Console.WriteLine("You needs {0} moves.",moves);
            Console.ReadLine();

        }

        static void HanoiTowers(int n, int stickOrigin, int stickAux, int stickDestiny,ref int moves)
        {
            if (n == 1)
            {
                Console.WriteLine("Move ring from stick {0} to stick {1}.", stickOrigin, stickDestiny);
                moves++;
                return;
            }
            else
            {
                HanoiTowers(n - 1, stickOrigin, stickDestiny, stickAux,ref moves);
                Console.WriteLine("Move ring from stick {0} to stick {1}.",stickOrigin,stickDestiny);
                moves++;
                HanoiTowers(n - 1, stickAux, stickOrigin, stickDestiny,ref moves);
            }
        }

    }

}

