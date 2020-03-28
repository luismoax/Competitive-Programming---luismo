using System;
using System.Collections.Generic;
using System.Text;

namespace COJ
{
    class Program
    {
		//1116 Cantoring Along
        static void Main(string[] args)
        {
            string[] arr = Cantoring();
            
            string xin = Console.ReadLine();
            while (xin !=null)
            {
                int n = int.Parse(xin);
                Console.WriteLine(arr[n]);
                xin = Console.ReadLine();
            }            
            Console.ReadLine();
        }

        static string[] Cantoring()
        {
            string[] adev = new string[13];
            adev[0] = "-";
            string ax = " ";

            for (int i = 1; i < adev.Length; i++)
            {
                adev[i] = adev[i - 1] + ax + adev[i - 1];
                ax = ax + ax + ax;
            }
            return adev;
        }
    }
}
