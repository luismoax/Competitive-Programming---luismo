using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace COJ
{
    class Program
    {
        static int sol = int.MaxValue;
        static int n,k;
        static List<Pair> pos;
        static Pair[] conf;
        static bool[] bbb;
        static void Main(string[] args)
        {   
            Console.BackgroundColor = ConsoleColor.Blue;
            Console.ForegroundColor = ConsoleColor.White;
            
            string[] p = Console.ReadLine().Split(' ');
            n = int.Parse(p[0]);
            k = int.Parse(p[1]);
            //Posiciones de las ovejas
            pos= new List<Pair>();
            for (int i = 0; i < k; i++)
            {
                p = Console.ReadLine().Split(' ');
                pos.Add(new Pair(){x = int.Parse(p[0]),y = int.Parse(p[1])});
            }
            bbb = new bool[pos.Count];
            conf = new Pair[pos.Count + 2];
            for (int i = 0; i < conf.Length; i++)
                conf[i] = new Pair() { x = 0, y = 0 };
            conf[0].x = 1;
            conf[0].y = 1;

            conf[conf.Length - 1].x = n;
            conf[conf.Length - 1].y = n;


            JohnAndHisSheeps(1);
            Console.WriteLine(sol);
            Console.ReadLine(); 
        }

        static void JohnAndHisSheeps(int ki)
        {
            if (ki == conf.Length - 1)
            {
                int cnt = 0;
                for (int i = 0; i < conf.Length-1; i++)
                {
                    cnt += Math.Max(Math.Abs(conf[i].x - conf[i + 1].x), Math.Abs(conf[i].y - conf[i + 1].y));
                }
                if (cnt < sol)
                    sol = cnt;
                return;
            }

            for (int i = 0; i < bbb.Length; i++)
            {
                if (!bbb[i])
                {
                    bbb[i] = true;
                    conf[ki] = pos[i];
                    JohnAndHisSheeps(ki + 1);
                    bbb[i] = false;
                }
            }
        }
    }

    class Pair
    {
        public int x;
        public int y;
    }

}
