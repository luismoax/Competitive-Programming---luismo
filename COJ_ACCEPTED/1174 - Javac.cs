using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            //1174 Javac
            string xin = Console.ReadLine();
            while (xin != null && xin != "")
            {
                bool er = false;
                string resutl = "";
                string[] p = xin.Split(new char[] { '_' }, StringSplitOptions.RemoveEmptyEntries);
                if (xin.Contains("__") || xin[0] == '_' || xin[xin.Length-1] == '_')
                    er = true;
                else if (p.Length > 1)
                {
                    //Si hay underscores reciso la caden por si hay mayusculas
                    for (int i = 0; i < xin.Length; i++)
                    {
                        if (Char.IsUpper(xin[i])) { er = true; break; }
                    }
                    //Sino hubo error
                    if (!er)
                    {
                        //Anyado el primer caracter
                        resutl += p[0][0];
                        for (int j = 0; j < p.Length; j++)
                        {
                            if (j > 0) resutl += Char.ToUpper(p[j][0]);
                            for (int k = 1; k < p[j].Length; k++)
                            {
                                resutl += p[j][k];
                            }
                        }
                    }
                }
                else
                {
                    if (Char.IsUpper(xin[0])) er = true;
                    else
                    {
                        for (int i = 0; i < xin.Length; i++)
                        {
                            if (Char.IsUpper(xin[i])) resutl += "_" + char.ToLower(xin[i]);
                            else resutl += xin[i];
                        }
                    }
                }                
                
                if (er) Console.WriteLine("Error!");
                else Console.WriteLine(resutl);

                xin = Console.ReadLine();
            }

            Console.ReadLine();
        }

    }
}
