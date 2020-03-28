using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Collections;
using System.Globalization;
using System.Linq;


namespace COJ
{
    class Program
    {
        /*
         * Author LUISMO
         * 		 
        */        
        static int n;        
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            for (int i = 0; i < n; i++)
            {
                string [] data = Console.ReadLine().Split(' ');
                int d = int.Parse(data[1]);
                string adev = "";

                if (d == 0)
                    adev = data[0];
                else
                {
                    int[] arr = new int[data[0].Length];
                    arr.Initialize();
                    int ind = -1;
                    for (int j = 0; j < data[0].Length && d > 0; j++)
                    {
                        if (data[0][j] == '1')
                            d--;
                        if (d == 0)
                        {
                            ind = j + 1;
                            break;
                        }
                    }
                    //
                    if (ind != -1)
                    {
                        for (int j = ind; j < data[0].Length; j++)
                        {
                            arr[j] = int.Parse( data[0][j].ToString() );
                        }
                    }
                    else
                    {
                        for (int j = 0; j < data[0].Length && d > 0; j++)
                        {
                            if (data[0][data[0].Length - 1 - j] == '0')
                            {
                                d--;
                                arr[arr.Length - 1 - j] = 1;
                            }
                        }
                    }
                    foreach (var item in arr)
                        adev += item.ToString();                    
                }
                // Respuesta
                Console.WriteLine("Case #{0}: {1}", i + 1, adev);
                
            }

            Console.ReadLine();
        }


    }
  
}
