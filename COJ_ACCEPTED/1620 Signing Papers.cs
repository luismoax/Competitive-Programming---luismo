using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            //1620 Signing Papers
            string xin = Console.ReadLine();
            while (xin!=null)
            {
                string[] p = xin.Split(' ');
                int n = int.Parse(p[0]);
                int k = int.Parse(p[1]);
                double totalDistance = 0;
                PointLmo p1 = new PointLmo();            
                //Sumo las distancias totales
                for (int c = 0; c < n; c++)
                {
                    p = Console.ReadLine().Split(' ');
                    if (c == 0)
                    {
                        p1 = new PointLmo(int.Parse(p[0]), int.Parse(p[1]));
                    }
                    else
                    {
                        PointLmo pax = new PointLmo(int.Parse(p[0]),int.Parse(p[1]));
                        totalDistance += p1.Distance(pax);
                        p1 = pax;
                    }
                }
                totalDistance /= 1000;
                double t = totalDistance / 0.05;
                Console.WriteLine("{0:f5}",k*t);
                
                xin = Console.ReadLine();
            }
            Console.ReadLine();
        }        

    }

    class PointLmo
    {
        int x;
        int y;

        public PointLmo(int x, int y)
        {
            this.x = x;
            this.y = y;
        }

        public PointLmo()
        {
        }

        public int X
        {
            get { return x; }
        }

        public int Y
        {
            get { return y; }
        }

        public double Distance(PointLmo p)
        {
            double x2 = Math.Pow((this.x - p.x), 2);
            double y2 = Math.Pow((this.y - p.y), 2);

            return Math.Sqrt(x2 + y2);
        }
    }


}
