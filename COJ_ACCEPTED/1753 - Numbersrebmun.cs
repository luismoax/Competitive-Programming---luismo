using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            int tc = int.Parse(Console.ReadLine());
            for (int c = 0; c < tc; c++)
            {
                string xin = Console.ReadLine();
                bool flag =true;
                for (int i = 0; i < xin.Length; i++)
                {
                    if(NLetter(xin[i].ToString()) != NLetter(xin[xin.Length-1-i].ToString()))
                    {
                        flag = false;
                        break;
                    }
                }
                if(flag) Console.WriteLine("YES");
                else Console.WriteLine("NO");
            }
        }

        static int NLetter(string ch)
        {
            ch = ch.ToLower();
            switch (ch)
            {
                case "a":
                    return 2;
                case "b":
                    return 2;
                case "c":
                    return 2;

                case "d":
                    return 3;
                case "e":
                    return 3;
                case "f":
                    return 3;

                case "g":
                    return 4;
                case "h":
                    return 4;
                case "i":
                    return 4;

                case "j":
                    return 5;
                case "k":
                    return 5;
                case "l":
                    return 5;

                case "m":
                    return 6;
                case "n":
                    return 6;
                case "o":
                    return 6;

                case "p":
                    return 7;
                case "q":
                    return 7;
                case "r":
                    return 7;
                case "s":
                    return 7;

                case "t":
                    return 8;
                case "u":
                    return 8;
                case "v":
                    return 8;

                case "w":
                    return 9;
                case "x":
                    return 9;
                case "y":
                    return 9;
                case "z":
                    return 9;
                
                default:
                    return -1;
                    break;
            }
        }


    }
}
