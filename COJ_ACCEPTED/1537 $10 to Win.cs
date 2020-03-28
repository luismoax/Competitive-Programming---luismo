using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication26
{
    class Program
    {
        static void Main(string[] args)
        {
            int tc = int.Parse(Console.ReadLine());
            for (int t = 0; t < tc; t++)
            {
                string[] elvis = Console.ReadLine().Split(' ');

                int cantWager = int.Parse(elvis[1]);
                double originalWager = double.Parse(elvis[0]);
                double wager = originalWager;

                double totalWon = 0;

                for (int i = 0; i < cantWager; i++)
                {
                    double  moneyline = double.Parse(Console.ReadLine());
                    double multiplayer = 0;
                    if (moneyline >= 0)
                        multiplayer = moneyline / 100;
                    else multiplayer = 100 / moneyline*-1;

                    multiplayer = Math.Round(multiplayer, 3,MidpointRounding.AwayFromZero);
                    double won = Math.Ceiling( wager * multiplayer);

                    totalWon += won;
                    wager += won;
                }
                totalWon += originalWager; 
                if (totalWon  > 1000000)
                {
                    totalWon = 1000000;                    
                }

                string s = (totalWon).ToString();
                string ss = "";
                for (int i = 0; i < s.Length; i++)
                {
                    ss = s[s.Length-1-i]+ss;
                    if ((i + 1) % 3 == 0)
                        ss = "," + ss;
                }
                if (ss[0] == ',')
                    ss = ss.Remove(0, 1);


                Console.WriteLine("{0} ${1}.00",t+1,ss);
            }


            Console.ReadLine();
        }
    }
}
