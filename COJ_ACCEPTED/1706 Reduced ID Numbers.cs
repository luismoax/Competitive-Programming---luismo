using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace COJ
{
    class Program
    {        
        static void Main(string[] args)
        {
            //1706 Reduced ID Numbers
            int tc = int.Parse(Console.ReadLine());
            for (int k = 0; k < tc; k++)
            {
                int G = int.Parse(Console.ReadLine());
                List<int> SINs = new List<int>();
                int max = 0;
                //Leyendo los sin
                for (int i = 0; i < G; i++)
                {
                    int x = int.Parse(Console.ReadLine());
                    SINs.Add(x);
                    if (x > max)
                        max = x;
                }

                bool ok = true;
                int final = 1;
                for (int i = G; i <= max+1; i++)
                {                    
                    bool[] rst = new bool[i];
                    ok = true;
                    for (int j = 0; j < SINs.Count; j++)
                    {
                        if (rst[SINs[j] % i] == true)
                        {
                            ok = false;
                            break;
                        }
                        rst[SINs[j] % i] = true;
                    }
                    if (ok)
                    {
                        final = i;
                        break;
                    }
                }
                Console.WriteLine(final);
                
            }
			
            Console.ReadLine();
        }

    }

}
