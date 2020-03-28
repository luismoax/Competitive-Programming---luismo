using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace COJ
{
    class Program
    {
        static List<int> mstEdgesIndexes;
        static int mstCost;
        static int secondMstCost;
        static void Main(string[] args)
        {
            //StreamReader Console = new StreamReader(@"d:\in.lmo");

            int tc = int.Parse(Console.ReadLine());
            string[] p;
            for (int t = 0; t < tc; t++)
            {                                
                p = Console.ReadLine().Split(' ');
                int n = int.Parse(p[0]);
                int m = int.Parse(p[1]);

                //Para alamacenar las aristas
                List<Edge> edges = new List<Edge>();

                //Leemos las aristas
                for (int i = 0; i < m; i++)
                {
                    p = Console.ReadLine().Split(' ');
                    edges.Add(new Edge(int.Parse(p[0]) - 1, int.Parse(p[1]) - 1, int.Parse(p[2])));
                }

                Kruskal(n, edges);

                Console.WriteLine("{0} {1}",mstCost,secondMstCost);
            }

            Console.ReadLine();
        }

        static void Kruskal(int n, List<Edge> edges)
        {
            int k = 0;
            mstEdgesIndexes = new List<int>();
            mstCost = int.MaxValue;
            secondMstCost = int.MaxValue;

            //Ordenamos las aristas
            edges.Sort();
            //Creamos el Conjunto Disjunto
            DisjointSetII<int> ds = new DisjointSetII<int>(new int[n]);

            for (int i = 0; i < edges.Count; i++)
            {
                Edge e = edges[i];
                //Si puedo cojer la arista estan en componentes conexas distintas los pego
                if (e.enabled && ds.SetOf(e.x) != ds.SetOf(e.y))
                {
                    k += e.value;
                    ds.MergeByHeight(e.x, e.y);

                    //anyado el indice de la arista escogida de entre todas ordenadas 
                    mstEdgesIndexes.Add(i);
                }
            }

            mstCost = k;

            //Buscamos ahora el segundo mst
            //Por c\arista del MST la deshabilitamos y despegamos del DS
            for (int i = 0; i < mstEdgesIndexes.Count; i++)
            {                
                Edge e = edges[mstEdgesIndexes[i]];
                //Depsgamos en el DS
                if (ds.UnMErge(e.x, e.y))
                {
                    //Restamos su valor a k
                    k -= e.value;

                    //A partir de ella buscamos la otra que cruce el corte
                    for (int j = mstEdgesIndexes[i] + 1; j < edges.Count; j++)
                    {
                        Edge ax = edges[j];
                        //Si estan en cc distintas encontre la otra mas liviana que cruza el corte
                        if (ds.SetOf(ax.x) != ds.SetOf(ax.y))
                        {
                            k += ax.value;
                            //No pegaremos
                            break;
                        }
                    }

                    if (k < secondMstCost && k >= mstCost)
                        secondMstCost = k;

                    //Reponemos la arista en el ds
                    ds.MergeByHeight(e.x, e.y);
                    k = mstCost;
                }
            }

        }


    }

    class Edge:IComparable<Edge>
    {
        public int x;
        public int y;
        public int value;
        public bool enabled;
        public Edge(int x, int y, int value)
        {
            this.x = x;
            this.y = y;
            this.value = value;
            enabled = true;
        }

        public int CompareTo(Edge other)
        {
            return this.value.CompareTo(other.value);
        }
    }

    public class DisjointSetII<T>
    {
        /*
         * Este conjunto Disjunto har? las mezclas por la Altura de c\arbol
         * en el arreglo p[i] guaramos un cursor al padre, en caso de ser negativo
         * este valor, el nodo en cuestion ser? la raiz y el significado absoluto 
         * del valor ser? la altura del arbol del que el es raiz
         * */
        T[] values;
        int[] pi;
        int[] hi;

        public DisjointSetII(T[] values)
        {
            //Colocamos los valores
            this.values = values;
            //Creamos el arreglo de paternidad con -1 en c\posicion
            //Creamos el arreglo de altura con 1 en c\posicion
            pi = new int[values.Length];
            hi = new int[values.Length];
            for (int i = 0; i < pi.Length; i++)
            {
                pi[i] = -1;
                hi[i] = 1;
            }
        }

        public T[] Values
        {
            get { return this.values; }
        }


        public int SetOf(int i)
        {
            if (i < 0 || i >= values.Length)
                throw new IndexOutOfRangeException("Indice fuera de rango");

            int k = i;
            while (pi[k] >= 0)
            {
                k = pi[k];
            }
            return k;
        }

        public void MergeByHeight(int i, int j)
        {
            //Cojemos los setOf
            int p1 = SetOf(i);
            int p2 = SetOf(j);

            //Comparamos las alturas (que estaran en hi)
            if (hi[p1] > hi[p2])
            {
                //Pegamos p2 a p1 y no aumenta la altura de p1
                pi[p2] = i;
            }
            else if (hi[p1] < hi[p2])
            {
                //Pegamos p1 a p2 y no aumenta la altura de p1
                pi[p1] = j;
            }
            //Y en el  caso que sean iguales las alturas
            else
            {
                //Pegamos p2 a p1 y no aumenta la altura de p1
                pi[p2] = i;
                //Y aumenta en 1 la altura de p1
                hi[p1]++;
            }

        }

        public bool UnMErge(int i, int j)
        {
            //Si el padre de i es j
            if (pi[i] == j)
            {
                pi[i] = -1;
                return true;
            }
            //Si lo contrario
            if (pi[j] == i)
            {
                pi[j] = -1;
                return true;
            }
            return false;
        }

    }

}
