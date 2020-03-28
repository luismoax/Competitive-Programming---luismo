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
          Problem: 2501 - Kastenlauf
          Online Judge: COJ
          Idea: Easy. DFS over the coordenates, jumping from one to another only if distances is less than 1000          
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
        static List<Pair> cities;
        static bool[] visited;

        static void SolveSingleProblem()
        {
            int tc = int.Parse(Console.ReadLine());
            for (int t = 0; t < tc; t++)
            {
                int n = int.Parse(Console.ReadLine());

                cities = new List<Pair>();

                visited = new bool[n + 2];
                
                // Joe's place
                string[] data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                cities.Add(new Pair(int.Parse(data[0]), int.Parse(data[1])));
                              
                // beer supply centers
                for (int i = 0; i < n; i++)
                {
                    data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                    cities.Add(new Pair(int.Parse(data[0]), int.Parse(data[1]) ));
                }

                // destination
                data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                cities.Add(new Pair(int.Parse(data[0]), int.Parse(data[1])));

                visited[0] = true;

                bool flag = DFS(0);

                Console.WriteLine((flag)?"happy":"sad");
            }
        }

        
        static bool DFS(int idx)
        {
            if (idx == cities.Count - 1)
                return true;

            for (int i = 1; i < cities.Count; i++)
            {
                // if has not visited this city
                if (!visited[i])
                {
                    // distance between current city and the i-th city
                    int dist = cities[idx].ManhatanDistance(cities[i]);
                    
                    // if distance can be covered
                    if (dist <= 1000)
                    {
                        visited[i] = true;
                        bool flag = DFS(i);

                        if (flag)
                            return true;
                    }
                }
            }

            return false;
        }

        private static int Abs(int p)
        {
            return (p > 0) ? p : -p;
        }

        private static int Max(int k1, int k2)
        {
            return (k1 > k2) ? k1 : k2;
        }

        static int Min(int a, int b)
        {
            return (a < b) ? a : b;
        }
    }

    class Pair
    {
        public int x,y;

        public Pair(int x, int y)
        {
            this.x = x;
            this.y = y;
        }

        public override string ToString()
        {
            return string.Format("[{0},{1}]", x,y);
        }

        public int ManhatanDistance(Pair other)
        {
            return Math.Abs(this.x - other.x) + Math.Abs(this.y - other.y);
        }
    }

}
