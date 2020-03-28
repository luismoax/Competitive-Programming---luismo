using System;
using System.Collections.Generic;
using System.Text;

namespace COJ
{
    class Program
    {
        static void Main(string[] args)
        {
            string xin = Console.ReadLine();
            //verificamos
            bool flag = false;
            for (int i = 1; i < xin.Length; i++)
            {
                if (xin[i].ToString() == xin[i].ToString().ToUpper())
                {
                    flag = true;
                    break;
                }
            }
            if (flag) Console.WriteLine(ChangeAll(xin));
            else Console.WriteLine(xin);

            Console.ReadLine();
        }

        static string ChangeAll(string s)
        {
            string ax = "";
            for (int i = 0; i < s.Length; i++)
            {
                //Si esta en minuscula
                if (s[i].ToString() == s[i].ToString().ToLower())
                    ax += s[i].ToString().ToUpper();
                else ax += s[i].ToString().ToLower();
            }
            return ax;
        }
    }
}
