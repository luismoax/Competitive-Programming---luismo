using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;


namespace CompetitiveProgramming
{
    /*
     * Author: Luis Manuel Díaz Barón
     * Problem: 2163 - Blocks of Wood
     * Online Judge: COJ
     * Idea: Easy 
     * 
     * */

    class Program
    {
        static void Main(string[] args)
        {
            TextReader tr = Console.In;
            TextWriter tw = Console.Out;
            // Console.SetIn(new StreamReader(@"d:\lmo.in"));
            // Console.SetOut(new StreamWriter(@"d:\lmo.out"));


            SolveSingleProblem();

            Console.SetIn(tr);
            // Console.SetOut(tw);
            Console.ReadLine();
        }
        
        static void SolveSingleProblem()
        {
            int n = int.Parse(Console.ReadLine());
            int[] alph = new int[26];
            string[] data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);

            for (int i = 0; i < data.Length; i++)
                alph[i] = int.Parse(data[i]);

            for (int i = 0; i < n; i++)
            {
                string text = Console.ReadLine();
                int[] taken = new int[26];
                bool flag = true;
                for (int j = 0; j < text.Length; j++)
                {
                    if (text[j] != ' ')
                    {

                        taken[text[j] - 'a']++;
                        if (taken[text[j] - 'a'] > alph[text[j] - 'a'])
                        {
                            flag = false;
                            break;
                        }
                    }
                }
                if(!flag)
                    Console.WriteLine("NO");
                else Console.WriteLine("YES");
            }            
        }
    }
}
