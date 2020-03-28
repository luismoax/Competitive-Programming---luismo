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
            //1627 Counting Zeros
            int tc = int.Parse(Console.ReadLine());
            for (int c = 0; c < tc; c++)
            {
                int n = int.Parse(Console.ReadLine());
                int raiser = 1;
                int numBer = 0;
                while (Math.Pow(5,raiser)<n)
                {
                    numBer += n / (int)Math.Pow(5,raiser);
                    raiser++;
                }
                Console.WriteLine(numBer);
            }
            Console.ReadLine();
        }        

    }


}
