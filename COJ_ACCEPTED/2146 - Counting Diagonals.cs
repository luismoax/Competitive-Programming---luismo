using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;


namespace COJ
{
    class MainClass
    {
        static int n;
        static int[,] mt;
        /// <summary>
        /// Author: Luismo
        /// Idea: 
        /// </summary>
        /// <param name="args"></param>
        public static void Main(string[] args)
        {            
            //TextReader tr = Console.In;
            //TextWriter tw = Console.Out;
            //Console.SetIn(new StreamReader(@"d:\lmo.in"));
            //Console.SetOut(new StreamWriter(@"d:\lmo.out"));
            //string [] data = Console.ReadLine().Split(new char[]{' '},StringSplitOptions.RemoveEmptyEntries);
            string[] data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            long d = long.Parse(data[0]);
            long v = long.Parse(data[1]);
            if(d == v*(v-3)/2)
                Console.WriteLine("yes");
            else Console.WriteLine("no");


            //Console.Out.Close();
            //Console.SetIn (tr);
            //Console.SetOut(tw);
            Console.ReadLine();
        }
        
    }
}