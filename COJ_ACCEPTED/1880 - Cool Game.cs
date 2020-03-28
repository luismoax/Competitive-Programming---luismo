using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace COJ
{
    class Program
    {
       
        static void Main(string[] args)
        {
            int tc = int.Parse(Console.ReadLine());
            for (int t = 0; t < tc; t++)
            {
                int n = int.Parse(Console.ReadLine());
                //Para ir llevando las sumas de la matriz original
                int sm = 0;
                for (int i = 0; i < n; i++)
                {
                    string s = Console.ReadLine();
                    for (int j = 0; j < s.Length; j++)
                    {                        
                        sm += int.Parse(s[j].ToString());
                    }
                }

                bool posible = true;

                //Leemos la segundo matriz
                for (int i = 0; i < n; i++)
                {
                    string s = Console.ReadLine();
                    for (int j = 0; j < s.Length; j++)
                    {
                        sm -= int.Parse(s[j].ToString());
                    }                    
                }
                if(sm!=0)
                    Console.WriteLine("NO");
                else Console.WriteLine("YES");

            }

            Console.ReadLine();
        }

        

    }
}
