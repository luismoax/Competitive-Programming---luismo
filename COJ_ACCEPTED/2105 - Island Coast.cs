using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;
using System.IO;


namespace ConsoleApplication1
{
    class Program
    {
        static int[] xs = { 1, -1, 1, -1, 1, -1, 0, 0 };
        static int[] ys = { 0, 0, 1, -1, -1, 1, 1, -1 };

        static void Main(string[] args)
        {
            TextReader tr = Console.In;
            //Console.SetIn(new StreamReader(@"d:\in.lmo"));


            string[] data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            int n = int.Parse(data[0]);
            int m = int.Parse(data[1]);
            int[,] mt = new int[n, m];
            for (int i = 0; i < n; i++)
            {
                string xin = Console.ReadLine();
                for (int j = 0; j < xin.Length; j++)
                {
                    if (xin[j] == '+')
                        mt[i, j] = 1;
                }
            }

            int[] xfor = { 1, -1, 0, 0 };
            int[] yfor = {0,0,1,-1 };

            int cnt = 0;

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (mt[i, j] == 1)
                    {
                        for (int k = 0; k < 4; k++)
                        {
                            int xs = i + xfor[k];
                            int ys = j + yfor[k];

                            if (xs >= 0 && xs < n && ys >= 0 && ys < m)
                            {
                                if (mt[xs, ys] == 0)
                                {
                                    cnt++;
                                    mt[i, j] = 2;
                                    break;
                                }
                            }
                        }

                    }
                }
            }


            Console.WriteLine(cnt);


            Console.SetIn(tr);
            Console.ReadLine();
        }


    }

}
