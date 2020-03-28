using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            //1285 Final Standings
            List<SolvedProbleID> lst = new List<SolvedProbleID>();
            int n = int.Parse(Console.ReadLine());
            for (int i = 0; i < n; i++)
            {
                string[] p = Console.ReadLine().Split(' ');
                lst.Add(new SolvedProbleID(p[0], int.Parse(p[1]),i+1));
            }
            lst.Sort();
            for (int i = 0; i<lst.Count; i++)
            {
                Console.WriteLine(lst[i]);
            }

            Console.ReadLine();
        }
    }


    class SolvedProbleID : IComparable<SolvedProbleID>
    {
        int solved;
        string id;
        int ind;

        public SolvedProbleID(string id, int solvedProblems,int ind)
        {
            this.solved = solvedProblems;
            this.id = id;
            this.ind = ind;
        }

        #region IComparable Members

        public int CompareTo(SolvedProbleID o)
        {
            if (this.solved.CompareTo(o.solved) == 0)
            {
                if (this.ind < o.ind)
                    return -1;
                else return 1;
            }
            return o.solved.CompareTo(this.solved);
        }

        #endregion

        public override string ToString()
        {
            return String.Format("{0} {1}",this.id,this.solved);
        }
    }
}
