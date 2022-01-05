using System;
using System.Reflection;

namespace Reflection
{
    class ExampleFour
    {
        static void Main(string[] args)
        {
            Type myType = typeof(Myclass);
            System.Console.WriteLine("Methods to investigate : " + myType.Name);
            System.Console.WriteLine();

            System.Console.WriteLine("# Recommended Methods #");
            MethodInfo[] myMethods = myType.GetMethods(); // Saves all functions into the array.
            foreach (MethodInfo index in myMethods)
            {
                System.Console.Write(index.ReturnType.Name + " " + index.Name + "(");

                ParameterInfo[] myParams = index.GetParameters(); // // Saves all function parameters into the array.
                for (int i = 0; i < myParams.Length; i++)
                {
                    System.Console.Write(myParams[i].ParameterType.Name + " " + myParams[i].Name);
                    if (i + 1 < myParams.Length)
                    {
                        System.Console.Write(", ");
                    }
                }

                System.Console.WriteLine(")");
                System.Console.WriteLine();
            }

            /*  # OUTPUT
                Methods to investigate : Myclass

                # Recommended Methods #
                Int32 Sum()

                Boolean inBetween(Int32 x)

                Void setMembers(Double x, Double y)

                Void showMembers()

                Type GetType()

                String ToString()

                Boolean Equals(Object obj)

                Int32 GetHashCode()
            */
        }
    }

    class Myclass
    {
        
        public Myclass(int x = 1, int y = 1)
        {
            m_x = x;
            m_y = y;
        }

        public int Sum()
        {
            return m_x + m_y;
        }

        public bool inBetween(int x)
        {
            return (m_x < x && x < m_y) ? true : false;
        }

        public void setMembers(double x, double y)
        {
            m_x = (int)x;
            m_y = (int)y;
        }

        public void showMembers()
        {
            System.Console.WriteLine(" [ " + m_x + " , " + m_y + " ]\n");
        }
        private int m_x;
        private int m_y;
    }
}