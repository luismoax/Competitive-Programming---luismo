using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace COJ
{
    class Program
    {
        /*
          Author: Luismo
          Problem: 2459 - Not Repeating Word Game
          Online Judge: COJ
          Idea: Easy Ad-Hoc, use a Dictionary to store Words with frequency
        */


        static void Main(string[] args)
        {
            TextReader tr = Console.In;
            TextWriter tw = Console.Out;

            // Console.SetIn(new StreamReader(@"d:\lmo.in"));

            SolveSingleProblem();
                       

            Console.SetIn(tr);
            Console.SetOut(tw);
            Console.ReadLine();

            //string[] data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
        }

        static void SolveSingleProblem()
        {
            string xin = "";

            while (xin!=null && !string.IsNullOrEmpty(xin = Console.ReadLine()))
            {
                Dictionary<string, int> dict = new Dictionary<string, int>();

                string [] Aplayer = xin.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                for (int i = 0; i < Aplayer.Length; i++)
                    dict.Add(Aplayer[i], 1);

                string [] Bplayer = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                for (int i = 0; i < Bplayer.Length; i++)
                {
                    if(dict.ContainsKey(Bplayer[i]))
                        dict[Bplayer[i]]++;
                    else dict.Add(Bplayer[i],1);
                }


                string [] Cplayer = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                for (int i = 0; i < Cplayer.Length; i++)
                {
                    if (dict.ContainsKey(Cplayer[i]))
                        dict[Cplayer[i]]++;
                    else dict.Add(Cplayer[i], 1);
                }

                // players' points
                int A=0, B=0, C = 0;
                // scanning each players' words
                // Player A
                for (int i = 0; i < Aplayer.Length; i++)
                {
                    int freq = dict[Aplayer[i]];
                    A += 4 - freq;
                }

                // Player B
                for (int i = 0; i < Bplayer.Length; i++)
                {
                    int freq = dict[Bplayer[i]];
                    B += 4 - freq;
                }

                // Player C
                for (int i = 0; i < Cplayer.Length; i++)
                {
                    int freq = dict[Cplayer[i]];
                    C += 4 - freq;
                }


                Console.WriteLine("{0}/{1}/{2}",A,B,C);

                // read blank line
                xin = Console.ReadLine();
            }

        }

    }



}
