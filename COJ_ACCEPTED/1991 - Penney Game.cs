using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ACM_ICPC
{
    class Program
    {
        static void Main(string[] args)
        {
            //TextReader tr = Console.In;
            //Console.SetIn(new StreamReader(@"d:\in.lmo"));

            string[] strArr = { "TTT", "TTH", "THT", "THH", "HTT", "HTH", "HHT", "HHH" };
            int tc = int.Parse(Console.ReadLine());
            for (int t = 0; t< tc; t++)
            {
                string dataSetNumber = Console.ReadLine();
                int[] arr = { 0,0,0,0,0,0,0,0};
                string data = Console.ReadLine();
                for (int i = 0; i < strArr.Length; i++)
                {
                    int cnt = 0;
                    for (int j = 0; j < data.Length - 2; j++)
                    {
                        bool good = true;
                        for (int k = 0; k < 3; k++)
                            if (data[j+k] != strArr[i][k])
                                good = false;

                        if (good)
                            cnt++;
                    }
                    arr[i] = cnt;
                }
                Console.Write(dataSetNumber);
                foreach(var item in arr)
                    Console.Write(" "+item);
                Console.WriteLine();

            }

            //Console.SetIn(tr);
            Console.ReadLine();
        }        
    }
}
