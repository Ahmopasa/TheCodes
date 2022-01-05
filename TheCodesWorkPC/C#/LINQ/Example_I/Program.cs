using System;

namespace LINQ{
    class ExampleOne{
        static void Main(string[] args){
            List<Student> myStudentList = new List<Student>()
            {
                new Student{ m_ID = 18, m_name = "Ahmet", m_surname = "Pehlivanli" },
                new Student{ m_ID = 19, m_name = "Merve", m_surname = "Pehlivanli"},
                new Student{ m_ID = 30, m_name = "Ulya", m_surname = "Yuruk"}
            };

            // Names, that start with 'M':
                // Using Lambda Expression #1
                var theStudents = myStudentList.Where( index => index.m_name[0] == 'M' );
                foreach (var i in theStudents)
                {
                    System.Console.WriteLine("Using Lambda Expression #1 : " + i.m_name + " " + i.m_surname); // Merve Pehlivanli
                }

                // Using Lambda Expression #2
                var theStudentsTwo = myStudentList.Where( indexTwo => indexTwo.m_name.StartsWith("M") );
                foreach (var i in theStudentsTwo)
                {
                    System.Console.WriteLine("Using Lambda Expression #2 : " + i.m_name + " " + i.m_surname); // Merve Pehlivanli
                }

                // Using Lambda Expression #3
                var theStudentsThree = myStudentList.Where( indexThree => indexThree.m_name.Substring(0,1).ToUpper() == "M" );
                foreach (var i in theStudentsThree)
                {
                    System.Console.WriteLine("Using Lambda Expression #3 : " + i.m_name + " " + i.m_surname); // Merve Pehlivanli
                }

                // LINQ - Style
                var theStudentsFour = from indexFour in myStudentList
                                      where indexFour.m_name.Substring(0,1).ToUpper() == "M"
                                      select indexFour;
                foreach (var i in theStudentsFour)
                {
                    System.Console.WriteLine("Using LINQ - Style #1      : " + i.m_name + " " + i.m_surname); // Merve Pehlivanli
                }
            
            // Surnames, that ends with 'L'
                // Using Lambda Expression #1
                var theStudentsFive = myStudentList.Where( indexFive => indexFive.m_surname.EndsWith("i") );
                foreach (var i in theStudentsFive)
                {
                    System.Console.WriteLine("Using Lambda Expression #1 : " + i.m_name + " " + i.m_surname); // Merve Pehlivanli & Ahmet Pehlivanli
                }

                // LINQ - Style
                var theStudentsSix = from indexSix in myStudentList
                                     where indexSix.m_surname.EndsWith("i")
                                     select indexSix;
                foreach (var i in theStudentsSix)
                {
                    System.Console.WriteLine("Using LINQ - Style #1      : " + i.m_name + " " + i.m_surname); // Merve Pehlivanli & Ahmet Pehlivanli
                }

            // Students, whose age are inbetween 18-25
                // Using Lambda Expression #1
                var theStudentsSeven = myStudentList.Where( indexSeven => indexSeven.m_ID >= 18 && indexSeven.m_ID <= 25);
                foreach (var i in theStudentsSeven)
                {
                    System.Console.WriteLine("Using Lambda Expression #1 : " + i.m_name + " " + i.m_surname); // Merve Pehlivanli & Ahmet Pehlivanli
                }

                // Using LINQ style
                var theStudentsEight = from indexEight in myStudentList
                                       where indexEight.m_ID >= 18 && indexEight.m_ID <= 25
                                       select indexEight;
                foreach (var i in theStudentsEight)
                {
                    System.Console.WriteLine("Using LINQ - Style #1      : " + i.m_name + " " + i.m_surname); // Merve Pehlivanli & Ahmet Pehlivanli
                }

                // Using Anonymous Types
                var theStudentsNine = myStudentList.Select( indexNine => new {
                                                                                m_tempID = indexNine.m_ID,
                                                                                m_nameSurname = indexNine.m_name + " " + indexNine.m_surname
                                                                            }
                                                        );
                foreach (var i in theStudentsNine)
                {
                    System.Console.WriteLine("Using Anonymous Types      : " + i.m_tempID + " " + i.m_nameSurname); // 18 Ahmet Pehlivanli & 19 Merve Pehlivanli & 30 Ulya Yuruk
                }
        }
    }

    class Student{
        public int m_ID{get;set;}
        public string m_name{get;set;}
        public string m_surname{get;set;}
    }
}