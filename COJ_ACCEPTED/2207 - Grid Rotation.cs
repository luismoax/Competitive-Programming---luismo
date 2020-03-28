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
            //TextReader tr = Console.In;   
            //Console.SetIn(new StreamReader(@"d:\lmo.in"));

            int n = int.Parse(Console.ReadLine());
            int[,] mt = new int[n, n];
            char[,] chmt = new char[n, n];
            for (int i = 0; i < n; i++)
            {
                string s = Console.ReadLine();
                for (int j = 0; j < s.Length; j++)
                {
                    chmt[i,j] = s[j];                    
                }
            }

            int q = int.Parse(Console.ReadLine());
            
            //Seg?n el n?mero de vueltas congruente m?dulo 4
            //0 mod 4 ->i,j
            //1 mod 4 ->j,n-i
            //2 mod 4 ->n-i,n-j
            //3 mod 4 ->n-j,i
            
            // Por cada pregunta
            for (int i = 0; i < q; i++)
            {                
                bool[] marks = new bool[4];
                int cnt = 4;
                for (int c = 0; c < n; c++)
                {
                    string s = Console.ReadLine();
                    for (int d = 0; d < s.Length; d++)
                    {
                        // Verificando para cada vuelta
                        if (!marks[0] && s[d] != chmt[c, d])
                        {
                            marks[0] = true;
                            cnt--;
                        }
                        if(!marks[1] && s[d] !=chmt[d,n-1-c])
                        {
                            marks[1]=true;
                            cnt--;
                        }
                        if(!marks[2] && s[d] !=chmt[n-1-c,n-1-d])
                        {
                            marks[2]=true;
                            cnt--;
                        }
                        if(!marks[3] && s[d] !=chmt[n-1-d,c])
                        {
                            marks[3]=true;
                            cnt--;
                        }
                    }
                }
                if(cnt==0)
                    Console.WriteLine("NO");
                else Console.WriteLine("YES");
            }
            //Console.SetIn(tr);
            Console.ReadLine();
        }


        #region M?todos Auxiliares
        static int ABS(int a)
        {
            if (a < 0)
                a *= -1;
            return a;
        }

        static void PrintMt(int[,] mt)
        {
            for (int i = 0; i < mt.GetLength(0); i++)
            {
                for (int j = 0; j < mt.GetLength(1); j++)
                {
                    Console.Write(mt[i, j] + " ");
                }
                Console.WriteLine();
            }
        }
        #endregion

    }

}
