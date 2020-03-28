using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace COJ
{
    class Program
    {
        //1690 Bad Cowtractors
        static void Main(string[] args)
        {
            string[] p = Console.ReadLine().Split(' ');
            int n = int.Parse(p[0]);
            int m = int.Parse(p[1]);

            long[,] ady = new long[n, n];
            EdgeValue[] edges = new EdgeValue[m];

            for (int i = 0; i < m; i++)
            {
                p = Console.ReadLine().Split(' ');
                int x = int.Parse(p[0]) - 1;
                int y = int.Parse(p[1]) - 1;
                long value = int.Parse(p[2]);

                ady[x, y] = value * -1;
                ady[y, x] = value * -1;

                edges[i] = new EdgeValue(x, y, value * -1);
            }

            long k = KruskalCost(ady, edges);
            Console.WriteLine(k * -1);             
			
            Console.ReadLine();
        }


        static long KruskalCost(long[,] ady, EdgeValue[] EdgesArray)
        {
            //Para ir llevando el costo
            long totalCost = 0;

            DisjointSetII<int> ds = new DisjointSetII<int>(new int[ady.GetLength(0)]);
            //Ordenamos las aristas
            Array.Sort(EdgesArray);
            int aristasTomadas = 0;
            //Vamos tomandolas en orden
            for (int i = 0; i < EdgesArray.Length; i++)
            {
                EdgeValue edge = EdgesArray[i];                
                //Si los vertices incidentes de esta arista estan en componentes conexas separadas
                //y la cantidad de aristas tomadas es menor que n-1 los unimos 
                if (ds.SetOf(edge.X) != ds.SetOf(edge.Y) && aristasTomadas< ady.GetLength(0) - 1 )
                {
                    //Hacemos la mezcla en el  DSet
                    ds.MergeByHeight(edge.X, edge.Y);
                    //Y anyadimos su costo
                    totalCost += (long)edge.Value;
                    //Aumentamos el numero de aristas tomadas
                    aristasTomadas++;
                }
            }
            if (aristasTomadas < ady.GetLength(0) - 1)
                return 1;
            return totalCost;
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

        public DisjointSetII(T[] values)
        {
            //Colocamos los valores
            this.values = values;
            //Creamos el arreglo de paternidad con -1 en c\posicion
            pi = new int[values.Length];
            for (int i = 0; i < pi.Length; i++)
            {
                pi[i] = -1;
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

            //Comparamos las alturas (que seran el modulo del valor de p1 y p2)
            if (p1 < p2)
            {
                //Pegamos p2 a p1 y no aumentara la altura de p2
                pi[p2] = p1;
            }
            else if (p1 > p2)
            {
                //Pegamos p1 a p2 y no aumentara la altura de p1
                pi[p1] = p2;
            }
            else
            {
                //El caso en que las alturas son iguales 
                //pegamos p2 a p1 y la altura de p1 aumentara
                pi[p2] = p1;
                pi[p1]--;
            }

        }

    }


    public class EdgeValue : IComparable
    {
        int x;
        int y;
        IComparable value;

        public EdgeValue(int x, int y, IComparable value)
        {
            this.x = x;
            this.y = y;
            this.value = value;
        }

        public int X
        {
            get { return this.x; }
        }

        public int Y
        {
            get { return this.y; }
        }

        public IComparable Value
        {
            get { return this.value; }
        }

        public int CompareTo(object obj)
        {
            if (!(obj is EdgeValue)) throw new FormatException("Esta intentado comparar con un valor de otro tipo");
            EdgeValue ev = (EdgeValue)obj;
            return this.value.CompareTo(ev.value);
        }
    }


}
