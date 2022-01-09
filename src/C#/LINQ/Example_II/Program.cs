using System;

namespace LINQ{
    class ExampleOne{
        static void Main(string[] args)
        {
            List<Student> studentList = new List<Student>()
            {
                new Student{m_ID = 1, m_name = "Ahmet", m_surname = "Pehlivanli", m_birthDate = new DateTime(1993, 7, 14) },
                new Student{m_ID = 2, m_name = "Merve", m_surname = "Pehlivanli", m_birthDate = new DateTime(1995, 8, 15) },
                new Student{m_ID = 3, m_name = "Ulya", m_surname = "Yuruk", m_birthDate = new DateTime(1995, 9, 16) },
                new Student{m_ID = 4, m_name = "Cihan", m_surname = "Ozhan", m_birthDate = new DateTime(1988, 10, 17) }
            };

            // Those, that has ID larger than 2: 
                // C# - Style:
                List<Student> tempStudentList = new List<Student>();
                foreach (var index in studentList)
                {
                    if (index.m_ID > 2)
                    {
                        tempStudentList.Add(index);
                    }
                }
                System.Console.WriteLine("C# - Stlye;");
                foreach (var index in tempStudentList)
                {
                    System.Console.WriteLine(index.m_name);
                }

                // LINQ - Style:
                var tempStudentLINQList = from index in studentList
                            where index.m_ID > 1
                            select index;
                System.Console.WriteLine("LINQ - Stlye;");
                foreach (var index in tempStudentLINQList)
                {
                    System.Console.WriteLine(index.m_name);
                }

                // Lambda Expression:
                var tempStudentLambdaList = studentList.Where( index => index.m_ID > 0);
                System.Console.WriteLine("Lambda Expression;");
                foreach (var index in tempStudentLambdaList)
                {
                    System.Console.WriteLine(index.m_name);
                }
        }
    }

    class Student{
        public int m_ID{get;set;}
        public string m_name{get;set;}
        public string m_surname{get;set;}
        public DateTime m_birthDate{get;set;}
    }
}