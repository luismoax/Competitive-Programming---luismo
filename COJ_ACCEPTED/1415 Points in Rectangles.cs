using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;


using System.Text;

namespace COJ
{
    class Program
    {
        static void Main(string[] args)
        {            
            List<Rectangle> lrect = new List<Rectangle>();
            string input = Console.ReadLine();
            while (input!="*")
            {
                string[] p = input.Split(' ');
                Pnt ul = new Pnt(double.Parse(p[1]), double.Parse(p[2]));
                Pnt lr = new Pnt(double.Parse(p[3]), double.Parse(p[4]));
                lrect.Add(new Rectangle(ul, lr));
                input = Console.ReadLine();
            }
            input = Console.ReadLine();
            int kounter = 1;
            while (input!="9999.9 9999.9")
            {
                string[] p = input.Split(' ');
                Pnt ax = new Pnt(double.Parse(p[0]), double.Parse(p[1]));
                bool kontained = false;
                for (int i = 0; i < lrect.Count; i++)
                {
                    if (lrect[i].IsInside(ax))
                    {
                        kontained = true;
                        Console.WriteLine("Point " + kounter + " is contained in figure " + (i + 1));
                    }
                }
                if (!kontained) Console.WriteLine("Point "+kounter+" is not contained in any figure");
                kounter++;
                input = Console.ReadLine();
            }
            Console.ReadLine();
        }

    }

    class Rectangle
    {
        Pnt UpperLeft;
        Pnt UpperRight;
        Pnt LowerLeft;
        Pnt LowerRight;
        public Rectangle(Pnt UpperLeft, Pnt LowerRight)
        {
            this.UpperLeft = UpperLeft;
            this.LowerRight = LowerRight;

            this.UpperRight = new Pnt(LowerRight.X, UpperLeft.Y);
            this.LowerLeft = new Pnt(UpperLeft.X, LowerRight.Y);
        }

        public bool IsInside(Pnt p)
        {
            return p.X > UpperLeft.X && p.X < UpperRight.X && p.Y > LowerLeft.Y && p.Y < UpperLeft.Y;
        }

    }

    class Pnt
    {
        double x;
        double y;
        public Pnt(double x, double y)
        {
            this.x = x;
            this.y = y;
        }

        public double X
        {
            get { return this.x; }
        }
        public double Y
        {
            get { return this.y; }
        }

    }

}
