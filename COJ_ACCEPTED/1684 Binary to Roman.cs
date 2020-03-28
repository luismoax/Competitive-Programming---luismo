using System;
using System.Collections.Generic;
using System.Text;

namespace COJ
{
    class Program
    {
        //1684 Binary to Roman
        static void Main(string[] args)
        {
            /*
             * la idea es ir con las letras mas grandes, 
             * primeros ves para mil (M) y vas restando 1000 tantas veces como puedas, 
             * luego lo haces con D=500, luego C=100, L=50, X=10, I=1, 
             * siempre verificas si mejor restar q poner las letras normal, ejemplo 4=IV 
             * en vez de IIII, 19=XIX en vez de XVIIII, esa es la idea
             * 
             */

            int tc = int.Parse(Console.ReadLine());
            for (int i = 0; i < tc; i++)
            {
                string bRep = Console.ReadLine();
                int n = ToDecimal(bRep);
                Console.WriteLine(ToRoman(n));
            }


            Console.ReadLine();
        }

        static int ToDecimal(string binaryRepresentation)
        {
            int n = 0;
            for (int i = 0; i < binaryRepresentation.Length; i++)
            {
                n += int.Parse(binaryRepresentation[binaryRepresentation.Length - 1 - i].ToString()) * (int)Math.Pow(2, i);
            }
            return n;
        }

        static string ToRoman(int n)
        {
            string romanNumber = "";
            int k = n / 1000;
            //Poniendo la M
            for (int i = 0; i < k; i++)
            {
                romanNumber += "M";
            }

            //Poniendo Centenas
            n = n % 1000;
            k = n / 100;
            if (k == 4) { romanNumber += "CD"; k = 0; }
            else if (k == 9) { romanNumber += "CM"; k = 0; }
            else if (k >= 5)
            {
                romanNumber += "D";
                k -= 5;

            }
            for (int i = 0; i < k; i++)
            {
                romanNumber += "C";
            }


            //Poniendo decenas
            n = n % 100;
            k = n / 10;
            if (k == 4) { romanNumber += "XL"; k = 0; }
            else if (k == 9) { romanNumber += "XC"; k = 0; }
            else if (k >= 5)
            {
                romanNumber += "L";
                k -= 5;
            }
            for (int i = 0; i < k; i++)
            {
                romanNumber += "X";
            }

            //PPoniendo unidades
            n = n % 10;
            k = n;
            if (k == 4) { romanNumber += "IV"; k = 0; }
            else if (k == 9) { romanNumber += "IX"; k = 0; }
            else if (k >= 5)
            {
                romanNumber += "V";
                k -= 5;
            }
            //Poniendo el resto
            for (int i = 0; i < k; i++)
            {
                romanNumber += "I";
            }

            return romanNumber;
        }

    }
}
