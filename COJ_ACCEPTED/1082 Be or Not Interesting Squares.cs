using System;

namespace COJ
{
    class Program
    {        
        static void Main(string[] args)
        {
            //1082 Be or Not Interesting Squares
			string xinput = Console.ReadLine();
            while (xinput!=null && xinput!="")
            {
                int n = int.Parse(xinput);

                switch (n)
                {
                    case 2:
                        Console.WriteLine(1);
                        break;
                    case 3:
                        Console.WriteLine(2);
                        break;
                    case 4:
                        Console.WriteLine(24);
                        break;
                    case 5:
                        Console.WriteLine(1344);
                        break;
                    case 6:
                        Console.WriteLine(1128960);
                        break;
                    default:
                        break;
                }
                xinput = Console.ReadLine();
            }            
            Console.ReadLine();
        }
    }

}
