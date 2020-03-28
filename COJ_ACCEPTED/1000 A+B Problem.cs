using System;


namespace ConsoleApplication1
{ 
    class Program
    {
        static void Main(string[] args)
        {
            string s = Console.ReadLine();
            string[] arr = s.Split(' ');

            int a = int.Parse(arr[0]);
            int b = int.Parse(arr[1]);
            
            
            Console.WriteLine(a+b);

        }
     }

    
}
