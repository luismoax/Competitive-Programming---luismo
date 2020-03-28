using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace COJ
{
    class Program
    {
        static void Main(string[] args)
        {
            string input = Console.ReadLine();
            while (input != "0")
            {
                int cortes = int.Parse(input);
                input = Console.ReadLine();

                string[] array = new string[cortes];

                for (int c = 0; c < input.Length; c++)
                {
                    if ((c / cortes) % 2 == 0)
                    {
                        array[c % cortes] += input[c];
                    }
                    else
                    {
                        int h = ((c / cortes + 1) * cortes) - c % cortes - 1;
                        array[c % cortes] += input[h];
                    }
                }
                foreach (object item in array)
                {
                    Console.Write(item);
                }
                Console.WriteLine();

                input = Console.ReadLine();
            }
            Console.ReadLine();
        }

    }
}
