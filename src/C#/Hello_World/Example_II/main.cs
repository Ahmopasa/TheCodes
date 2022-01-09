using System;

namespace HelloWorld
{
  class ExampleTwo 
  {
    static bool checkAccountValidation(int pinCode, in string name)
    {
      if (1234 == pinCode && "Ahmet" == name)
        return true;

      else
        return false;
    }

    static void Main() 
    {
      Console.Write("Hello!\nWelcome to the Example_II\nPlease, enter your name to proceed;\nName: ");
      string? myName = Console.ReadLine();
      
      if (myName != null)
      {
        Console.Write("Please, enter your PIN code to proceed;\nPIN Code: ");
        int pinCode;
        pinCode = Convert.ToInt32(Console.ReadLine());
        if (checkAccountValidation(pinCode, in myName))
        {
          Console.Write("You're in!!!.\n\n\n");
        }
        else
        {
          Console.WriteLine("The account could not be founded!!!\nEntered Information:");
          Console.Write("Name     : {0}\n", myName);
          Console.Write("PIN CODE : {0}\n", pinCode);
        }

        Console.Write("\nProgram is exiting!!!...\n");
      }
      else
      {
        System.Console.WriteLine("THE NAME IS NULL\n");
      }
    }
  }
}