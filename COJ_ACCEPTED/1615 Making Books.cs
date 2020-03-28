using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            //1615 Making Books
            string xin = Console.ReadLine();
            int xcase = 0;
            while (xin!="0")
            {
                string[] p = xin.Split(' ');
                int[] nON = new int[10];
                int a = Math.Min(int.Parse(p[0]), int.Parse(p[1]));
                int b = Math.Max(int.Parse(p[0]), int.Parse(p[1]));
                for (int c = a; c <= b; c++)
                {
                    string x = c.ToString();
                    for (int d = 0; d < x.Length; d++)
                    {
                        #region Switch for numbers
                        switch (x[d])
                        {
                            case '0':
                                nON[0]++;
                                break;
                            case '1':
                                nON[1]++;
                                break;
                            case '2':
                                nON[2]++;
                                break;
                            case '3':
                                nON[3]++;
                                break;
                            case '4':
                                nON[4]++;
                                break;
                            case '5':
                                nON[5]++;
                                break;
                            case '6':
                                nON[6]++;
                                break;
                            case '7':
                                nON[7]++;
                                break;
                            case '8':
                                nON[8]++;
                                break;
                            case '9':
                                nON[9]++;
                                break;

                            default:
                                break;
                        }
                        #endregion                        
                    }                    
                }
                xcase++;
                Console.WriteLine("Case {10}: 0:{0} 1:{1} 2:{2} 3:{3} 4:{4} 5:{5} 6:{6} 7:{7} 8:{8} 9:{9}", nON[0], nON[1], nON[2], nON[3], nON[4], nON[5], nON[6], nON[7], nON[8], nON[9],xcase);
                xin = Console.ReadLine();
            }

        }
    }
}
