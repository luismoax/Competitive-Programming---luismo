using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;
using System.IO;


namespace ConsoleApplication1
{
    class Program
    {
        static int[] xs = { 1, -1, 1, -1, 1, -1, 0, 0 };
        static int[] ys = { 0, 0, 1, -1, -1, 1, 1, -1 };

        static void Main(string[] args)
        {
            
            string xin = "";
            while ((xin = Console.ReadLine())!="0")
            {
                int n = int.Parse(xin);
                bool[,] map = new bool[n, n];
                for (int i = 0; i < n; i++)
                {
                    xin = Console.ReadLine();
                    for (int j = 0; j < xin.Length; j++)
                    {
                        if (xin[j] == 'l')
                        {
                            map[i, j] = true;
                        }
                    }
                }



                int max = 0,min = int.MaxValue,total=0;


                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (map[i, j])
                        {
                            int x=SinkIsland(map, i, j);
                            if (x > max)
                                max = x;
                            if (x < min)
                                min = x;

                            total++;
                        }
                    }
                }

                if (total == 0)
                {
                    min = 0;
                }
                Console.WriteLine("{0} {1} {2}",total,min,max);

               
            }

            Console.ReadLine();
        }

        private static int SinkIsland(bool [,] map,int i,int j)
        {
            int cnt = 0;
            int n = map.GetLength(0); // Dimension del mapa
            Queue<Pair> q = new Queue<Pair>();

            map[i, j] = false;

            q.Enqueue(new Pair(i,j));
            while (q.Count>0)
            {
                Pair p = q.Dequeue();
                
                cnt++;
                for (int k = 0; k < 8; k++)
                {
                    int ax1= p.x+xs[k];
                    int ax2 = p.y+ys[k];
                    if (ax1 >= 0 && ax1<n && ax2>=0 && ax2<n && map[ax1,ax2])
                    {
                        q.Enqueue(new Pair(ax1,ax2));
                        map[ax1, ax2] = false;                  
                    }
                }
            }

            return cnt;
        }

    }

    class Pair
    {
        public int x, y;
        public Pair(int x, int y)
        {
            this.x = x;
            this.y = y;
        }

        public override string ToString()
        {
            return String.Format("[{0},{1}]",this.x,this.y);
        }
    }
}
