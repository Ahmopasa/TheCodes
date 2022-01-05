using System;

namespace UdemyCourse{
    class ExampleTwo{
        static void Main(string[] args){
            Console.WriteLine("Hello!\nIn this program, I'll be using arrays, if-else and switch cases to learn.\n");
            Console.Write("Please, enter your name : ");
            string m_name = string.Empty;
            m_name = Console.ReadLine();
            string[] m_nameArrays = new string[3];

            Console.Write("Please, enter your age  : ");
            int m_age = Convert.ToInt16(Console.ReadLine());
            int[] m_ageArrays = new int[3];
        
            Console.Write("Please, enter your score: ");
            int m_score = Convert.ToInt16(Console.ReadLine());
            int[] m_scoreArrays = new int[3];

            for (int i = 0; i < 3; i++)
            {
                m_nameArrays[i] = m_name;
                m_ageArrays[i] = m_age;
                m_scoreArrays[i] = m_score;
            }

            for (int i = 0; i < 3; i++)
            {
                Console.Write("{0}", i);
                Console.Write(". student has following attributes\n");
                for (int j = 0; j < 3; j++)
                {
                    Console.Write(m_nameArrays[j] + ", " + m_ageArrays[j] + ", " + m_scoreArrays[j] + "\n");
                }
            }
        }
    }
}