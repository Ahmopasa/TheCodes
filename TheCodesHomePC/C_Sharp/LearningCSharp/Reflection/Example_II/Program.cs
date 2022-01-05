using System;
using System.Reflection;

namespace Reflection{
    class ExampleTwo{
        static void Main(string[] args){

            // Student myStudentOne = new Student(m_name = "Ahmet", m_surname = "Pehlivanli"); // Syntax - Error
            // Student myStudentOne = new Student("Ahmet", "Pehlivanli"); // Syntax - Error
            // Student myStudentOne = new Student{"Ahmet", "Pehlivanli"}; // Syntax - Error
            Student myStudentOne = new Student{m_name = "Ahmet", m_surname = "Pehlivanli"}; // OK

            Type studentObjType = typeof(Student); // It saves the information of 'the type'.

            FieldInfo[] myStudentsFields = studentObjType.GetFields(BindingFlags.Public | BindingFlags.Instance); // It saves the information of members, that are 'public' and 'non-static'.
            
            System.Console.WriteLine("******************************************");
            foreach (FieldInfo index in myStudentsFields)
            {
                System.Console.WriteLine(index.Name + " = " + index.GetValue(myStudentOne));
            }
            System.Console.WriteLine("******************************************");
            /*  # THE OUTPUT #
                m_name = Ahmet
                m_surname = Pehlivanli
            */
        }
    }

    class Student{
        public string m_name;
        public string m_surname;
        private string m_mailAddress;
    }
}