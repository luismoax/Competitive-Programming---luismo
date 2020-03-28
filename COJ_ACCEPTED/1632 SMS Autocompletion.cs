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
            //1632 SMS Autocompletion
            string xin = Console.ReadLine();

            List<string> phraseList = new List<string>();
            List<string> diccLst = new List<string>();
            bool diccNow = false;
            while (xin != null)
            {
                if (xin == "-----") diccNow = true;
                if (!diccNow)
                    phraseList.Add(xin);
                else diccLst.Add(xin);
                
                xin = Console.ReadLine();
            }

            List<string> adev = new List<string>();
            adev.Add("-----");
            for (int c = 0; c < phraseList.Count; c++)
            {
                string code = CodeWord(phraseList[c]);
                foreach (string item in diccLst)
                {
                    if (code == CodeWord(item)) adev.Add(item);
                }
                adev.Add("-----");
            }

            //Sacando la respuesta
            foreach (string item in adev)
            {
                Console.WriteLine(item);
            }

            Console.ReadLine();
        }

        static string CodeWord(string s)
        {
            string adev = "";
            foreach (char item in s)
            {
                adev += CodeChar(item).ToString();
            }
            return adev;
        }

        static int CodeChar(char c)
        {
            switch (c)
            {
                case 'a':
                    return 1;
                case 'b':
                    return 1;
                case 'c':
                    return 1;

                case 'd':
                    return 2;
                case 'e':
                    return 2;
                case 'f':
                    return 2;

                case 'g':
                    return 3;
                case 'h':
                    return 3;
                case 'i':
                    return 3;

                case 'j':
                    return 4;
                case 'k':
                    return 4;
                case 'l':
                    return 4;

                case 'm':
                    return 5;
                case 'n':
                    return 5;
                case 'o':
                    return 5;

                case 'p':
                    return 6;
                case 'q':
                    return 6;
                case 'r':
                    return 6;

                case 's':
                    return 7;
                case 't':
                    return 7;
                case 'u':
                    return 7;

                case 'v':
                    return 8;
                case 'w':
                    return 8;
                case 'x':
                    return 8;

                case 'y':
                    return 9;
                case 'z':
                    return 9;

                default:
                    return -1;
            }
        }


    }
}
