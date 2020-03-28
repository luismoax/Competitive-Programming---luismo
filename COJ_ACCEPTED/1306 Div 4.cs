using System;
using System.Collections.Generic;
using System.Text;

namespace smtp
{
    class Program
    {
        static void Main(string[] args)
        {
            int numberOfCases = int.Parse( Console.ReadLine());
            string [] fn = new string[numberOfCases];
            int ind= 0;
            for (int i = 0; i < numberOfCases; i++)
            {
                string number = Console.ReadLine();
                string ax = "";
                if (number.Length <= 2)
                    ax = number;
                else
                {
                    ax += number[number.Length - 2];
                    ax += number[number.Length - 1];
                    
                }

                if (int.Parse(ax) % 4 == 0) fn[ind] = "YES";
                else fn[ind] = "NO";
                ind++;
            }

            for (int i = 0; i < numberOfCases; i++)
            {
                Console.WriteLine(fn[i]);
            }
            
            Console.ReadLine();
        }
    }
}
