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
          Problem: 2411 - Big World in Danger
          Online Judge: COJ
          Idea: Easy, use a dictionary to store planets' names with their respective distance from earth, and sort the distances so binary search can be done
		  to find the amount of planets that can be reached
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
            
            string[] data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            int n = int.Parse(data[0]);
            int q = int.Parse(data[1]);

            // stores planet-distance
            Dictionary<string, int> planetDistance = new Dictionary<string, int>();
            // distances
            int[] distances = new int[n];
            // reading planets
            for (int i = 0; i < n; i++)
            {
                data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                planetDistance.Add(data[0], int.Parse(data[1]));
                distances[i] = int.Parse(data[1]);
            }

            Array.Sort(distances);

            // reading queries
            for (int i = 0; i < q; i++)
            {
                data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);

                bool possible = false;
                int distanceCanTravel = 0;
                // if this planet is contained
                if (planetDistance.ContainsKey(data[0]))
                {
                    // calculate maximun posible distance
                    int weight = int.Parse(data[1]);
                    distanceCanTravel = 1 << (weight / 100);

                    double percent = (weight % 100) / 100.0 * distanceCanTravel;
                    distanceCanTravel += (int)percent;

                    if (distanceCanTravel >= planetDistance[data[0]])
                    {
                        Console.WriteLine("Yes");
                        possible = true;
                    }
                }

                if (!possible)
                {
                    int idx = Array.BinarySearch(distances, distanceCanTravel);
                    if (idx < 0)
                        idx = (idx * -1) - 1;
                    else idx++;

                    Console.WriteLine("No {0}", idx);
                }
            }
        }

    }

}

