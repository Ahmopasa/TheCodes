using System;
using System.Dynamic;

namespace DynamicProgramming{
    class ExampleOne{
        static void Main(string[] args){
            dynamic m_variable = 5;
            System.Console.WriteLine(m_variable); // It'll print '5' on the console.

            m_variable = "AA";
            System.Console.WriteLine(m_variable); // It'll print 'AA' on the console.

            // Creating a class-like object during the run-time:
            dynamic human = new ExpandoObject(); // A dynamic object'll be created during the run-time.
            human.m_name = "Ahmet"; // During the run-time, our 'human' object'll have a member, called 'm_name'.
            human.m_surname = "Pehlivanli"; // During the run-time, our 'human' object'll have a member, called 'm_surname'.
            System.Console.WriteLine(human.m_name + " " + human.m_surname); // It'll print 'Ahmet Pehlivanli' on the console.
            
            human.print = new Action( // 'Action' is kind of 'delegate' where you cannot return anything.
                                        () => // Start position of the Lambda Expression
                                        {
                                            System.Console.WriteLine("Details [ " + human.m_name + " ] [ " + human.m_surname + " ].");
                                        } // End position of the Lambda Expression
                                    ); 
            human.print(); // It'll print 'Details [ Ahmet ] [ Pehlivanli ].' on the console.
           
            human.callFunction = new Func<string, string>( // 'Func' is kind of 'delegate' where you can return anything. Left parameter of 'Func' is used for parameters while right parameter is used to return parameters.
                                                            passedVariable => 
                                                            {
                                                                return "Passed Parameter [ " + passedVariable + " ]."; 
                                                            }
                                                        );
            dynamic returnedVariable = human.callFunction("Learning C-Sharp");
            System.Console.WriteLine(returnedVariable); // It'll print 'Passed Parameter [ Learning C-Sharp ].' on the console.
            

        }
    }
}