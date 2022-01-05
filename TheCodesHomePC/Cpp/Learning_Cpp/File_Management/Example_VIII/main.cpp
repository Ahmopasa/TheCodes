// Opening File to Read from File Formatted.
#include <iostream>
#include <fstream>

int main()
{
        // std::fstream fileHandlerMain{}; // Used to open a file to read and write.
    /*  // Formatted Reading from File w/o looping.
        // * Input : 
        // Test This is
        // A simple example
        // * Output: 
        // Test
        // This
        // is
        // A
    
        std::ifstream fileHandler{};
        std::string word{}, word_2{}, word_3{}, word_4{};

        fileHandler.open("test.txt");
        if (!fileHandler)
        {
            std::cerr << "Problem Opening File" << std::endl; return -1;
        }
        std::cout << "Reading File is Possible" << std::endl;

        fileHandler >> word >> word_2 >> word_3 >> word_4; // Test this is A

        fileHandler.close();

        std::cout << word << std::endl << word_2 << std::endl << word_3 << std::endl << word_4 << std::endl;
    */

    /*  // Formatted Reading from File With looping.
        // * Input : 
        // Test This is 100.4569 987456,456
        // A simple example 798789,4981 asdasdasduıjaksldjansd opweıqjwelkas d
        // * Output: 
        // 1th word => Test
        // 2th word => This
        // 3th word => is
        // 4th word => 100.4569
        // 5th word => 987456,456
        // 6th word => A
        // 7th word => simple
        // 8th word => example
        // 9th word => 798789,4981
        // 10th word => asdasdasduıjaksldjansd
        // 11th word => opweıqjwelkas
        // 12th word => d

        std::ifstream fileHandler{"test.txt"};
        std::string word{};

        if (!fileHandler)
        {
            std::cerr << "Problem Opening File" << std::endl; 
            return -1;   
        }

            std::cout << "Reading File is Possible" << std::endl;

            int i = 1;
            while (!fileHandler.eof()) //fileHandler >> word { using >> makes it stops when a white space is found}
            {
                fileHandler >> word;
                std::cout << i++ << "th word => " << word << std::endl;
            }
            fileHandler.close();
   */

    /*  // Unformatted Reading from File With looping.
        // * Input : 
        // Test This is 100.4569 987456,456
        // A simple example 798789,4981 asdasdasduıjaksldjansd opweıqjwelkas d
        // * Output: 
        // 1th word => T
        // 2th word => e
        // 3th word => s
        // 4th word => t
        // 5th word =>  
        // 6th word => T
        // 7th word => h
        // 8th word => i
        // 9th word => s
        // 10th word =>  
        // 11th word => i
        // 12th word => s
        // 13th word =>  
        // 14th word => 1
        // 15th word => 0
        // 16th word => 0
        // 17th word => .
        // 18th word => 4
        // 19th word => 5
        // 20th word => 6
        // 21th word => 9
        // 22th word =>  
        // 23th word => 9
        // 24th word => 8
        // 25th word => 7
        // 26th word => 4
        // 27th word => 5
        // 28th word => 6
        // 29th word => ,
        // 30th word => 4
        // 31th word => 5
        // 32th word => 6
        // 33th word => 

        // 34th word => A
        // 35th word =>  
        // 36th word => s
        // 37th word => i
        // 38th word => m
        // 39th word => p
        // 40th word => l
        // 41th word => e
        // 42th word =>  
        // 43th word => e
        // 44th word => x
        // 45th word => a
        // 46th word => m
        // 47th word => p
        // 48th word => l
        // 49th word => e
        // 50th word =>  
        // 51th word => 7
        // 52th word => 9
        // 53th word => 8
        // 54th word => 7
        // 55th word => 8
        // 56th word => 9
        // 57th word => ,
        // 58th word => 4
        // 59th word => 9
        // 60th word => 8
        // 61th word => 1
        // 62th word =>  
        // 63th word => a
        // 64th word => s
        // 65th word => d
        // 66th word => a
        // 67th word => s
        // 68th word => d
        // 69th word => a
        // 70th word => s
        // 71th word => d
        // 72th word => u
        // 73th word => �
        // 74th word => �
        // 75th word => j
        // 76th word => a
        // 77th word => k
        // 78th word => s
        // 79th word => l
        // 80th word => d
        // 81th word => j
        // 82th word => a
        // 83th word => n
        // 84th word => s
        // 85th word => d
        // 86th word =>  
        // 87th word => o
        // 88th word => p
        // 89th word => w
        // 90th word => e
        // 91th word => �
        // 92th word => �
        // 93th word => q
        // 94th word => j
        // 95th word => w
        // 96th word => e
        // 97th word => l
        // 98th word => k
        // 99th word => a
        // 100th word => s
        // 101th word =>  
        // 102th word => d

        std::ifstream fileHandler{"test.txt"};
        char c{};
        if (!fileHandler)
        {
            std::cerr << "Problem Opening File" << std::endl; return -1;
        }

        int counter = 1;
        while (fileHandler.get(c))
        {
            std::cout << counter++ << "th word => " << c << std::endl;
        }
        fileHandler.close();   
    */
    
    /*  // Writing to File
    // std::ofstream fileHandler{"test.txt", std::ios::trunc}; // Open a file to overwrite it. // std::ios::binary flag enables to write in binary mode..
    // std::ofstream fileHandler_2{"test.txt", std::ios::app}; // Open a file to append it.
    // std::ofstream fileHandler_3{"test.txt", std::ios::ate}; // Open a file to seek to the end of stream when opening.
    */

    return 0;   
}
