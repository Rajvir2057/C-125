#include <iostream>
#include <string>
#include <vector>

class LibraryItem{
    // protected members
    protected: 
     std :: string title;
     int year;

    public:
    // default constructor..
    LibraryItem() : title("Unknown") , year(0){}

    //parameterised constructor..
    LibraryItem(std :: string TITLE , int YEAR) : title(TITLE) , year(YEAR){}

    //destructor.
   virtual  ~LibraryItem(){

   }

    //virtual function..
   virtual void displayInfo() const = 0;

    //setters.
    void setTitle(std :: string TITLE){
        title = TITLE;
    }

    void setYear(int YEAR){
        year = YEAR;
    }

    //getters.

    std :: string getTitle() const{
        return title;
    }

    int getYear() const{
        return year;
    }
};

class Book : public LibraryItem{

    //setting members.
    private:
    std :: string author;

    public:
    //default constructor.
    Book():
    LibraryItem() , author("tbd"){}

    //parameterised constructor.
    Book(std :: string title1, int year1, std :: string  m_author):
    LibraryItem(title1, year1) , author(m_author){}

    //override..
    void displayInfo() const override{
        std :: cout << getTitle()<< "\n";
        std :: cout << getAuthor()<< "\n";
        std :: cout << getYear() << "\n";
    }

    //getter and setter
    void setAuthor(std :: string m_author){
        author =  m_author;
    }

    std :: string getAuthor()const {
        return author;
    }

};

class Audiobook : public LibraryItem{
    //new members
    private:
        std::string narrator;
        double lengthHours;

    public:
    // default constructor
    Audiobook():
    LibraryItem() , narrator("name") , lengthHours(0.0){}

    //parameterised constructor..
    Audiobook(std :: string title2 , int year2, std :: string m_narrator, double m_lengthHours):
    LibraryItem(title2, year2) , narrator(m_narrator) , lengthHours(m_lengthHours){}

    //overide..
    void displayInfo() const override{
        std :: cout << "\n";
        std :: cout << getTitle()<< "\n";
        std :: cout << getYear() << "\n";
        std :: cout << getNarrator()<< "\n";
        std :: cout << getLengthHours()<< "\n";


    }

    // getters
    void setNarrator(std :: string m_narrator){
        narrator = m_narrator;
    }

    void setLengthHours(double m_lengthHours){
        lengthHours = m_lengthHours;
    }

    // setters
    std :: string getNarrator()const{
        return narrator;
    }

    int getLengthHours()const{
        return lengthHours;
    }
};

int main(){

    //creating objects..
    Book book("Clean Code", 2020 ,"John Doe");
    Audiobook Audiobook("Sample Audio",2018,"Jane doe",5.6);

    //setters
    book.setTitle("Clean Code : Updated Edition");
    Audiobook.setLengthHours(6.0);

    LibraryItem& item = book;
    item.displayInfo();

    LibraryItem& item1 = Audiobook;
    item1.displayInfo();


    return 0;
}
