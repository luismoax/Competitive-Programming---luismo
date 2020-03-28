using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static int [] pi;
        static List<List<Edge>> ady;
        static Node[] nodes;
        static void Main(string[] args)
        {
            Console.BackgroundColor = ConsoleColor.Blue;
            Console.ForegroundColor = ConsoleColor.White;

            TextReader tr = Console.In;
            //Console.SetIn(new StreamReader(@"d:\in.lmo"));

            string xin = Console.ReadLine();
            while (xin!=null && xin!="")
            {
                string[] p = xin.Split(' ');
                int n = int.Parse(p[0]);
                int edges = int.Parse(p[1]);
                int s = int.Parse(p[2]) - 1;
                int t = int.Parse(p[3]) - 1;

                nodes = new Node[n];
                ady = new List<List<Edge>>(n);
                for (int i = 0; i < n; i++)
                {
                    ady.Add(new List<Edge>());
                    nodes[i] = new Node(double.MaxValue,false);
                }

                //Reading edges
                for (int i = 0; i < edges; i++)
                {
                    p = Console.ReadLine().Split(' ');
                    int x = int.Parse(p[0]) - 1;
                    int y = int.Parse(p[1]) - 1;
                    double dist = double.Parse(p[2]);

                    ady[x].Add(new Edge(x,y,dist));
                    ady[y].Add(new Edge(y,x,dist));
                }
                //Leyendo los nodos de la mafia
                int mn = int.Parse(Console.ReadLine()); //amount of mob nodes
                for (int i = 0; i < mn; i++)
                {
                    int ax = int.Parse(Console.ReadLine())-1;
                    nodes[ax].isMob = true;
                }

                Dijkstra(ady, s);

                List<int> path = new List<int>();
                int k = t;
                path.Add(k + 1);
                while (pi[k]>=0)
                {
                    path.Add(pi[k]+1);
                    k = pi[k];
                }
                //Imprimo el camino
                for (int i = 0; i < path.Count; i++)
                {
                    if (i == 0) Console.Write(path[path.Count-1]);
                    else Console.Write(" "+path[path.Count - 1-i]);
                }
                Console.WriteLine();
                Console.WriteLine("{0} {1:f2}",nodes[t].mobNodesInAWay,nodes[t].di);
                //Leemos la siguiente entrada
                xin = Console.ReadLine();
            }

            Console.SetIn(tr);
            Console.ReadLine();
        }


        static void Dijkstra(List<List<Edge>> ady, int s)
        {
            int n = ady.Count;
            pi = new int[n];
            for (int i = 0; i < n; i++)
                pi[i] = -1;
            //ISS
            nodes[s].di = 0;
            nodes[s].mobNodesInAWay = 0;            
            nodes[s].isMob = false;
            nodes[s].taken = true;
            //Marcamos ultimo tomado al inicio
            int lastTaken = s;

            for (int i = 0; i < n; i++)
            {
                //Por las aristas del ultimo nodo tomado, RELAX
                for (int j = 0; j < ady[lastTaken].Count; j++)
                {
                    Edge e = ady[lastTaken][j];
                    //
                    int factorMafia = 0;
                    if (nodes[e.y].isMob)
                        factorMafia++;
                    //Si el nodo al que voy tiene mas mafia
                    if (nodes[e.y].mobNodesInAWay > nodes[lastTaken].mobNodesInAWay + factorMafia)
                    {
                        //Actualizamos la cantidad de nodos mafia en un camino a el
                        nodes[e.y].mobNodesInAWay = nodes[lastTaken].mobNodesInAWay + factorMafia;
                        nodes[e.y].di = nodes[lastTaken].di + e.value;
                        //Asignamos paternidad
                        pi[e.y] = lastTaken;
                    }
                    //Si tiene igual mafia y la distancia es menor, se la actualizamos
                    if (nodes[e.y].mobNodesInAWay == nodes[lastTaken].mobNodesInAWay + factorMafia)
                    {
                        //Si se puede mejorar la distancia
                        if (nodes[e.y].di > nodes[lastTaken].di + e.value)
                        {
                            nodes[e.y].di = nodes[lastTaken].di + e.value;
                            //Asignamos paternidad
                            pi[e.y] = lastTaken;
                        }
                    }
                }
                //Escojo el "menor de estos nodos" que no han sido tomados
                Node aux = new Node(double.MaxValue, true);
                int idx = -1;
                for (int j= 0; j < nodes.Length; j++)
                {
                    if (!nodes[j].taken && nodes[j].CompareTo(aux) < 0)
                    {
                        aux = nodes[j];
                        idx = j;
                    }
                }

                if (idx != -1)
                {
                    nodes[idx].taken = true;
                    lastTaken = idx;
                }

            }

        }
    }

    class Edge
    {
        public int x;
        public int y;
        public double value;

        public Edge(int x, int y, double value)
        {
            this.x = x;
            this.y = y;
            this.value = value;
        }

        public override string ToString()
        {
            return String.Format("{0}->{1} : {2}",x,y,value);
        }
    }

    class Node:IComparable<Node>
    {
        public double di;
        public bool isMob;
        public bool taken;
        public int mobNodesInAWay;

        public Node(double di,bool isMob)
        {
            this.di = di;
            this.isMob = isMob;
            taken = false;
            this.mobNodesInAWay = int.MaxValue;
        }

        public int CompareTo(Node other)
        {
            if (this.mobNodesInAWay == other.mobNodesInAWay)
            {
                return this.di.CompareTo(other.di);
            }
            return this.mobNodesInAWay.CompareTo(other.mobNodesInAWay);
        }

        public override string ToString()
        {
            return String.Format("{0} {1} {2}",di,isMob,mobNodesInAWay);
        }
    }
}
