using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;
using System.IO;
using System.Linq;


namespace ConsoleApplication1
{
    class Program
    {
        
        static void Main(string[] args)
        {
            TextReader tr = Console.In;
            //Console.SetIn(new StreamReader(@"d:\in.lmo"));
            
            //string[] data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            int gx = int.Parse(Console.ReadLine());
            if (gx == 0)
                Console.WriteLine("0");
            else
            {
                Calculate(ToBinary(gx));
            }
            
            Console.SetIn(tr);
            Console.ReadLine();
        }

        private static void Calculate(string s)
        {
            string x1 = "", x2 = "";
            if (s[s.Length - 1] == '1')
            {
                // FirstStep
                x1 = "1";
                x2 = "0";

                for (int i = s.Length - 2; i >= 0; i--)
                {
                    x1 = x2[0] + x1;
                    if (s[i] == '0')
                        x2 = x1[0] + x2;
                    else
                    {
                        char append = '0';
                        if (x1[0] == '0')
                            append = '1';

                        x2 = append + x2;
                    }
                }
                // If firstCreation is Good
                if (x1[0] == '1')
                {
                    Console.WriteLine(ToDecimal(x1));
                    return;
                }

                // secon Step
                x1 = "0";
                x2 = "1";

                for (int i = s.Length - 2; i >= 0; i--)
                {
                    x1 = x2[0] + x1;
                    if (s[i] == '0')
                        x2 = x1[0] + x2;
                    else
                    {
                        char append = '0';
                        if (x1[0] == '0')
                            append = '1';

                        x2 = append + x2;
                    }
                }

                if (x1[0] == '1')
                {
                    Console.WriteLine(ToDecimal(x1));
                    return;
                }


            }
            else
            {
                x1 = "0";
                x2 = "0";

                for (int i = s.Length - 2; i >= 0; i--)
                {
                    x1 = x2[0] + x1;
                    if (s[i] == '0')
                        x2 = x1[0] + x2;
                    else
                    {
                        char append = '0';
                        if (x1[0] == '0')
                            append = '1';

                        x2 = append + x2;
                    }
                }

                if (x1[0] == '1')
                {
                    Console.WriteLine(ToDecimal(x1));
                    return;
                }

                // Second Step

                x1 = "1";
                x2 = "1";

                for (int i = s.Length - 2; i >= 0; i--)
                {
                    x1 = x2[0] + x1;
                    if (s[i] == '0')
                        x2 = x1[0] + x2;
                    else
                    {
                        char append = '0';
                        if (x1[0] == '0')
                            append = '1';
                        x2 = append + x2;
                    }
                }

                if (x1[0] == '1')
                {
                    Console.WriteLine(ToDecimal(x1));
                    return;
                }
            }
        }

        static string ToBinary(int n)
        {
            string adev = "";
            if (n == 1)
                return "1";
            while (n > 0)
            {
                adev = n % 2 + adev;
                n /= 2;
            }
            return adev;
        }

        static int ToDecimal(string binary)
        {
            double d = 0;
            for (int i = 0; i < binary.Length; i++)
            {
                if (binary[binary.Length - 1 - i] == '1')
                {
                    d += Math.Pow(2, i);
                }
            }
            return (int)d;
        }
    }

}
