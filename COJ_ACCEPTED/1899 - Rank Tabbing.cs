using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace COJ
{
    class Program
    {
        /*
        Este problema se resume a ordenar los datos usando el criterio de comparacion explicado
        y luego usando un arreglo paralelo ir llevando para c\i el numero de pagina dividiendo
        entre k q es la cantidad maxima de elementos a mostrar en una hoja
		
        */
        static void Main(string[] args)
        {
            //StreamReader Console = new StreamReader(@"f:\in.lmo");
            string[] p = Console.ReadLine().Split(' ');
            int n = int.Parse(p[0]);
            int k = int.Parse(p[1]);

            Contestant[] arr = new Contestant[n];
            for (int i = 0; i < n; i++)
            {
                p = Console.ReadLine().Split(' ');
                arr[i] = new Contestant(int.Parse(p[0]), int.Parse(p[1]), int.Parse(p[2]));
            }
            Array.Sort(arr);
            //Para llevar el numero de pagina de entre c\contestante
            int[] pn = new int[n];
            int pnk = 0;
            for (int i = 0; i < n; i++)
            {
                if (i % k == 0) pnk++;
                pn[arr[n-1-i].id - 1] = pnk;                
            }

            foreach (var item in pn)
            {
                Console.WriteLine(item);
            }
            Console.ReadLine();
        }

    }

    class Contestant : IComparable<Contestant>
    {
        public int id;
        public int sp;
        public int ta;

        public Contestant(int id, int sp, int ta)
        {
            this.id = id;
            this.sp = sp;
            this.ta = ta;
        }

        public int CompareTo(Contestant other)
        {
            if (this.sp.CompareTo(other.sp) == 0)
                return other.ta.CompareTo(this.ta);

            return this.sp.CompareTo(other.sp);
        }

        public override string ToString()
        {
            return String.Format("id:{0} sp:{1} ta:{2}", id, sp, ta);
        }
    }

}
