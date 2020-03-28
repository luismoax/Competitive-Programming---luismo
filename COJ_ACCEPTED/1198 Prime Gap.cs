using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            
            List<object> lst = new List<object>();
            int tc = int.Parse(Console.ReadLine());
            for (int c = 0; c < tc; c++)
            {
                int k = int.Parse(Console.ReadLine());
                bool[] b = new bool[k];
                int unlocked = 0;
                for (int i = 1; i <= k; i++)
                {
                    for (int j = 1; j <= k; j+=i)
                    {                    
                        if (b[j - 1])
                        {
                            b[j - 1] = false;
                            unlocked--;
                        }
                        else
                        {
                            b[j - 1] = true;
                            unlocked++;
                        }                        
                    }
                }
                lst.Add(unlocked);
            }


            foreach (object var in lst)
            {
                Console.WriteLine(var);
            }

            Console.ReadLine();
        }

        

        static bool IsPRime(int n)
        {
            if (n < 2) return false;
            for (int c = 2; c <= Math.Sqrt(n); c++)
            {
                if (n % c == 0) return false;
            }
            return true;
        }

        static int PrimeGap(int n)
        {
            if (IsPRime(n)) return 0;
            bool bb = false;
            int k = n+1;
            int suma = 1;
            while (!bb)
            {
                if (IsPRime(k))
                {
                    bb = true;
                }
                else suma++;
                k++;
            }
            bb = false;
            k = n - 1;
            while (!bb)
            {
                if (IsPRime(k))
                {
                    bb = true;
                }
                else suma++;
                k--;
            }
            return suma + 1;
        }
    }
}
