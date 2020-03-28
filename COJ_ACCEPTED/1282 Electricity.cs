using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
		//1282 Electricity
        static void Main(string[] args)
        {
            //StreamReader sr = new StreamReader(@"d:\PrOGrAmaCi”n\Taller\COJ\COJ\COJ\bin\Debug\in.lmo");

            string xin = Console.ReadLine();
            while (xin != "0")
            {
                int measures = int.Parse(xin);
                int numberOfDays = 0;
                //Leo la primera fecha
                string[] split = Console.ReadLine().Split(' ');
                DateTime dt1 = new DateTime(int.Parse(split[2]), int.Parse(split[1]), int.Parse(split[0]));
                int lastMeasure = int.Parse(split[3]);                
                int amount = 0;
                
                for (int c = 0; c < measures-1; c++)
                {
                    split = Console.ReadLine().Split(' ');
                    DateTime dt2 = new DateTime(int.Parse(split[2]), int.Parse(split[1]), int.Parse(split[0]));
                    //Si este dia es consecutivo al dia dt1
                    if (dt2 == dt1.AddDays(1))
                    {
                        //Aumento el numero de dias con mediadas posibles
                        numberOfDays++;
                        //Anyado las diferencias de las medidas
                        amount +=int.Parse(split[3]) - lastMeasure;                        
                    }
                    //Actualizo dt1
                    dt1 = dt2;
                    lastMeasure = int.Parse(split[3]);                    
                }
                Console.WriteLine("{0} {1}",numberOfDays,amount);

                xin = Console.ReadLine();
            }

            Console.ReadLine();
        }

    }
}

