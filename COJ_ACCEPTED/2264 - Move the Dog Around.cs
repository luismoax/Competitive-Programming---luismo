using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Collections;
using System.IO;

namespace consoleApp
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            int n = int.Parse(data[0]);
            int m = int.Parse(data[1]);
            data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            int x = int.Parse(data[0]);
            int y = int.Parse(data[1]);
            int count = int.Parse(data[2]);

            // east,west,south,north (not needed)
            int[] xs = { 0, 0, 1, -1 };
            int[] ys = { 1, -1, 0, 0 };
            
            List<Step> stepss = new List<Step>(); // steps

	    // foreach command I create a reversed (direction) command
            for (int i = 0; i < count; i++)
            {
                data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                if(data[0]=="E" )
                    stepss.Add(new Step("W",int.Parse(data[1])));
                else if(data[0]=="W" )
                    stepss.Add(new Step("E",int.Parse(data[1])));
                else if(data[0]=="S" )
                    stepss.Add(new Step("N",int.Parse(data[1])));
                else if(data[0]=="N" )
                    stepss.Add(new Step("S",int.Parse(data[1])));
            }

	    // given final position
            int fx = x;
            int fy = y;
	     
	    // taking steps backwards
            for (int i = stepss.Count-1; i >= 0; i--)
            {
                if (stepss[i].dir == "S")
                    fx += stepss[i].steps;

                else if (stepss[i].dir == "N")
                    fx -= stepss[i].steps;

                else if (stepss[i].dir == "E")
                    fy += stepss[i].steps;

                else if (stepss[i].dir == "W")
                    fy -= stepss[i].steps;
            }

            Console.WriteLine("{0} {1}",fx,fy);
            Console.ReadLine();
        }

    }

    class Step
    {
        public string dir;
        public int steps;
        public Step(string dir, int steps)
        {
            this.dir = dir;
            this.steps = steps;
        }
    }

}
