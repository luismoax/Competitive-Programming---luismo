using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static long[] di;
        static void Main(string[] args)
        {
            Console.BackgroundColor = ConsoleColor.Blue;
            Console.ForegroundColor = ConsoleColor.White;
            TextReader tr = Console.In;
            //Console.SetIn(new StreamReader(@"d:\in.lmo"));
            
            string alfabet = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm";
            int [] arr = new int[alfabet.Length];
            //Leyendo las aristas            
            int paths = int.Parse(Console.ReadLine());
            int nodesCount = 1;
            List<Edge> edges = new List<Edge>(paths); //para guardar las aristas
            for (int i = 0; i < paths; i++)
            {
                string[] p = Console.ReadLine().Split(' ');
                int x = alfabet.IndexOf(p[0]);
                int y = alfabet.IndexOf(p[1]);
                int value = int.Parse(p[2]);

                if (arr[x] == 0)
                {
                    arr[x] = nodesCount;
                    nodesCount++;                    
                }
                x = arr[x];
                if (arr[y] == 0)
                {
                    arr[y] = nodesCount;
                    nodesCount++;                    
                }
                y = arr[y];
                edges.Add(new Edge(x,y,value));
                edges.Add(new Edge(y, x, value));
            }
            nodesCount--;
            //arrelgo Lista de Adyacencia
            List<Edge>[] ady = new List<Edge>[nodesCount];
            //Inicializamos las listas
            for (int i = 0; i < ady.Length; i++)
                ady[i] = new List<Edge>();
            //Ponemos las aristas
            for (int i = 0; i < edges.Count; i++)
            {
                Edge e = edges[i];
                ady[e.x - 1].Add(e);
            }


            //Buscamos el nodo inicial (que es del de Z)
            int s = arr[19] - 1;
            //Aplicamos Dijkstra
            Dijkstra(ady, s);
                        
            //Buscamos la mejor distancia
            int idx=-1,mnVal=int.MaxValue;
            for (int i = 0; i < di.Length; i++)
            {
                if (di[i]!=0 && di[i] < mnVal)
                {
                    if (alfabet[Array.IndexOf(arr, i + 1)] == Char.ToUpper(alfabet[Array.IndexOf(arr, i + 1)]))
                    {
                        mnVal = (int)di[i];
                        idx = i;
                    }
                }
            }

            Console.WriteLine("{0} {1}",alfabet[Array.IndexOf(arr,idx+1)],mnVal);

            Console.SetIn(tr);
            Console.ReadLine();
        }

        static void Dijkstra(List<Edge>[] ady, int s)
        {
            int n = ady.Length;
            di = new long[n];
            for (int i = 0; i < n; i++)
                di[i] = long.MaxValue;
            di[s] = 0;

            bool[] taken = new bool[n];
            int lastTaken = s;
            //Iteramos n veces
            for (int k = 0; k < n; k++)
            {
                //Por c\u de las aristas del ultimo nodo tomado relajamos
                for (int i = 0; i < ady[lastTaken].Count; i++)
                {
                    Edge e = ady[lastTaken][i];
                    //Sino ha sido tomado y se puede ralax
                    if (!taken[e.y - 1] && di[e.y - 1] > di[lastTaken] + e.value)
                    {
                        //Realajo
                        di[e.y - 1] = di[lastTaken] + e.value;
                    }
                }

                //Buscando el mejor de los relajados
                int idx = -1;
                int mnValue = int.MaxValue;
                for (int i = 0; i < di.Length; i++)
                {
                    if (!taken[i] && di[i] < mnValue)
                    {
                        mnValue = (int)di[i];
                        idx = i;
                    }
                }

                if (idx != -1)
                {
                    taken[idx] = true;
                    lastTaken = idx;
                }
                else break;
            }

        }


        static void CWMT(long [,] mt)
        {
            for (int i = 0; i < mt.GetLength(0); i++)
            {
                for (int j = 0; j < mt.GetLength(1); j++)
                    Console.Write(mt[i, j]+" ");
                Console.WriteLine();
            }
        }

    }

    class Edge
    {
        public int x, y, value;
        public Edge(int x,int y,int value)
        {
            this.x = x;
            this.y = y;
            this.value = value;
        }
        public override string ToString()
        {
            return String.Format("{0}->{1}: {2}",x,y,value);
        }
    }

}
