using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ACM_ICPC
{
    class Program
    {
        
        static void Main(string[] args)
        {

            string baseTwo = Console.ReadLine();
            string baseTree = Console.ReadLine();
            Console.WriteLine( Result(baseTwo, baseTree) );

            Console.ReadLine();
        }

        private static int Result(string baseTwo, string baseTree)
        {
            for (int i = 0; i < baseTwo.Length; i++)
            {
                for (int j = 0; j < baseTree.Length; j++)
                {
                    string bin = "", tree = "";
                    //Binary
                    if (baseTwo[i] == '0')
                        bin = baseTwo.ReplaceAt(i, "1");
                    else bin = baseTwo.ReplaceAt(i, "0");

                    for (int k = 0; k < 3; k++)
                    {
                        if (baseTree[j] != k.ToString()[0])
                            tree = baseTree.ReplaceAt(j, k.ToString());

                        //Llamo a comparar
                        int t = FromBaseToDecimal(tree,3);
                        int b = FromBaseToDecimal(bin,2);
                        if (t == b)
                        {
                            return b;
                        }
                    }
                }
            }
            return -1;
        }

        static int FromBaseToDecimal(string number,int oldBase)
        {
            number.TrimStart('0');
            int n = 0;
            for (int i = 0; i < number.Length; i++)
            {
                n += int.Parse(number[number.Length - 1 - i].ToString()) * (int)Math.Pow(oldBase, i);
            }
            return n;
        }        
    }

    static class StringExtensions
    {
        public static string ReplaceAt(this string str,int index,string value)
        {
            string newString = "";
            for (int i = 0; i < str.Length; i++)
            {
                if (i != index)
                    newString += str[i];
                else newString += value;                
            }
            return newString;
        }
    }
}
