using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace COJ
{
    class Program
    {
        static void Main(string[] args)
        {
            string xin = "";
            int cs = 1;
            while (!String.IsNullOrEmpty(xin = Console.ReadLine()))
            {
                string[] data = xin.Split(new char[] { '-' }, StringSplitOptions.RemoveEmptyEntries);
                int oddSum = int.Parse(data[0]);
                int pairSum = 0;
                for (int i = 0; i < 5; i++)
                {
                    if (i % 2 == 1)
                        oddSum += int.Parse(data[1][i].ToString());
                    else pairSum += int.Parse(data[1][i].ToString());
                }
                //**----**
                for (int i = 0; i < 5; i++)
                {
                    if (i % 2 == 1)
                        pairSum += int.Parse(data[2][i].ToString());
                    else oddSum += int.Parse(data[2][i].ToString());
                }
                
                int s = (3 * oddSum + pairSum);
                int n = (10 - (s%10))%10;
                Console.WriteLine("Case #{0}: {1}",cs,n );
                cs++;
            }
            Console.ReadLine();
        }


    }
}
