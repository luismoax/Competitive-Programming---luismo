using System;
using System.Collections.Generic;
using System.Text;

namespace CA
{
    class Program
    {

        static void Main(string[] args)
        {

            string input = Console.ReadLine();
            List<string> lst = new List<string>();

            while (input !="#")
            {
                string ax = "";
                string s = "";
                     
                for (int c = 0; c < input.Length; c++)
                {
                    #region SWITCH
                    switch (input[c])
                    {
                        case ' ':
                            s = "%20";
                            break;
                        case '!':
                            s = "%21";
                            break;
                        case '$':
                            s = "%24";
                            break;
                        case '%':
                            s = "%25";
                            break;
                        case '(':
                            s = "%28";
                            break;
                        case ')':
                            s = "%29";
                            break;
                        case '*':
                            s = "%2a";
                            break;
                        default:
                            s = input[c].ToString();
                            break;
                    }
                    #endregion
                    ax += s;                    
                }
                lst.Add(ax);
                ax = "";
                input = Console.ReadLine();
            }

            foreach (string var in lst)
            {
                Console.WriteLine(var);
            }
            Console.ReadLine();
            
        }

    }
}