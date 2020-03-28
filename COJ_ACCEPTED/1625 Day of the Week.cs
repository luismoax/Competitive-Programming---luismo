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
            //1625 Day of the Week
            string[] months = { "JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE", "JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER" };
            int tc = int.Parse(Console.ReadLine());
            for (int c = 0; c < tc; c++)
            {
                string[] p = Console.ReadLine().Split(' ');
                int k = -1;
                for (int i = 0; i < months.Length; i++)
                {
                    if (months[i] == p[1]) { k = i+1; break; }
                }
                DateTime dt = new DateTime(int.Parse(p[0]), k, int.Parse(p[2]));
                Console.WriteLine(dt.DayOfWeek.ToString().ToUpper());
            }
            

            Console.ReadLine();
        }        

    }


}
