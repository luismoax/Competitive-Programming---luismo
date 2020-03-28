using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace COJ
{
    class Program
    {
        static void Main(string[] args)
        {            
            int tc = int.Parse(Console.ReadLine());
            int[] rst = new int[tc];
            List<string> lst = new List<string>();
         
            for (int i = 0; i < tc; i++)
			{
                string input = Console.ReadLine();		
                if (Div495(input)) lst.Add("YES");
                else lst.Add("NO");                	 
			}
            foreach (string item in lst)
            {
                Console.WriteLine(item);
            }

            Console.ReadLine();
        }
        static bool Div495(string n)
        {
            //debe ser divisible por 5, por 9 y por 11
            //Menor que 495
            if (n.Length <= 3 && int.Parse(n) < 495) return false;
            //Div5            
            if (n[n.Length - 1] != '0' && n[n.Length - 1] != '5') return false;
            int fn11 = 0;
            int fn9 = 0;
            for (int c = 0; c < n.Length; c++)
            {
                if (c % 2 == 0) fn11 += int.Parse(n[c].ToString());
                else fn11 -= int.Parse(n[c].ToString());

                fn9 += int.Parse(n[c].ToString());
            }
            return fn11 % 11 == 0 && fn9%9==0;
        }
        
    }
}
