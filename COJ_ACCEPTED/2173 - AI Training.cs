using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;
using System.IO;
using System.Linq;


namespace ConsoleApplication1
{
    class Program
    {
        /// <summary>
        /// Author: Luismo
        /// Idea: 
        /// </summary>
        /// <param name="args"></param>

        static void Main(string[] args)
        {
            //TextReader tr = Console.In;
            //Console.SetIn(new StreamReader(@"d:\lmo.in"));

            int tc = int.Parse(Console.ReadLine());
            for (int t = 0; t < tc; t++)
            {
                string[] data = Console.ReadLine().Split(new char[]{' '},StringSplitOptions.RemoveEmptyEntries);
                int n = int.Parse(data[0]);
                int m = int.Parse(data[1]);

                int[,] map = new int[n, m];
                int[,] mapvalues = new int[n, m];
                bool[,] mark = new bool[n, m];
                Pair initial = new Pair(-1, -1);
                Pair final = new Pair(-1, -1);

                for (int i = 0; i < n; i++)
                {
                    string xin = Console.ReadLine();
                    for (int j = 0; j < xin.Length; j++)
                    {
                        if (xin[j] == 'C')
                        {
                            map[i, j] = 2;
                            final = new Pair(i, j);
                        }
                        else if (xin[j] == 'R')
                        {
                            map[i, j] = 1;
                            initial = new Pair(i, j);
                        }
                        else if (xin[j] == 'X')
                            map[i, j] = 3;
                    }
                }

                // BFS over the table
                Queue<Pair> q = new Queue<Pair>();
                q.Enqueue(initial);
                // Direction arrays
                int[] xs = { 0,0,1,-1};
                int[] ys = { 1,-1,0,0};
                mark[initial.X, initial.Y]=true;

                while (q.Count > 0)
                {
                    Pair p = q.Dequeue();

                    if (p.Equals(final))
                        break;
                    

                    // Check the adyacent cells
                    int cnt = 0;
                    for (int i = 0; i < 4; i++)
                    {
                        int kx = xs[i] + p.X;
                        int ky = ys[i] + p.Y;

                        if (CanMove(kx, ky, n, m) && map[kx, ky] != 3 && !mark[kx, ky])
                        {
                            q.Enqueue(new Pair(kx, ky));
                            cnt++;
                        }
                    }

                    if (cnt > 1)
                        mapvalues[p.X, p.Y]++;

                    for (int i = 0; i < 4; i++)
                    {
                        int kx = xs[i] + p.X;
                        int ky = ys[i] + p.Y;

                        if (CanMove(kx, ky, n, m) && map[kx, ky] != 3 && !mark[kx, ky])
                        {
                            mark[kx, ky] = true;
                            mapvalues[kx, ky] = mapvalues[p.X, p.Y];
                        }
                    }

                }

                Console.WriteLine(mapvalues[final.X,final.Y]);

            }
            
            //Console.SetIn(tr);
            Console.ReadLine();
        }

        static bool CanMove(int x, int y, int h, int w)
        {
            return x >= 0 && y >= 0 && x < h && y < w;
        }


        static void PrintMt(int [,] mt)
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
    }

    class Pair
    {
        public int X { get; set; }
        public int Y { get; set; }

        public Pair(int x, int y)
        {
            this.X = x;
            this.Y = y;
        }

        public override string ToString()
        {
            return string.Format("[{0} , {1}]",X,Y);
        }

        public override bool Equals(object obj)
        {
            if (!(obj is Pair))
                return false;
            Pair p = (Pair)obj;
            return p.X == this.X && p.Y == this.Y;
        }
    
    }

}