#include <iostream>
#include <string>

class Animal{
// forming variables..
    private:
    int number;
    std :: string name;

    public:
    //default constructor.
    Animal() : number (0), name("Unknown") {}

    // paramatized constructor..
    Animal(int num, std :: string Name) : number(num) , name(Name){}

    //get and set 

    void setName(std :: string Name){
        name = Name;
    }

    std :: string getName(){
        return name;
    }


    void setNumber(int num){
        number = num;
    }

    int getNumber(){
        return number;
    }

};

int main(){
    //forming objects.

    Animal obj;

    obj.setName("Cat");
    obj.setNumber(23);

    std :: cout << obj.getName() <<"\n";
    return 0;

}
