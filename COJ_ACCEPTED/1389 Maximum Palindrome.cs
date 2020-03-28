using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        //1389 Maximum Palindrome
        static void Main(string[] args)
        {
            string number = Console.ReadLine();

            Console.WriteLine(LargestPalindrome(number));

            Console.ReadLine();
        }

        static string LargestPalindrome(string s)
        {
            string adev = "";
            //Por todas las longitudes posibles
            for (int i = s.Length; i >=1 ; i--)
            {
                //Por todas las posiciones posibles
                for (int j = 0; j <= s.Length-i; j++)
                {
                    if (IntervaPalindrome(s, j, j + i-1)) return s.Substring(j, i);
                }
            }
            return adev;
        }

        static bool IntervaPalindrome(string s, int initialPos, int finalPos)
        {
            for (int c = 0; c < (finalPos-initialPos)/2; c++)
            {
                if (s[initialPos + c] != s[finalPos - c]) return false;
            }
            return true;
        }

    }

}
