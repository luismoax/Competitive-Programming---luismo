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
          Problem: 1859 - Parts Acquisition
          Online Judge: COJ
          Idea: BFS, once built the graph which is the hardest part of the problem. On the BFS keep track of the weigth through a path to the current node
		  and if a node previosly added to the queue (taken = 1), can be achieved with a better weigth in a path to it, update the weight and enqueue it again
		  if found a planet delivering object K, be sure to finish scanning that level and break;
        */


        static void Main(string[] args)
        {
            TextReader tr = Console.In;
            TextWriter tw = Console.Out;

            //Console.SetIn(new StreamReader(@"d:\adquire\acquire.6.in"));

            SolveSingleProblem();
            
            Console.SetIn(tr);
            Console.SetOut(tw);
            
			Console.ReadLine();

            //string[] data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
        }

        static void SolveSingleProblem()
        {
            //
            string[] data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            int n = int.Parse(data[0]);
            int k = int.Parse(data[1]); // desired object

            // reading graph
            // list to store which planet RECIEVE the ith object
            List<List<int>> recieve = new List<List<int>>();
            for (int i = 0; i < n + 1; i++)
                recieve.Add(new List<int>());

            // list to store which planet DELIVER the ith object
            List<List<int>> deliver = new List<List<int>>();
            for (int i = 0; i < n + 1; i++)
                deliver.Add(new List<int>());
            // the planet earth will be at position Zero
            deliver[0].Add(1);

            // Planet collectio
            Planet[] planets = new Planet[n + 1];
            planets[0] = new Planet(0, -1, 1);
            planets[0].amount = 1;


            // reading exchanges
            for (int i = 1; i <= n; i++)
            {
                data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);

                int rec = int.Parse(data[0]);
                int del = int.Parse(data[1]);

                planets[i] = new Planet(i, rec, del);

                recieve[rec].Add(i);
                deliver[del].Add(i);
            }

            // building graph
            List<List<Edge>> adj = new List<List<Edge>>();
            for (int i = 0; i < n + 1; i++)
                adj.Add(new List<Edge>());

            for (int i = 0; i < n + 1; i++)
            {
                // foreach possible planet to deliver
                int d = planets[i].deliver; // object delivered by planet i

                for (int j = 0; j < recieve[d].Count; j++)
                {
                    Edge e = new Edge(i, recieve[d][j]);
                    adj[i].Add(e);
                }
            }

            // BFS
            Queue<Planet> q = new Queue<Planet>();

            // setting values for first planet
            planets[0].taken = 1;
            planets[0].level = 0;
            planets[0].amount = planets[0].recieve;

            Planet answer = new Planet(-1, -1, -1);
            answer.amount = int.MaxValue;

            // BFS
            // enqueue first planet as root
            q.Enqueue(planets[0]);

            while (q.Count > 0)
            {
                Planet current = q.Dequeue();
                current.taken = 2;

                // if object K is already found in a planet with lower level than this current planet
                if (answer.idx != -1 && answer.level <= current.level)
                    break;

                // ofreach adjacent planet
                for (int i = 0; i < adj[current.idx].Count; i++)
                {
                    // index for adjacent planet
                    int nextIdx = adj[current.idx][i].y;
                    // adjacent planet
                    Planet nextPlanet = planets[nextIdx];
                    // if not taken or taken with greater amount
                    if (nextPlanet.taken == 0 || (nextPlanet.taken == 1 && current.amount + nextPlanet.deliver < nextPlanet.amount))
                    {
                        // setting visited, parenthood, level and amount values
                        nextPlanet.taken = 1;
                        nextPlanet.pi = current.idx;
                        nextPlanet.level = current.level + 1;
                        nextPlanet.amount = current.amount + nextPlanet.deliver;

                        q.Enqueue(nextPlanet);

                        // if found object K
                        if (nextPlanet.deliver == k)
                        {
                            // if has been found with a better amount
                            if (nextPlanet.amount < answer.amount)
                                answer = nextPlanet;
                        }
                    }

                }

            }
            // END BFS


            // if there was found no planet to deliver object K
            if (answer.idx == -1)
            {
                Console.WriteLine(-1);
                return;
            }

            Stack<int> stack = new Stack<int>();
            int tmp = answer.idx;
            while (tmp >= 0)
            {
                stack.Push(planets[tmp].deliver);
                tmp = planets[tmp].pi;
            }

            Console.WriteLine(stack.Count);
            while (stack.Count > 0)
                Console.WriteLine(stack.Pop());

        }

    }

    class Edge
    {
        public int x, y;
        public Edge(int x, int y)
        {
            this.x = x;
            this.y = y;
        }

        public override string ToString()
        {
            return String.Format("[{0},{1}]", x, y);
        }
    }

    class Planet
    {
        public int recieve, deliver,
        pi, amount, level,
        idx;
        public int taken;

        public Planet(int idx, int recieve, int deliver)
        {
            this.idx = idx;
            this.recieve = recieve;
            this.deliver = deliver;
            this.amount = int.MaxValue;
            level = -1;
            this.pi = -1;
            taken = 0;
        }

        public override string ToString()
        {
            return String.Format("i:{0} pi:{1} r:{2} d:{3} {4}", idx, pi, recieve, deliver, amount);
        }
    }

}
