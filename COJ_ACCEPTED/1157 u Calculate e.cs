using System;

namespace uce
{
    class Program
    {
        public static void Main (string[] args)
        {
            double[] fct = new double[10];
            double[] rst = new double[10];
            fct[0] = 1;
            rst[0] = 1;

            Console.WriteLine("n e");
            Console.WriteLine("- -----------");
            Console.WriteLine("0 1");
            Console.WriteLine("1 2");
            Console.WriteLine("2 2.5");
            Console.WriteLine("3 2.666666667");
            Console.WriteLine("4 2.708333333");

            for (int c = 0; c < 10; c++)
            {
                if (c > 0)
                {
                    fct[c] = c * fct[c - 1];
                    rst[c] = 1 / fct[c] + rst[c - 1];
                }
                if(c>=5)
                    Console.WriteLine(c + " {0:f9}", rst[c]);
            }
            Console.ReadLine();
        }

    }
}
