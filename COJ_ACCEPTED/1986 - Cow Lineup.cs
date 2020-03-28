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
         * Idea: Dynamic. Mantain a interval with cows of all diferent IDs.
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
        static void SolveSingleProblem()
        {
            int n = int.Parse(Console.ReadLine());
            List<PosID> cows = new List<PosID>(); //

            // dictionary to dynamically keep the amount of cows per ID, already in the current interval
            Dictionary<int, int> dict = new Dictionary<int, int>();

            // reading data
            for (int c = 0; c < n; c++)
            {
                string[] data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                int x = int.Parse(data[0]);
                int id = int.Parse(data[1]);

                cows.Add(new PosID(x, id));

                // if this ID has not been registered, add it to de collection
                if (!dict.Keys.Contains(id))
                    dict.Add(id, 0);
            }

            cows.Sort();

            int idCnt = dict.Keys.Count; // amount of diferent Id

            int left = 0; // pointer for the first cow of the dynamic interval

            dict[cows[0].id]++; // increase the number of cows with the first ID

            int cnt = 1; // amounts of diferent cows found

            int min = int.MaxValue; // max interval
            for (int i = 1; i < n; i++)
            {

                PosID cow = cows[i];
                // if has the same Id of the first one in the current interval
                // pop out the first one (increase the pointer)
                if (cow.id == cows[left].id)
                    left++;
                else
                {
                    if (dict[cow.id] == 0)
                        cnt++;

                    dict[cow.id]++;
                }

                // if found a interval containing all cows, update it
                if (cnt == idCnt)
                {
                    // while the fist one in the current interval has 
                    // others with the same ID in the current interval
                    // pop out it and decrease their number 
                    while (dict[cows[left].id] > 1)
                    {
                        dict[cows[left].id]--;
                        left++;
                    }
                    // update the interval lenght
                    if (cows[i].x - cows[left].x < min)
                        min = cows[i].x - cows[left].x;
                }

            }
            // answer
            Console.WriteLine(min);
        }
    }

    class PosID : IComparable<PosID>
    {
        public int x, id;
        public PosID(int x, int id)
        {
            this.x = x;
            this.id = id;
        }

        public override string ToString()
        {
            return x + " " + id;
        }

        public int CompareTo(PosID other)
        {
            return this.x.CompareTo(other.x);
        }
    }

}
