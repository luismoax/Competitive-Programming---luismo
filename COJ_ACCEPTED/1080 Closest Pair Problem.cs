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
         * Author: Luismo
         * Idea: Divide and Conquer algorithm
         * 
         * */
        static void Main(string[] args)
        {            
            TextReader tr = Console.In;
            
            SolveSingleProblem();            

            Console.SetIn(tr);
            Console.ReadLine();            
        }


        static void SolveSingleProblem()
        {            
            string xin = "";
            while ((xin = Console.ReadLine())!="0")
            {
                int n = int.Parse(xin);
                List<Point> points = new List<Point>();
                for (int i = 0; i < n; i++)
                {
                    // adding points
                    string [] data = Console.ReadLine().Split(new char[]{' '},StringSplitOptions.RemoveEmptyEntries);
                    points.Add(new Point(double.Parse(data[0]),double.Parse(data[1])));
                }
                // ordering by coordinates
                List<Point> pointsX = points.OrderBy(p => p.x).ThenBy(p => p.y).ToList();
                List<Point> pointsY = points.OrderBy(p => p.y).ThenBy(p => p.x).ToList();

                double d = ClosestPair(pointsX,pointsY);
                if(d>10000)
                    Console.WriteLine("INFINITY");
                else Console.WriteLine("{0:f4}",d);

            }
        }

        static double ClosestPair(List<Point> pointsX,List<Point> pointsY)
        {
            if (pointsX.Count <= 3)
            {
                double minDist = double.MaxValue;

                for (int i = 0; i < pointsX.Count; i++)
                {
                    for (int j = i+1; j < pointsX.Count; j++)
                    {
                        // minimun distance
                        double d = pointsX[i].EuclideanDistance(pointsX[j]);
                        if (d < minDist)
                            minDist = d;
                    }
                }
                return minDist;
            }

            // split the array by the middle
            int mid = pointsX.Count / 2;

            List<Point> forX1 = new List<Point>();
            List<Point> forX2 = new List<Point>();
            // middle point
            Point p = pointsX[mid];
            for (int i = 0; i <pointsX.Count; i++)
            {
                if(i<=mid)
                    forX1.Add(pointsX[i]);
                else forX2.Add(pointsX[i]);
            }

            List<Point> forY1 = new List<Point>();
            List<Point> forY2 = new List<Point>();
            for (int i = 0; i < pointsY.Count; i++)
            {
                if (pointsY[i].x < p.x || pointsY[i].x == p.x && pointsY[i].y <= p.y)
                    forY1.Add(pointsY[i]);
                else forY2.Add(pointsY[i]);
            }

            double delta1 = ClosestPair(forX1, forY1);
            double delta2 = ClosestPair(forX2, forY2);

            // minimun value so far
            delta1 = Min(delta1, delta2);

            // searching throug the points in the vertical strip
            for (int i = 0; i < pointsY.Count; i++)
            {
                for (int j = i+1; j < pointsY.Count && j<i+7; j++)
                {
                    double d = pointsY[i].EuclideanDistance(pointsY[j]);
                    if (d < delta1)
                        delta1 = d;
                }
            }

            return delta1;
        }

        static double Min(double a, double b)
        {
            return (a < b) ? a : b;
        }
    }


    class Point
    {
        public double x, y;
        public Point(double x, double y)
        {
            this.x = x;
            this.y = y;
        }

        public double EuclideanDistance(Point other)
        {
            return Math.Sqrt((this.x - other.x) * (this.x - other.x) + (this.y - other.y) * (this.y - other.y)  );
        }
    }

    class PointComparator : IComparer<Point>
    {

        public int Compare(Point x, Point y)
        {
            throw new NotImplementedException();
        }
    }
    
}
