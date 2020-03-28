using System;
using System.Collections.Generic;

using System.Text;

namespace ConsoleApplication1
{ 
    class Program
    {
        static void Main(string[] args)
        {
            Queue<int> cola = new Queue<int>();
            int k = int.Parse(Console.ReadLine());
            while (k!=42)
            {
                cola.Enqueue(k);
                k = int.Parse(Console.ReadLine());
            }
            foreach (int item in cola)
            {
                Console.WriteLine(item);
            }
            
        }
        

    }    
}