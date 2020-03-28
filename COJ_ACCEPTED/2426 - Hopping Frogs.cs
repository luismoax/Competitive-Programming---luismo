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
         * Author: Luismo
		 * Problem: 2426 - Hopping Frogs
         * Idea: BFS over states, each configuration is a node, from the first configuration, make BFS where every next
		 * 		 possible configuration has 1 step more
         * 
         * */


        static void Main(string[] args)
        {
            //string[] data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            TextReader tr = Console.In;
            //Console.SetIn(new StreamReader(@"d:\lmo.in"));

            SolveSingleProblem();

            Console.SetIn(tr);
            Console.ReadLine();
        }


        // static variables
        static string original = "";
        static string goal = "";
        static int minStep = int.MaxValue;
        static Dictionary<string, int> dict;
        static void SolveSingleProblem()
        {
            dict = new Dictionary<string, int>();
            int tc = int.Parse(Console.ReadLine());
            for (int t = 0; t < tc; t++)
            {
                Console.ReadLine();
                dict = new Dictionary<string, int>(); // reset the dictionary
                minStep = int.MaxValue; // reset variable for min steps

                // reading data
                original = Console.ReadLine();
                goal = Console.ReadLine();

                // BackTrack
                //BackTrack(original, 0);
                minStep = BFS();

                if (minStep !=-1)
                    Console.WriteLine("Case {0}: {1}", t + 1, minStep);
                else Console.WriteLine("Case {0}: {1}", t + 1, "impossible"); // burner
                
            }
        }

        static int BFS()
        {
            Queue<string> q = new Queue<string>();
            q.Enqueue(original);
            // add the original position with 0 steps
            dict.Add(original, 0);

            // BFS
            while (q.Count>0)
            {
                string current = q.Dequeue();
                int step = dict[current];
                // if reached
                if (string.CompareOrdinal(current, goal) == 0)
                    return step;

                
                // iterate through current state
                for (int i = 0; i < current.Length; i++)
                {
                    // if found a dot
                    if (current[i] == '.')
                    {
                        // if can move 1 cell right
                        if (Move1CellRight(current, i))
                        {
                            // new state
                            string nState = SwapChars(current, i, i + 1);
                            if (!dict.ContainsKey(nState))
                            {
                                q.Enqueue(nState);
                                dict.Add(nState, step + 1);
                            }
                        }

                        // if can move 2 cells right
                        if (Move2CellsRight(current, i))
                        {
                            string nState = SwapChars(current, i, i + 2);
                            if (!dict.ContainsKey(nState))
                            {
                                q.Enqueue(nState);
                                dict.Add(nState, step + 1);
                            }
                        }

                        // if can move 1 cell left
                        if (Move1CellLeft(current, i))
                        {
                            string nState = SwapChars(current, i,i - 1);
                            if (!dict.ContainsKey(nState))
                            {
                                q.Enqueue(nState);
                                dict.Add(nState, step + 1);
                            }
                        }
                        // if can move 2 cells left
                        if (Move2CellsLeft(current, i))
                        {
                            string nState = SwapChars(current, i, i - 2);
                            if (!dict.ContainsKey(nState))
                            {
                                q.Enqueue(nState);
                                dict.Add(nState, step + 1);
                            }
                        }


                    }

                }

            }


            return -1;
        }

        static bool Move1CellRight(string state, int i)
        {
            return i < state.Length - 1 && (state[i + 1] == 'G' || state[i + 1] == 'R');
        }

        static bool Move2CellsRight(string state, int i)
        {
            return
                i < state.Length - 2 && state[i + 1] != '.' && (state[i + 2] == 'G' || state[i + 2] == 'R');
        }

        static bool Move1CellLeft(string state, int i)
        {
            return i > 0 && (state[i - 1] == 'B' || state[i - 1] == 'R');
        }

        static bool Move2CellsLeft(string state,int i)
        {
            return
                i > 1 && state[i - 1] != '.' && (state[i - 2] == 'B' || state[i - 2] == 'R');
        }


        static string SwapChars(string str, int i, int j)
        {
            char[] arr = str.ToCharArray();
            char caux = arr[i];
            arr[i] = arr[j];
            arr[j] = caux;
            return new String(arr);
        }

    }

}
