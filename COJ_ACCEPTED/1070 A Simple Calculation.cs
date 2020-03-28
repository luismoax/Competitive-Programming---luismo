using System;
using System.Collections.Generic;
using System.Text;

namespace COJ
{
    class Program
    {
        static void Main(string[] args)
        {
            string input = Console.ReadLine();
            List<object> rslt = new List<object>();
            while (input != null && input != "")
            {
                rslt.Add(ChessSqRct(int.Parse(input)));
                input = Console.ReadLine();
            }
            foreach (object item in rslt)
            {
                Console.WriteLine(item);
            }
            Console.ReadLine();
        }
        static string ChessSqRct(int n)
        {
            if (n == 1) return "1 1";

            int sq = 0;
            int rct = 0;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    rct += (n - i + 1) * (n - j + 1);
                    if (i == j) sq += (n - i + 1) * (n - j + 1);
                }
            }
            return sq + " " + rct;
        }
    }
}
