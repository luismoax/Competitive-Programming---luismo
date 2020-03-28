using System;

namespace ConsoleApplication1
{ 
    class Program
    {
        static void Main(string[] args)
        {
        
            int a = int.Parse(Console.ReadLine());
            int cnt = a - 1;
            bool[] b = new bool[a - 1];
            for (int i = 2; i < a / 2; i++)
            {
                //Encontre un divisor, cojeres sus multiplos
                if (!b[i - 1] && a % i == 0)
                {
                    int k = i;
                    while (k <= a - 1)
                    {
                        if (!b[k - 1])
                        {
                            b[k - 1] = true;
                            cnt--;
                        }
                        k += i;
                    }
                }
            }
            Console.WriteLine(cnt);

		
		
		
		
        }
				
    }
	
}