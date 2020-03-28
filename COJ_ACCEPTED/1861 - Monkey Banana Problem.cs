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
            /*
             * Dinamica analoga a la suma en triangulo
             * */
            int tc = int.Parse(Console.ReadLine());
            for (int t = 0; t < tc; t++)
            {
                int n = int.Parse(Console.ReadLine());
                long [] ax = null;
                List<long> lst = new List<long>();
                
                lst.Add(long.Parse(Console.ReadLine()));
                for (int i = 1; i < 2*n - 1; i++)
                {
                    string [] p = Console.ReadLine().Split(' ');
                    ax = new long[p.Length];
                    for(int c=0;c<p.Length;c++)
                        ax[c] = long.Parse(p[c]);

                    if (i < n)
                    {
                        for (int c = 0; c < ax.Length; c++)
                        {
                            if (c == 0)
                                ax[0] += lst[0];
                            else if (c == ax.Length - 1)
                            {
                                ax[c] += lst[c - 1];
                            }
                            else
                            {
                                ax[c] += Math.Max(lst[c], lst[c - 1]);
                            }
                        }
                    }
                    else
                    {
                        for (int c = 0; c < ax.Length; c++)
                        {
                            if (c == 0)
                                ax[0] += Math.Max( lst[0],lst[1]);                            
                            else
                            {
                                ax[c] += Math.Max(lst[c], lst[c + 1]);
                            }
                        }
                    }

                    lst = new List<long>(ax);
                }


                Console.WriteLine("Case {0}: {1}",t+1,lst[0]);

            }

            Console.ReadLine();
        }

    }
}
