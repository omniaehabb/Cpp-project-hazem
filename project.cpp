/*
-User registration program 
-[Options]-- {Add / Fetch / Quit}
-functions [add/ Fetch] with paramterers
-three branches in the program which will depend on the input, choose the option and
call the function 

*/

#include <iostream>
#include <string>
#include <vector>
void print_msg(const std::string& msg)
{
    std::cout << msg;
}

class Application
{
    public:
    // Show Application first 
    void show ()
    {
    print_msg(" User SignUp Application \n");
    print_msg("Please select an option \n");
    print_msg("1: Add Record \n");
    print_msg("2: Fetch Record \n ");
    print_msg("3: Quit \n");

    }
};

class Person 
{
    // show record in the system 
    public: 
    std:: string name;
    int age;
};
// declare a vector to store records 
std::vector<Person> records;

void AddRecord (const std::string& name , int age)
    {
        Person new_person;
        new_person.name = name;
        new_person.age = age;
        records.push_back(new_person);
    }
Person FetchRecord (int userID)
{
    //UserID is the index stored in the Array
    return records[userID]; 
}

enum class option
{
    Add_Record =1,
    Fetch_Record =2,
    Quit =3  
};

option default_option = option::Add_Record; 

// Operator overloading 

std:: istream& operator>> ( std::istream & input_stream,option & result )
{
  int int_option;
  input_stream >> int_option;
  //conversion step from int to option enum
  result = static_cast <option>(int_option); 
  return input_stream;  
}

option user_select()
{
    option option;
    std::cin >> option;
    return option; 
}


int main()
{ 
    // Initialization 
    bool Run = true;
    Application app; 
    option user_option =  default_option;
    int age, userID;
    std::string name; 


    // Code 
    while (Run == true )
    {
    
     app.show(); // 1. Show application 
     user_option = user_select();  // 2. User choose which app 

     switch (user_option)
     {

       case option::Add_Record:
       {
        std::cout << "Enter your name\n";
        std::cin >> name;
        std::cout << "Enter your age\n";
        std::cin >> age;
        AddRecord(name ,age);
        std::cout << "User Added successfully \n"; 
        } break;
        case option::Fetch_Record:
        {
        std::cout << "Enter your userID\n";
        std::cin >> userID;
        if ( userID >= 0 && userID < records.size())
        {
            Person Found= FetchRecord(userID);
            std::cout << "User Found: \n";
            std::cout << "Name: " << Found.name << "\n" ;
            std::cout << "Age " << Found.age <<"\n";
        }
        else
        {
            std::cout <<"Invalid USER \n";
        }
        break;
        }
        case option::Quit:
        {
        std::cout << "SEE U AGAIN!! \n";
        break;
        }
    default:
        {
            std::cout << "Invalid input\n";
        }
      }
    } 

}