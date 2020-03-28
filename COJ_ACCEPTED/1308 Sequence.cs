using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        //1308 Sequence (solucion dinamica)
        static void Main(string[] args)
        {               
            //Solucion dinamica
            //Genero las 15 soluciones y las guardo en una lista y luego las devuelvo
            //Arreglos para llevar memoiation
            Fraction[] xn = new Fraction[15];
            Fraction[] yn = new Fraction[15];
            //Pongo los valores bases (X1,Y1) = (0,0) 
            xn[0] = new Fraction(0, 1);
            yn[0] = new Fraction(0, 1);
            List<string> soluciones = new List<string>();
            for (int i = 1; i < 15; i++)
            {
                //Siempre me voy apoyando en los valores previamente claculados

                //Haciendo las operaciones de Xn
                Fraction f1 = new Fraction(1, 1);
                f1 = f1.Restate(new Fraction(2,(i+1))).Multiply(xn[i-1]);

                Fraction f2 = new Fraction(1, i + 1);
                f2 = f2.Multiply(yn[i - 1]);

                xn[i] = f1.Restate(f2).Add(new Fraction(4,i+1));

                //Para el Yn
                f1 = new Fraction(1, 1);
                f1 = f1.Restate(new Fraction(1, (i + 1))).Multiply(yn[i - 1]);

                f2 = new Fraction(1, i + 1);
                f2 = f2.Multiply(xn[i - 1]);

                yn[i] = f1.Restate(f2).Add(new Fraction(3, i + 1));
                
                //Guardo la solucion para n-1                
                soluciones.Add( String.Format("(x{0},y{0}) = ({1},{2})",i,xn[i-1],yn[i-1]));
            }
            //Guardo la ultima solucion
            soluciones.Add(String.Format("(x15,y15) = ({0},{1})",xn[14], yn[14]));

            string xin = Console.ReadLine();
            while (xin !="0")
            {
                Console.WriteLine(soluciones[int.Parse(xin) - 1]);
                xin = Console.ReadLine();
            }

            Console.ReadLine();
        }
        //Clase Fraction para facilitar el trabajo con las fracciones
        class Fraction
        {
            long numerator;
            long denominator;

            #region Constructores
            public Fraction(long numerator, long denominator)
            {
                if (denominator == 0) throw new Exception("No se puede dividir por cero");
                this.numerator = numerator;
                this.denominator = denominator;
                //La simplifico
                Simplify();
            }
            #endregion

            #region Propiedades
            public long Numerator
            {
                get { return this.numerator; }
            }

            public long Denominator
            {
                get { return this.denominator; }
            }
            #endregion

            #region Metodos Publicos
            public Fraction Multiply(Fraction fraction)
            {
                return new Fraction(this.numerator * fraction.numerator, this.denominator * fraction.denominator);
            }

            public Fraction Add(Fraction fraction)
            {
                long mcm = (this.denominator * fraction.denominator) / MCD(this.denominator, fraction.denominator);
                return new Fraction((this.numerator * mcm / this.denominator) + (fraction.numerator * mcm / fraction.denominator), mcm);
            }

            public Fraction Divide(Fraction fraction)
            {
                return new Fraction(this.numerator * fraction.denominator, this.denominator * fraction.numerator);
            }

            public Fraction Restate(Fraction fraction)
            {
                long mcm = (this.denominator * fraction.denominator) / MCD(this.denominator, fraction.denominator);
                return new Fraction((this.numerator * mcm / this.denominator) - (fraction.numerator * mcm / fraction.denominator), mcm);
            }
            #endregion

            #region Metodos Privados
            void Simplify()
            {
                long mcd = MCD(this.numerator, this.denominator);
                this.numerator = this.numerator / mcd;
                this.denominator = this.denominator / mcd;
            }

            public long MCD(long a, long b)
            {
                if (a == b) return a;
                if (a % b == 0) return b;
                if (b % a == 0) return a;

                return MCD(b, a % b);
            }
            #endregion

            public override string ToString()
            {
                if (this.denominator == 1) return this.numerator.ToString();
                return String.Format("{0}/{1}", numerator, denominator);
            }

        }



    }

}

