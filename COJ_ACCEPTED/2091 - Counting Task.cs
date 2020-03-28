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
            string ax = "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
            bool[] arr;
            //Console.WriteLine(ax.Length);
            int tc = int.Parse(Console.ReadLine());
            for (int t = 0; t < tc; t++)
            {
                int cnt = 0;
                arr = new bool[62];
                string data = Console.ReadLine();
                for (int i = 0; i < data.Length; i++)
                {
                    int tmp = ax.IndexOf(data[i]);
                    if (!arr[tmp])
                    {
                        cnt++;
                        arr[tmp] = true;
                    }
                }
                Console.WriteLine(cnt);
            }

            Console.ReadLine();
        }

    }
}
