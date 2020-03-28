using System;
using System.Collections.Generic;
using System.Text;

namespace COJ
{
    class Program
    {
        static void Main(string[] args)
        {
            int nOC = int.Parse(Console.ReadLine());
            string[] rst = new string[nOC];
            int ind=0;

            for (int i = 0; i < nOC; i++)
            {
                //X%6==0 <=> 3|x ^ 2|x
                string x = Console.ReadLine();
                //Si se divide por 2
                if (int.Parse(x[x.Length - 1].ToString()) % 2 == 0)
                {
                    //Y ademas se divide por 3
                    int k = 0;
                    for (int c = 0; c < x.Length; c++)
                    {
                        k += int.Parse(x[c].ToString());
                    }
                    if (k % 3 == 0)
                        rst[ind] = "YES";
                    else rst[ind] = "NO";
                }
                else rst[ind] = "NO";
                ind++;

            }

            foreach (string var in rst)
            {
                Console.WriteLine(var);
            }

            Console.ReadLine();
        }
    }
}
