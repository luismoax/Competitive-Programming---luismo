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
			//1475 Cedric's Cypher
            char[] alfabet = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };            
            string xin = Console.ReadLine();
            while (xin!="#")
            {
                //Cojo el ultimo caracter
                char lst = Char.ToLower( xin[xin.Length - 1]);
                //Busco su corrimiento
                int shift = -1;
                for (int c = 0; c < alfabet.Length; c++)
                {
                    if (alfabet[c] == lst) { shift = c; break; }
                }
                string adev = "";                
                for (int c = 0; c < xin.Length-1; c++)
                {
                    int kind = -1;
                    bool uppered = false;
                    for (int d = 0; d < alfabet.Length; d++)
                    {
                        if (alfabet[d] == Char.ToLower(xin[c])) 
                        {
                            kind = d;
                            //Si es una mayuscula
                            if(Char.ToUpper(alfabet[d]) == xin[c]) uppered = true;
                            break; 
                        }
                    }
                    //Si no es una letra del alfabeto
                    if (kind == -1) adev += xin[c];
                    else
                    {
                        if (kind - shift < 0) kind = alfabet.Length - Math.Abs(kind - shift);
                        else kind = kind - shift;
                        if (uppered) adev += Char.ToUpper(alfabet[kind]);
                        else adev += alfabet[kind];
                    }
                }
                Console.WriteLine(adev);
                xin = Console.ReadLine();
            }
            Console.ReadLine();
        }
    }
}
