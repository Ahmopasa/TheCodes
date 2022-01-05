using System;
using System.Reflection;

namespace Reflection{
    class ExampleThree{
        static void Main(string[] args){
            User myUserOne = new User(){ m_ID = 1993, m_userName = "Ahmopasa", m_mailAddress = "ahmopasa@gmail.com" };

            var properties = myUserOne.GetType().GetProperties();
            foreach (var index in properties)
            {
                System.Console.WriteLine(index.Name + " = " + index.GetValue(myUserOne));
                /*  # OUTPUT #
                    m_ID = 1993
                    m_userName = Ahmopasa
                    m_mailAddress = ahmopasa@gmail.com
                */
            }
        }

        class User{
            
            public int m_ID{get;set;}
            public string m_userName{get;set;}
            public string m_mailAddress{get;set;}
        }
    }
}