using System;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] alfabet = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
            string []code = new string[26];
            string keyWord = Console.ReadLine();
            int keyNumber = int.Parse(Console.ReadLine());
            
            for (int c = 0; c < keyWord.Length; c++)
            {
                for (int d = 0; d < 26; d++)
                {
                    if (keyWord[c].ToString() == alfabet[d])
                    {
                        code[(keyNumber+c-1) % 26] = keyWord[c].ToString();
                        alfabet[d] = "";
                        break;
                    }
                }
            }
            int kind = (keyNumber-1 + keyWord.Length) % 26;
            for (int c = 0; c < 26; c++)
            {
                if (alfabet[c] != "")
                {
                    code[kind] = alfabet[c];
                    kind = (kind + 1) % 26;
                }
            }

            alfabet = new string[] { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};

            string text = Console.ReadLine();
            for (int c = 0; c < text.Length; c++)
            {                
                for (int d = 0; d < code.Length; d++)
                {
                    if (text[c].ToString() == code[d]) Console.Write(alfabet[d]);                    
                }
            }
            Console.ReadLine();
        }
    }
}
