using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Globalization;

namespace COJ
{
    class Program
    {  
        /*
         * Author: LUISMO
         *
         * 
         * */
        static void Main(string[] args)
       {            
            string[] data = Console.ReadLine().Split(new char[]{' '},StringSplitOptions.RemoveEmptyEntries);
            int day = int.Parse(data[0]);
            int hour = int.Parse(data[1]);
            int minute = int.Parse(data[2]);
			
            int k = (int)new DateTime(2011, 11, day, hour, minute, 0).Subtract(new DateTime(2011, 11, 11, 11, 11, 0)).TotalMinutes;

            if (k < 0)
                k = -1;

            Console.WriteLine(k);            
            
            Console.ReadLine();
        } 

    }

}
