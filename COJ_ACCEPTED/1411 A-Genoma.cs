using System;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            //1411 A-Genoma
            int tc = int.Parse(Console.ReadLine());
            for (int c = 0; c < tc; c++)
            {
                Console.WriteLine("Case "+(c+1));
                string alienG = Console.ReadLine();
                int terrestialCreatures = int.Parse(Console.ReadLine());
                for (int i = 0; i < terrestialCreatures; i++)
                {
                    string s = Console.ReadLine();
                    int x = StringMatchingNaive(alienG,s);
                    if (x > 0) Console.WriteLine(x);
                    else Console.WriteLine("Darwin was right about this creature");
                }
            }
            Console.ReadLine();
        }

        static int StringMatchingNaive(string text, string s)
        {
            int adev = 0;

            for (int i = 0; i < text.Length-s.Length+1; i++)
            {
                bool bt = true;
                for (int j = 0; j < s.Length; j++)
                {
                    if (s[j] != text[i+j]) { bt = false; break; }
                }
                if (bt) adev++;
            }
            return adev;
        }        

    }
}
