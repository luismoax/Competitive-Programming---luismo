using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Collections;
using System.Globalization;
// good one
//using C = System.Console;

namespace COJ
{
    class MainClass
    {
        /// <summary>
        /// Author: Luismo
        /// Idea: Easy Sorting (create a class Card)
        /// </summary>
        /// <param name="args"></param>
        /// 
        
        public static void Main(string[] args)
        {
            //string[] data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
   
            TextReader tr = Console.In;
            

            SolveSingleProblem();

            Console.SetIn(tr);
            Console.ReadLine();
        }


        static void SolveSingleProblem()
        {
            char[] denom = { 'S', 'H', 'C', 'D' };
            int n = int.Parse(Console.ReadLine());
            for (int p = 0; p < n; p++)
            {
                string[] data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                Card[] cards = new Card[data.Length - 1];
                for (int i = 1; i < data.Length; i++)
                {
                    int den = Array.IndexOf(denom, data[i][data[i].Length - 1]);
                    
                    string ss = data[i].Substring(0, data[i].Length - 1);
                    int num = 0;

                    switch (ss)
                    {
                        case "A":
                                num=1;
                            break;
                        case "J":
                            num = 11;
                            break;
                        case "Q":
                            num = 12;
                            break;
                        case "K":
                            num = 13;
                            break;
                        case "T":
                            num = 10;
                            break;
                        default:
                            num = num = int.Parse(ss);
                            break;
                    }

                    cards[i-1] = new Card(num, den);
                }

                Array.Sort(cards);

                for (int i = 0; i < cards.Length; i++)
                {
                    if(i!=0)
                        Console.Write(" "+cards[i]);
                    else Console.Write(cards[i]);
                }
                Console.WriteLine();

            }

        }

    }


    class Card:IComparable<Card>
    {
        char[] denom = { 'S', 'H', 'C', 'D' };

        public int number, denomination;
        public Card(int number, int denomination)
        {
            this.number = number;
            this.denomination = denomination;
        }

        public int CompareTo(Card other)
        {
            if (this.number == other.number)
                return this.denomination.CompareTo(other.denomination);
            return this.number.CompareTo(other.number);
        }

        public override string ToString()
        {
            string nm="";
            switch (number)
            {
                case 1:
                    nm = "A";
                    break;
                case 11:
                    nm = "J";
                    break;
                case 12:
                    nm = "Q";
                    break;
                case 13:
                    nm = "K";
                    break;
                case 10:
                    nm = "T";
                    break;  

                default:
                    nm = number.ToString();
                    break;
            }
            return nm+denom[denomination];
        }
    }

}
