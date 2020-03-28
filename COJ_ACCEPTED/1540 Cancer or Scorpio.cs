using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication26
{
    class Program
    {
        static void Main(string[] args)
        {
            int tc = int.Parse(Console.ReadLine());
            for (int t = 0; t < tc; t++)
            {
                string date = Console.ReadLine();
                int month = int.Parse(date.Substring(0, 2));
                int day = int.Parse(date.Substring(2, 2));
                int year = int.Parse(date.Substring(4, 4));
                DateTime dt = new DateTime(year, month, day);
                dt=dt.AddDays(280);
                string sign = "";
                

                if (dt.Month == 1)
                {
                    if (dt.Day >= 21)
                        sign = "aquarius";
                    else sign = "capricorn";
                }

                else if (dt.Month == 2)
                {
                    if (dt.Day >= 20)
                        sign = "pisces";
                    else sign = "aquarius";
                }

                else if (dt.Month == 3)
                {
                    if (dt.Day >=21)
                        sign = "aries";
                    else sign = "pisces";
                }
                    //Abril
                else if (dt.Month == 4)
                {
                    if (dt.Day >= 21)
                        sign = "taurus";
                    else sign = "aries";
                }
                //Mayo
                else if (dt.Month == 5)
                {
                    if (dt.Day >= 22)
                        sign = "gemini";
                    else sign = "taurus";
                }
                //Junio
                else if (dt.Month == 6)
                {
                    if (dt.Day >= 22)
                        sign = "cancer";
                    else sign = "gemini";
                }
                //Julio
                else if (dt.Month == 7)
                {
                    if (dt.Day >= 23)
                        sign = "leo";
                    else sign = "cancer";
                }
                //Agosto
                else if (dt.Month == 8)
                {
                    if (dt.Day >= 22)
                        sign = "virgo";
                    else sign = "leo";
                }
                //Septiempre
                else if (dt.Month == 9)
                {
                    if (dt.Day >= 24)
                        sign = "libra";
                    else sign = "virgo";
                }
                //octubre
                else if (dt.Month == 10)
                {
                    if (dt.Day >= 24)
                        sign = "scorpio";
                    else sign = "libra";
                }
                //
                //nov
                else if (dt.Month == 11)
                {
                    if (dt.Day >= 23)
                        sign = "sagittarius";
                    else sign = "scorpio";
                }
                //dic
                else if (dt.Month == 12)
                {
                    if (dt.Day >= 23)
                        sign = "capricorn";
                    else sign = "sagittarius";
                }
                string d = dt.Day.ToString();
                string m = dt.Month.ToString();
                string y = dt.Year.ToString();

                if (d.Length == 1)
                    d = "0" + d;
                if (m.Length == 1)
                    m = "0" + m;



                Console.WriteLine("{0} {1}/{2}/{3} {4}",t+1,m,d,dt.Year,sign);
            }

            Console.ReadLine();
        }
    }
}
