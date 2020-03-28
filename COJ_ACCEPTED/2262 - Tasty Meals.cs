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
            //Console.WriteLine(long.MaxValue>1000000000000);
            string[] data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            int n = int.Parse(data[0]);
            ulong k = ulong.Parse(data[1]);
            ulong[] arr = new ulong[n];
            data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            for (int i = 0; i < n; i++)
            {
                arr[i] = ulong.Parse(data[i]);
            }

            Array.Sort(arr);
            int cnt = 0;
            ulong amount = 0;
            for (int i = n-1; amount<k && i>=0; i--)
            {
                amount += arr[i];
                cnt++;                
            }

            if(amount>=k)
                Console.WriteLine(cnt);
            else Console.WriteLine("IMPOSSIBLE");

            Console.ReadLine();
        }
    }


}
