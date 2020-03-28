using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;
using System.IO;
using System.Linq;


namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
			string xin = "";
            while (!String.IsNullOrEmpty(xin = Console.ReadLine()))
            {
                string[] data = xin.Split(new char[]{' '});
                bool[] arr = new bool[data[1].Length];
                int n = data[0].Length;
                int idx = 0;
                for (int i = 0; i < data[0].Length; i++)
                {
                    bool flag = false;
                    
                    for (int j = idx; j < data[1].Length; j++)
                    {
                        if (data[0][i] == data[1][j] && !arr[j])
                        {
                            flag = true;
                            arr[j] = true;
                            n--;
                            idx = j + 1;
                            break;
                        }
                    }
                    if (!flag)
                        break;
                    
                }

                if (n == 0)                
                    Console.WriteLine("Yes");
                else Console.WriteLine("No");
            }

            Console.ReadLine();
        }

    }

}
