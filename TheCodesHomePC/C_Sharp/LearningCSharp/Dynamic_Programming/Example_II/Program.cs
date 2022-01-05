using System;
using System.Dynamic;
using System.Collections;

namespace DynamicProgramming{
    class ExampleOne{
        static void Main(string[] args){
            foreach (dynamic user in getList())
            {
                System.Console.WriteLine("{0} {1}", user.Name, user.Surname); // Since we returned from the 'getList()' function as 'Name' and 'Surname', we cannot use 'm_name' and 'm_surname'.
            }
        }

        private static IEnumerable<dynamic> getList()
        {
            var users = new List<User> { 
                new User() { m_ID = 1993, m_name = "Ahmet", m_surname = "Pehlivanli"},
                new User() { m_ID = 2002, m_name = "Mike", m_surname = "Tyson"},
                                        };

            return from index in users select new { Name = index.m_name, Surname = index.m_surname }; // LINQ Expression
        }
    }

    class User{
        public int m_ID { get; set; }
        public string m_name { get; set; }
        public string m_surname { get; set; }
    }
}