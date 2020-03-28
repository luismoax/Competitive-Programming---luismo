using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CP
{
    class Program
    {
		// Easy one working with maps for efficiency
        static void Main(string[] args)
        {
            TextReader tr = Console.In;
            
            //Console.SetIn(new StreamReader(@"d:\lmo.in"));
            SolveSingleProblem();

            Console.SetIn(tr);
            Console.ReadLine();
        }



        static void SolveSingleProblem()
        {
            int tc = int.Parse(Console.ReadLine());
            for (int t = 0; t < tc; t++)
            {
                string[] data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                int n = int.Parse(data[0]);
                int m = int.Parse(data[1]);

                Dictionary<char, int> map = new Dictionary<char, int>(); // mapping char with freq

                string [] alfabet = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries); //

                for (int i = 0; i < alfabet.Length; i++)
                {
                    map.Add(alfabet[i][0], 0);
                }
                
                

                string message = Console.ReadLine();
                for (int i = 0; i < message.Length; i++)
                {
                    map[message[i]]++;    
                }

                char[] build = new char[message.Length];
                int idx = 0;
                foreach (var item in map.OrderByDescending(p=> p.Value))
                {
                    for (int j = 0; j < message.Length; j++)
                    {
                        if (message[j] == item.Key)
                            build[j] = alfabet[idx][0];
                    }
                    idx++;
                }

                string sss = new string(build);
                Console.WriteLine(sss);

            }
        }


    }

    class CharFreq
    {
        public char ch;
        public int freq;
        public CharFreq(char ch, int freq)
        {
            this.ch = ch;
            this.freq = freq;
        }
    }

}
