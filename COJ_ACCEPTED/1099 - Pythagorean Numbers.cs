using System;
using System.Collections.Generic;

namespace ConsoleApplication1
{ 
    class Program
    {
        static void Main(string[] args)
        {
                       string ns = Console.ReadLine();
            //Cola para almacernar las respuestas
            Queue<string> q = new Queue<string>();
            //Mientras haya una entrada por leer
            while (ns != "0")
            {
                string[] p = ns.Split(' ');
                //Arreglo que contendra los valores de la entrada
                int[] a3 = new int[3];
                //Voy llevando el indice del maximo
                int ind = 0;
                for (int i = 0; i < 3; i++)
                {
                    a3[i] = int.Parse(p[i]);
                    //Actualizo el valor del mayor en el array
                    if (a3[i] > a3[ind]) ind = i;
                }
                //Inercambio el valor maximo con el de la ultima posicion
                int x = a3[2];
                a3[2] = a3[ind];
                a3[ind] = x;

                //Segun se cumpla la relacion, se encola el resultado
                if ((a3[0] * a3[0] + a3[1] * a3[1]) == a3[2] * a3[2]) q.Enqueue("right");
                else q.Enqueue("wrong");
                //Lee la entrada
                ns = Console.ReadLine();
            }
            //Mientras haya "respuestas" en la cola"
            while (q.Count > 0)
            {
                //Imprime la respuesta
                Console.WriteLine(q.Dequeue());
            }            
       
		
        }
				
    }
	
}