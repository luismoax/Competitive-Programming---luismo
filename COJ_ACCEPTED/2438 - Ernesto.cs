using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CP
{
    class Program
    {
		// Author: Luismo
		// Problem: 2438 - Ernesto
		// Idea: Find the greatest element in each coneccted componet
        static void Main(string[] args)
        {
            TextReader tr = Console.In;            
            //Console.SetIn(new StreamReader(@"d:\lmo.in"));
            SolveSingleProblem();

            Console.SetIn(tr);
            Console.ReadLine();
        }



        static Student best = new Student("", 0);
        static List<List<Pair>> ady; // for adyacency
        static bool[] taken;


        static List<Student> students; // for students 

        static List<Student> chosenOnes;
        static void SolveSingleProblem()
        {
            string[] data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            while (data[0]+data[1]!="00")
            {
                int n = int.Parse(data[0]);
                int m = int.Parse(data[1]);

                // maps
                Dictionary<Student, int> map = new Dictionary<Student, int>();
                Dictionary<string, int> mapTwo = new Dictionary<string, int>();

                students = new List<Student>();

                for (int i = 0; i < n; i++)
                {
                    data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                    Student student = new Student(data[0], int.Parse(data[1]));

                    students.Add(student);

                    map.Add(student, i); // mapping with index
                    
                    mapTwo.Add(data[0],i);
                }

                // adyacency
                ady = new List<List<Pair>>();
                for (int i = 0; i < n; i++)
                    ady.Add(new List<Pair>());

                // reading edges
                for (int i = 0; i < m; i++)
                {
                    data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                    int x = mapTwo[data[0]];
                    int y = mapTwo[data[1]];

                    // adding adyacency
                    ady[x].Add(new Pair(x, y));
                    ady[y].Add(new Pair(y, x));

                }

                // DFS searching for the Best;
                chosenOnes = new List<Student>(); 
                taken = new bool[n];

                for (int i = 0; i < n; i++)
                {
                    // if not taken
                    if (!taken[i])
                    {
                        DFS(i);
                        // asing the bes Student
                        chosenOnes.Add(best);
                    }
                    
                    
                    best = new Student("", 0);
                }


                foreach (var item in chosenOnes.OrderBy(std=> std.name))
                {
                    Console.WriteLine(item.name);
                }

                // read again
                data = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            }
        }


        static void DFS(int idx)
        {
            // if this student is better
            if (students[idx].tolerance > best.tolerance)
                best = students[idx];

            // mark as visited
            taken[idx] = true;

            for (int i = 0; i < ady[idx].Count; i++)
            {
                Pair p = ady[idx][i];
                if (!taken[p.y])
                    DFS(p.y);
            }
        }

        static void PrintMT(int [,] mt)
        {
            for (int i = 0; i < mt.GetLength(0); i++)
            {
                for (int j = 0; j < mt.GetLength(1); j++)                
                    Console.Write(mt[i,j]+" ");
                Console.WriteLine();
            }
            Console.WriteLine();
        }


    }

    class Student
    {
        public string name;
        public int tolerance;
        public Student(string name, int tolerance)
        {
            this.name = name;
            this.tolerance = tolerance;
        }

        public override string ToString()
        {
            return string.Format("{0} {1}",name,tolerance);
        }
    }

    class Pair
    {
        public int x, y;
        public Pair(int x, int y)
        {
            this.x = x;
            this.y = y;
        }

        public override string ToString()
        {
            return string.Format("{0},{1}",x,y);
        }
    }
}
