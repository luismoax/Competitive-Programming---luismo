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
            //1212 Jingles
            string xin = Console.ReadLine();
            while (xin !="*")
            {
                string [] p = xin.Split('/');
                int numberOfBadMeasure = 0;
                for (int c = 0; c < p.Length; c++)
                {
                    double sum = 0;
                    for (int d = 0; d < p[c].Length; d++)
                    {
                        #region Switch
                        switch (p[c][d])
                        {
                            case 'W':
                                sum += 1;
                                break;
                            case 'H':
                                sum += 1/2.0;
                                break;
                            case 'Q':
                                sum += 1/4.0;
                                break;
                            case 'E':
                                sum += 1/8.0;
                                break;
                            case 'S':
                                sum += 1/16.0;
                                break;
                            case 'T':
                                sum += 1/32.0;
                                break;
                            case 'X':
                                sum += 1/64.0;
                                break;
                            default:
                                break;
                        }
                        #endregion                        
                    }
                    if (sum == 1) numberOfBadMeasure++;
                }
                Console.WriteLine(numberOfBadMeasure);
                xin = Console.ReadLine();
            } 
                      
            Console.ReadLine();
        }

    }
}
