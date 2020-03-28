using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace COJ
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] arr = new int[1001];

            for (int i = 1; i < arr.Length; i++)
            {
                arr[i] = ToBinaryInt(i)+arr[i-1];
            }

            int tc = int.Parse(Console.ReadLine());
            for (int t = 0; t < tc; t++)
            {
                string[] xin = Console.ReadLine().Split(new char[] { ' ' },StringSplitOptions.RemoveEmptyEntries);
                Console.WriteLine(arr[int.Parse(xin[1])] - arr[int.Parse(xin[0])-1]);
            }

            Console.ReadLine();
        }


        static int ToBinaryInt(int n)
        {   
            int cnt = 0;
            while (n>0)
            {
                if (n % 2 == 1)
                    cnt++;
                n /= 2;
            }
            return cnt;
            
        }
    }
}
