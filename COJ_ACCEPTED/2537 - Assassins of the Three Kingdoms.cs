using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Globalization;

namespace COJ
{
    class Program
    {
        /*
          Author: Luismo
          Problem: 2537 - Assassins of the Three Kingdoms
          Online Judge: COJ
          Idea: Brute Force, permutation of indexes and verify the conditions foreach permutation
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

        // static variables
        static int cnt = 0;
        static int[] preferences;
        static int[] permuntations;
        static bool[] taken;
        static bool[] locked;
        static int pavel;

        static void SolveSingleProblem()
        {
            int tc = int.Parse(Console.ReadLine());
            for (int t = 0; t < tc; t++)
            {
                int n = int.Parse(Console.ReadLine());
                // card preferences
                string[] data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                preferences = new int[data.Length];
                // data
                for (int i = 0; i < data.Length; i++)
                {
                    preferences[i] = int.Parse(data[i]);
                }

                pavel = preferences[0]; // favorite card for pavel
                cnt = 0; // counter
                // foreach permutation of indexes (order in players)
                // verify if pavel can get his favorite card
                taken = new bool[n];
                permuntations = new int[n]; // stores permutations

                BackTrack(0);

                Console.WriteLine(cnt);
            }
        }

        static void BackTrack(int idx)
        {

            // base case
            if (idx == preferences.Length)
            {
                // 
                locked = new bool[permuntations.Length];
                // scan to see if pavel can pick his favorite card
                for (int i = 0; i < permuntations.Length; i++)
                {
                    int currentPlayer = permuntations[i];
                    int currentCard = preferences[currentPlayer];

                    // if pavel's position
                    if (currentPlayer == 0)
                    {
                        // if not locked the pavel's favorite card
                        if (!locked[pavel])
                            cnt++;
                        // if was locked out this loop
                        break;
                    }
                    else
                    {
                        // if the current player's favorite card is locked (taken before)
                        // iterate until can use the following card
                        while (locked[currentCard])
                            currentCard = (currentCard + 1) % locked.Length;
                        // lock this card
                        locked[currentCard] = true;
                    }

                }
                return;
            }

            // foreach possible value to put in this index (idx)
            for (int i = 0; i < taken.Length; i++)
            {
                if (!taken[i])
                {
                    taken[i] = true;
                    permuntations[idx] = i;

                    BackTrack(idx + 1);

                    taken[i] = false;
                }
            }
        }



        #region Auxiliar Methods
        static void Swap(ref int a, ref int b)
        {
            int x = a;
            a = b;
            b = x;
        }

        static int Min(int a, int b)
        {
            return (a < b) ? a : b;
        }

        static int Max(int a, int b)
        {
            return (a > b) ? a : b;
        }

        static int Abs(int a)
        {
            return (a < 0) ? -1 * a : a;
        }
        #endregion

    }
}
