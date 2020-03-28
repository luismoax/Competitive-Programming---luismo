using System;
using System.Collections.Generic;

using System.Text;

namespace ConsoleApplication1
{ 
    class Program
    {
        static void Main(string[] args)
        {
           
            int numberOfCases = 0;
            numberOfCases = int.Parse(Console.ReadLine());
            string[] p = new string[numberOfCases];

            for (int i = 0; i < numberOfCases; i++)
            {
                Console.ReadLine();
                
                double numberOfChildren = double.Parse(Console.ReadLine());
                double sum = 0;
                for (int j = 0; j < numberOfChildren; j++)
                {
                    sum += double.Parse(Console.ReadLine());
                }                
                if (sum % numberOfChildren == 0) p[i] = "YES";
                else p[i] = "NO";
            }
            for (int c = 0; c < p.Length; c++)
            {
                Console.WriteLine(p[c]);
            }
        }
        

    }    
}