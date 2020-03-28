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
            for (int t = 0; t < tc; t++)
            {
                string s = Console.ReadLine();
                int[] broken = new int[6];
                for (int i = 0; i < s.Length; i++)
                {
                    switch (s[i])
                    {
                        case 'B':
                            broken[0]++;
                            break;
                        case 'R':
                            broken[1]++;
                            break;
                        case 'O':
                            broken[2]++;
                            break;
                        case 'K':
                            broken[3]++;
                            break;
                        case 'E':
                            broken[4]++;
                            break;
                        case 'N':
                            broken[5]++;
                            break;
                        default:
                            break;
                    }
                }
                
                s = "No Secure";                
                for (int i = 1; i < broken.Length; i++)
                {
                    if (broken[i] != broken[0])
                    {
                        s = "Secure";
                        break;
                    }
                }
                Console.WriteLine(s);
            }

            Console.ReadLine();

        }
    }
}
