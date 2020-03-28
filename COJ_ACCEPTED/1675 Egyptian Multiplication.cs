using System;
using System.Collections.Generic;
using System.Text;
using System.IO;


namespace COJ
{
    class Program
    {
        //
        static void Main(string[] args)
        {
            string xin = Console.ReadLine();
            long cs = 1;
            while (xin != "-1")
            {
                string[] p = xin.Split(' ');
                long n = long.Parse(p[0]);
                long m = long.Parse(p[1]);

                List<long> powers = new List<long>();
                List<long> values = new List<long>();
                //powers.Add(1);                
                //values.Add(m);

                //Parche para 0
                if (n == 0 || m == 0)
                {
                    Console.WriteLine("Case {0}: {1} x {2} = {3}", cs, n, m, 0);
                }
                else
                {
                    long pw = 1;
                    while (pw <= n)
                    {
                        powers.Add(pw);
                        values.Add(m * pw);
                        pw *= 2;
                    }
                    List<long> aux = new List<long>();
                    long xx = n;
                    int find = powers.Count - 1;
                    while (xx > 0)
                    {
                        for (int k = find; k >= 0; k--)
                        {
                            if (xx - powers[k] >= 0)
                            {
                                xx -= powers[k];
                                aux.Add(values[k]);
                            }
                        }
                    }

                    string sumas = "";
                    if (p[2] == "b")
                    {
                        long x = n;
                        for (int i = 0; i < aux.Count; i++)
                        {
                            if (i == 0) sumas += aux[i];
                            else sumas += " + " + aux[i];
                        }
                        Console.WriteLine("Case {0}: {1} x {2} = {3}", cs, n, m, sumas);
                    }
                    else
                    {
                        for (int i = 0; i < aux.Count; i++)
                        {
                            if (i == 0) sumas += aux[aux.Count - 1 - i];
                            else sumas += " + " + aux[aux.Count - 1 - i];
                        }
                        Console.WriteLine("Case {0}: {1} x {2} = {3}", cs, n, m, sumas);
                    }
                }
                xin = Console.ReadLine();
                cs++;
            }

            Console.ReadLine();
        }


    }

}