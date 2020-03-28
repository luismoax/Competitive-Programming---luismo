using System;

namespace uce
{
    class Program
    {
        public static void Main(string[] args)
        {
            //1069 Soda Supler
            int tc = int.Parse(Console.ReadLine());
            for (int c = 0; c < tc; c++)
            {
                string[] p = Console.ReadLine().Split(' ');
                int emptyBott = int.Parse(p[0]) + int.Parse(p[1]);
                int cost = int.Parse(p[2]);
                if (cost == 1) Console.WriteLine("0");
                else
                {
                    int totalDrunk = 0;
                    while (emptyBott >= cost)
                    {
                        int earn = emptyBott / cost;
                        totalDrunk += earn;
                        emptyBott = emptyBott % cost;
                        emptyBott += earn;
                    }
                    Console.WriteLine(totalDrunk);
                }                
            }
            Console.ReadLine();
        }
    }
}