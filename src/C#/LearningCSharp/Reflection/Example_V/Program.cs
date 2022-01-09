using System;
using System.Reflection;

namespace Reflection
{
    class ExampeFive
    {
        static void Main(string[] args)
        {
            Type myClassType = typeof(Myclass);
            Myclass myClassObj = new Myclass(10, 20);
            System.Console.WriteLine("The User-Defined Type : " + myClassType.Name);
            System.Console.WriteLine("******************");

            MethodInfo[] myClassMethods = myClassType.GetMethods();
            foreach (MethodInfo theMethod in myClassMethods)
            {
                ParameterInfo[] myClassMethodParameters = theMethod.GetParameters();
                if (theMethod.Name.Equals("setMembers", StringComparison.Ordinal) && myClassMethodParameters[0].ParameterType == typeof(int))
                {
                    object[] argList = new object[2];
                    argList[0] = 9;
                    argList[1] = 18;
                    theMethod.Invoke(myClassObj, argList);
                }
                else if (theMethod.Name.Equals("setMembers", StringComparison.Ordinal) && myClassMethodParameters[0].ParameterType == typeof(double))
                {
                    object[] argList = new object[2];
                    argList[0] = 9.99;
                    argList[1] = 18.1818;
                    theMethod.Invoke(myClassObj, argList);
                }
                else if (theMethod.Name.Equals("Sum", StringComparison.Ordinal))
                {
                    System.Console.WriteLine("Sum : " + (int)(theMethod.Invoke(myClassObj, null)));
                }
                else if (theMethod.Name.Equals("isBetween", StringComparison.Ordinal) && myClassMethodParameters[0].ParameterType == typeof(int))
                {
                    object[] argList = new object[1];
                    argList[0] = 31;
                    if ((bool)theMethod.Invoke(myClassObj, argList))
                    {
                        System.Console.WriteLine("In between the boundaries.");
                    }
                    else
                    {
                        System.Console.WriteLine("Outside of the boundaries.");
                    }
                }
                else if (theMethod.Name.Equals("showMembers", StringComparison.Ordinal))
                {
                    theMethod.Invoke(myClassObj, null);                    
                }
                
            }
        }
    }

    class Myclass
    {
        public Myclass(int i, int j)
        {
            m_x = i;
            m_y = j;
        }

        public int Sum()
        {
            return m_x + m_y;
        }

        public bool isBetween(int i)
        {
            if (m_x < i && i < m_y)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        public void setMembers(int i, int j)
        {
            System.Console.Write("Inside void setMembers(int i, int j) => " + i + ", " + j + "\n");
            m_x = i;
            m_y = j;
        }

        public void setMembers(double i, double j)
        {
            System.Console.Write("Inside void setMembers(double i, double j) => " + i + ", " + j + "\n");
            m_x = (int)i;
            m_y = (int)j;
        }

        public void showMembers()
        {
            System.Console.WriteLine("Members => [ " + m_x + " , " + m_y + " ]\n");
        }

        private int m_x;
        private int m_y;
    }
}