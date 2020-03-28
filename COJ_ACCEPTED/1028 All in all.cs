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
            List<object> lst = new List<object>();
            string input = Console.ReadLine();
            while (input!="" && input!=null)
            {
                string[] p = input.Split(' ');
                if (SubSeq(p[0], p[1])) lst.Add("Yes");
                else lst.Add("No");
                input = Console.ReadLine();
            }            
            foreach (object item in lst)
            {
                Console.WriteLine(item);
            }            
            Console.ReadLine();
        }

        static bool SubSeq(string aBuscar,string fuente)
        {
            bool found = false;
            int k = 0;
            for (int c = 0; c < aBuscar.Length; c++)
            {
                for (int d = k; d < fuente.Length; d++)
                {
                    if (fuente[d] == aBuscar[c]) { found = true; k = d + 1; break; }
                }
                if (found) found = false;
                else return false;
            }
            return true;
        }
    }
}
