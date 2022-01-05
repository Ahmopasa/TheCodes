using System;
using Example_I;

namespace OOP{
    class Program{
        static void Main(string[] args){
            // Calling default ctor:
            SimpleClass objectOne = new SimpleClass();
            printSimpleClass(objectOne);

            // Calling the function to create an object of type SimpleClass:
            SimpleClass objectTwo = createSimepleClass(10,25);
            printSimpleClass(objectTwo);
            // Changing the value of an object:
            changeSimpleClass(objectOne, 12, 13);
            printSimpleClass(objectOne);

            // Calling copy ctor:
            SimpleClass objecThree = objectTwo;
            printSimpleClass(objecThree);
        }  

        static SimpleClass createSimepleClass()
        {
            SimpleClass objectOne = new SimpleClass();

            return objectOne;
        }

        static SimpleClass createSimepleClass(int x = 1, int y = 1)
        {
            SimpleClass objectTwo = new SimpleClass(x,y);

            return objectTwo;
        }

        static void changeSimpleClass(SimpleClass tempObject, int x = 1, int y = 1)
        {
            tempObject.setMemberX = x;
            tempObject.setMemberY = y;
        }

        static void printSimpleClass(SimpleClass tempObject)
        {
            Console.Write("\n**********\n");
            System.Console.Write("m_x : " + tempObject.getMemberX + "\n");
            System.Console.Write("m_y : " + tempObject.getMemberY);
            Console.Write("\n**********\n");
        }
    }
}