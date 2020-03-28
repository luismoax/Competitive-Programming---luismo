using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            //1600 Big Powers
            string xin = Console.ReadLine();
            while (xin != "0 0")
            {
                string[] p = xin.Split(' ');
                int n = int.Parse(p[0][p[0].Length - 1].ToString());
                string lstDig = p[1][p[1].Length - 1].ToString();
                if (p[1].Length > 1) lstDig = p[1][p[1].Length - 2] + lstDig;
                int exponentLastDigit = int.Parse(lstDig);

                if (p[1] == "0") Console.WriteLine(1);
                else
                {
                    Console.WriteLine(LastDigit(n, exponentLastDigit));
                }
                xin = Console.ReadLine();
            }
            Console.ReadLine();
        }

        static int LastDigit(int n, int exponentLastDigit)
        {
            if (n == 0 || n == 1 || n == 5 || n == 6) return n;

            int cong4 = exponentLastDigit % 4;
            int cong2 = exponentLastDigit % 2;

            if (n == 2)
            {
                #region Switch congruente 4 para ->2
                switch (cong4)
                {
                    case 1:
                        return 2;
                    case 2:
                        return 4;
                    case 3:
                        return 8;
                    case 0:
                        return 6;
                    default:
                        break;
                }
                #endregion
            }

            if (n == 3)
            {
                #region Switch congruente 4 para ->3
                switch (cong4)
                {
                    case 1:
                        return 3;
                    case 2:
                        return 9;
                    case 3:
                        return 7;
                    case 0:
                        return 1;
                    default:
                        break;
                }
                #endregion
            }

            if (n == 7)
            {
                #region Switch congruente 4 para ->7
                switch (cong4)
                {
                    case 1:
                        return 7;
                    case 2:
                        return 9;
                    case 3:
                        return 3;
                    case 0:
                        return 1;
                    default:
                        break;
                }
                #endregion
            }

            if (n == 8)
            {
                #region Switch congruente 4 para ->8
                switch (cong4)
                {
                    case 1:
                        return 8;
                    case 2:
                        return 4;
                    case 3:
                        return 2;
                    case 0:
                        return 6;
                    default:
                        break;
                }
                #endregion
            }

            if (n == 4)
            {
                #region Switch congruente 4 para ->4
                switch (cong2)
                {
                    case 1:
                        return 4;
                    case 0:
                        return 6;
                    default:
                        break;
                }
                #endregion
            }

            if (n == 9)
            {
                #region Switch congruente 4 para ->9
                switch (cong2)
                {
                    case 1:
                        return 9;
                    case 0:
                        return 1;
                    default:
                        break;
                }
                #endregion
            }

            return 0;
        }
    }
}
