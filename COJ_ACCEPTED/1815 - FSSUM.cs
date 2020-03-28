using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace COJ
{
    class Program
    {
        static void Main(string[] args)
        {
            int l = int.Parse(Console.ReadLine());
            string[] p = Console.ReadLine().Split(' ');
            int[] arr = new int[p.Length];
            for (int i = 0; i < p.Length; i++)
            {
                arr[i] = int.Parse(p[i]);
            }
            int q = int.Parse(Console.ReadLine());
            p = Console.ReadLine().Split(' ');
            //Por c\pregunta
            for (int i = 0; i < q; i++)
            {
                if(SubListSum(arr,int.Parse(p[i]),0,0))
                    Console.WriteLine("YES");
                else Console.WriteLine("NO");
            }

            Console.ReadLine();
        }

        static bool SubListSum(int[] values, int q, int cnt,int index)
        {
            if (cnt == q)
                return true;
            if(index == values.Length)
                return false;
                        
            if (cnt + values[index] <= q)
            {
                return SubListSum(values, q, cnt + values[index], index + 1) || SubListSum(values, q, cnt, index + 1);
            }

            return SubListSum(values, q, cnt, index + 1);
        }

    }

}
