using System;

namespace ConsoleApplication1
{ 
    class Program
    {
        static void Main(string[] args)
        {
		
	   int numberOfCases = int.Parse(Console.ReadLine());
            int[] nc = new int[numberOfCases];
            for (int i = 0; i < numberOfCases; i++)
            {
                //Lee la primera liena del caso
                string s = Console.ReadLine();
                string[] p = s.Split(' ');
                int n = int.Parse(p[0]);
                int m = int.Parse(p[1]);
                //Arreglo de n posiciones para llevar los votos por candidato
                int[] arr = new int[n];
                int maxIndex = 0;
                //Por c\region
                for (int c = 0; c < m; c++)
                {
                    //leo los votos
                    s = Console.ReadLine();
                    p = s.Split(' ');
                    //Por c\ voto lo anyado al arreglo
                    for (int d = 0; d < n; d++)
                    {
                        arr[d] += int.Parse(p[d]);
                        if (arr[d] > arr[maxIndex]) maxIndex = d;
                    }
                }
                //Guardo el ganador
                nc[i] = maxIndex + 1;
            }
            foreach (int item in nc)
            {
                Console.WriteLine(item);
            }	
		
		
        }
				
    }
	
}