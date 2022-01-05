#include "ATM_Version_One.hpp"
#include "ATM_Version_Two.hpp"

int main()
{
    std::cout << "--------------------\n";
    versionOne::ATM machine_1{};
    machine_1.showMembers();
    std::cout << "--------------------\n";
    versionOne::ATM_Program main_program{};
    main_program.showMembers();
    std::cout << "--------USING TEMPLATE FUNCTIONS WITH CONST REFERENCE------------\n";
    showTemplateFunction(machine_1);
    std::cout << "--------------------\n";
    showTemplateFunction(main_program);
    std::cout << "--------USING TEMPLATE FUNCTIONS WITH SMART POINTER------------\n";
    std::unique_ptr<versionOne::ATM> machine_1_PTR = std::make_unique<versionOne::ATM>();
    showTemplateFunction(std::move(machine_1_PTR));
    std::cout << "--------------------\n";
    std::unique_ptr<versionOne::ATM_Program> main_program_PTR = std::make_unique<versionOne::ATM_Program>();
    showTemplateFunction(std::move(main_program_PTR));
    std::cout << "--------USING META FUNCTIONS WITH CONST REFERENCE------------\n";
    versionOne::ATM machine_2{};
    showMetaFunction(machine_2);
    std::cout << "--------------------\n";
    versionOne::ATM_Program sub_program{};
    showMetaFunction(sub_program);
    std::cout << "--------USING META FUNCTIONS WITH SMART POINTER------------\n";
    std::unique_ptr<versionOne::ATM> machine_2_PTR = std::make_unique<versionOne::ATM>();
    showMetaFunction(std::move(machine_2_PTR));
    std::cout << "--------------------\n";
    std::unique_ptr<versionOne::ATM_Program> sub_program_PTR = std::make_unique<versionOne::ATM_Program>();
    showMetaFunction(std::move(sub_program_PTR));
    std::cout << "--------------------\n";


    std::cout << "--------------------------------\n";
    versionTwo::ATM machine_10{};
    machine_10.showMembers();
    std::string tempName = "ISTANBUL";
    machine_10.setIdentifier(tempName);
    std::cout << "New Name => " << machine_10.getIdentifier() << std::endl;
    machine_10.setIntValue(1'000'000);
    std::cout << "New Cash => " << machine_10.getCashAmount() << std::endl;
    std::cout << "--------------------------------\n";
    versionTwo::ATM_Program main_program_version_two{};
    main_program_version_two.showMembers();
    main_program_version_two.setIdentifier(machine_10);
    main_program_version_two.setIntValue(1);
    main_program_version_two.showMembers();
    std::cout << "--------------------------------\n";
    std::cout << "--------------------------------\n";
    std::cout << "--------------------------------\n";
    showMembers(machine_10);
    std::cout << "--------------------------------\n";
    std::cout << "--------------------------------\n";
    std::cout << "--------------------------------\n";
    showMembers(main_program_version_two);
    std::cout << "--------------------------------\n";
    std::cout << "--------------------------------\n";
    std::cout << "--------------------------------\n";
    changeIntValues(machine_10);
    showMembers(machine_10);
    std::cout << "--------------------------------\n";
    std::cout << "--------------------------------\n";
    std::cout << "--------------------------------\n";
    changeIntValues(main_program_version_two);
    showMembers(main_program_version_two);
    std::cout << "--------------------------------\n";
    std::cout << "--------------------------------\n";
    std::cout << "--------------------------------\n";   

    return 0;
}