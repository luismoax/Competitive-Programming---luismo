using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Globalization;

namespace COJ
{
    class Program
    {
        /*
         * Author: LUISMO
         *
         * Problem: Cow Beauty Pageant (Bronze Level)
         * 
         * Idea: The idea here is to mark each spot with
         * a diferent id (eg. 1 and 2 ) and then for each
         * part of each spot I calculate the minimun distance
         * to any part of the other spot, then take the best
         * of this values. Initially boths spots are marked with
         * number two, then a take the first ocurrence of a spot
         * and aplicate a Lee algorithm to mark every other part
         * of this spot as 1, thus I separate boths spots.
         * 
         * Complexity: O(m*n)
         * 
         * */
        static void Main(string[] args)
       {
            TextReader tr = Console.In;
            //Console.SetIn(new StreamReader(@"d:\lmo.in"));

            string[] data = Console.ReadLine().Split(new char[]{' '},StringSplitOptions.RemoveEmptyEntries);
            int n = int.Parse(data[0]);
            int m = int.Parse(data[1]);

            int[,] mt = new int[n, m];

            Pair first = new Pair(-1, -1);
            for (int i = 0; i < n; i++)
            {
                string xin = Console.ReadLine();
                for (int j = 0; j < xin.Length; j++)
                {
                    if (xin[j] == 'X')
                    {
                        mt[i, j] = 2;
                        if (first.x == -1)
                        {
                            first.x = i;
                            first.y = j;
                        }
                    }
                }
            }

            // Call a Lee method to mark first spot with number 1
            LeeBFS(mt, first.x, first.y, 1);
            
            // Put each spot point into separated lists
            // For each pair of points of diferent spot 
            // I caluculate de distance and uptede a value
            // for my best distance
            List<Pair> firstSpot = new List<Pair>();
            List<Pair> secondSpot = new List<Pair>();
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (mt[i, j] == 1)
                    {
                        firstSpot.Add(new Pair(i, j));
                    }
                    else if (mt[i, j] == 2)
                    {
                        secondSpot.Add(new Pair(i,j));
                    }
                }
            }

            int minimunDistance = int.MaxValue;

            for (int i = 0; i < firstSpot.Count; i++)
            {
                for (int j = 0; j < secondSpot.Count; j++)
                {
                    int val = Absolute(   firstSpot[i].x-secondSpot[j].x ) +  Absolute( firstSpot[i].y-secondSpot[j].y   ) -1;
                    if (val < minimunDistance)
                        minimunDistance = val;
                }
            }

            Console.WriteLine(minimunDistance);
            
            Console.SetIn(tr);
            Console.ReadLine();
        }

        static void PrintMt(int[,] mt)
        {
            for (int i = 0; i < mt.GetLength(0); i++)
            {
                for (int j = 0; j < mt.GetLength(1); j++)
                {
                    Console.Write(mt[i,j]+" ");   
                }
                Console.WriteLine();
            }
        }

        static void LeeBFS(int[,] mt, int i,int j,int id)
        {
            int[] xMove = { 1, -1, 0, 0 };
            int[] yMove = { 0,0,1,-1};

            Pair p = new Pair(i, j);
            Queue<Pair> q = new Queue<Pair>();
            q.Enqueue(p);
            while (q.Count>0)
            {
                Pair ax = q.Dequeue();
                mt[ax.x, ax.y] = id;

                for (int k = 0; k < 4; k++)
                {
                    int f1 = ax.x + xMove[k];
                    int f2 = ax.y + yMove[k];

                    // If is a valid position in the matrix
                    if (f1 >= 0 && f1 < mt.GetLength(0) && f2 >= 0 && f2 < mt.GetLength(1) && mt[f1, f2] != id && mt[f1, f2] != 0)
                    {
                        q.Enqueue(new Pair(f1, f2));
                    }
                }
            }

        }

        static int Minimun(int a,int b)
        {
            if (a < b)
                return a;
            return b;
        }

        static int Absolute(int a)
        {
            if (a < 0)
                return a * -1;
            return a;
        }

        static int Maximun(int a, int b)
        {
            if (a > b)
                return a;
            return b;
        }

    }

    class Pair
    {
        public int x, y;
        public Pair(int x,int y)
        {
            this.x = x;
            this.y = y;
        }

        public override string ToString()
        {
            return String.Format("[{0},{1}]",x,y);
        }

    }



}
