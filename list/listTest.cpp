#include "list.hpp"
#include <list>
# define G "\e[92m\e[1m"
# define D "\e[39m\e[0m"
# define R "\e[91m"
# define Y "\e[93m"

int main () {
    try {
        /****** CONSTRUCTOR  ********/

        {
            std::cout << Y "My constructor\n" D;

            ft::list<int> myListDefault;
            std::cout << "Default construct, size = " << myListDefault.size() << "\n";

            ft::list<char> myListElement1(6);
            std::cout << "Construct with n element empty, size = " << myListElement1.size() << "\n";
            std::cout << "Front element = |" << myListElement1.front() << "|\n";
//            ft::list<char>::const_iterator myIT1;// = myListElement1.begin();
//
//            std::cout  << "iterator = " << *myIT1 << "\n";




//нужно разобраться с константным итераторм

//хочу реализовать через пуш бэк




            ft::list<char> myListElement(4, 'C');
            std::cout << "Construct with n element, size = " << myListElement.size() << "\n";
            std::cout << "Front element = " << myListElement.front() << "\n";
            std::cout << "Back element = " << myListElement.back() << "\n";

            myListElement.push_back('Z');
            ft::list<char>::iterator myIT = myListElement.begin();
            ft::list<char>::iterator myITend = myListElement.end();
            ft::list<char> myinalIterator(myIT, myITend);
            std::cout << "Construct with iterator, size = " << myinalIterator.size() << "\n";
            std::cout << "Front element = " << myinalIterator.front() << "\n";
            std::cout << "Back element = " << myinalIterator.back() << "\n";


            std::cout << Y"Original constructor\n" << D;

            std::list<int> origListDefault;
            std::cout << "Default construct, size = " << origListDefault.size() << "\n";

            std::list<char> origListElement1(6);
            std::cout << "Construct with n element empty, size = " << origListElement1.size() << "\n";
            std::cout << "Front element = |" << origListElement1.front() << "|\n";

           std::list<char> origListElement(4, 'C');
           std::cout << "Construct with n element, size = " << origListElement.size() << "\n";
           std::cout << "Front element = " << origListElement.front() << "\n";
           std::cout << "Back element = " << origListElement.back() << "\n";

           origListElement.push_back('Z');
           std::list<char>::iterator origIT = origListElement.begin();
           std::list<char> originalIterator(origIT, origListElement.end());
           std::cout << "Construct with iterator, size = " << originalIterator.size() << "\n";
           std::cout << "Front element = " << originalIterator.front() << "\n";
           std::cout << "Back element = " << originalIterator.back() << "\n";

        }

                /******CONSTRUCT COPY AND OPERATOR =  ********/
        {
            std::cout << Y "\nMy construct copy and operator '='\n" D;

           ft::list<int> myList;
           for (int i = 0; i < 5; i++)
               myList.push_back(i);
           ft::list<int> myListCopy(myList);
           std::cout << "Construct copy, size = " << myListCopy.size() << "\n";
           std::cout << "Front element = " << myListCopy.front() << "\n";
           std::cout << "Back element = " << myListCopy.back() << "\n";

           myList.push_back(55);
           ft::list<int> myListEquality = myList;
           std::cout << "Operator equality, size = " << myListEquality.size() << "\n";
           ft::list<int>::iterator itstart = myListEquality.begin();
           ft::list<int>::iterator itfinish = myListEquality.end();
           while(itstart != itfinish) {
                std::cout << *itstart<< " ";
                itstart++;
           }
            std::cout << "\n";


           std::cout << Y "Original construct copy and operator '='\n" D;

           std::list<int> origList;
           for (int i = 0; i < 5; i++)
               origList.push_back(i);
           std::list<int> origListCopy(origList);
           std::cout << "Construct copy, size = " << origListCopy.size() << "\n";
           std::cout << "Front element = " << origListCopy.front() << "\n";
           std::cout << "Back element = " << origListCopy.back() << "\n";

            origListCopy.push_back(55);
           std::list<int> originalListEquality = origListCopy;
           std::cout << "Operator equality, size = " << originalListEquality.size() << "\n";
           std::list<int>::iterator itstart1 = originalListEquality.begin();
           std::list<int>::iterator itfinish1 = originalListEquality.end();
           while(itstart1 != itfinish1) {
                std::cout << *itstart1<< " ";
                itstart1++;
           }
            std::cout << "\n";
        }

                    /****** ITERATOR ********/


        {

            std::cout <<Y "\nMy iterator\n" D;

           ft::list<int>::iterator myIT;
           ft::list<int>::iterator myITend;
           ft::list<int> myVector;
           for(int i = 0; i < 10; i+=2)
               myVector.push_back(i);
           myIT = myVector.begin();
           myITend = myVector.end();
           while(myIT != myITend ) {
               std::cout << "MyIT = " << *myIT << "\n";
               myIT++;
           }

//            ft::list<int>::reverse_iterator myITReverse;
//            ft::list<int>::reverse_iterator myITEndReverse;
//            myITReverse = myVector.rbegin();
//            myITEndReverse = myVector.rend();
//            while(myITReverse != myITEndReverse) {
//                std::cout << "myITReverse = " << *myITReverse << "\n";
//                myITReverse++;
//            }

            std::cout <<Y "Original iterator\n" D;


           std::list<int>::iterator originalIT;
           std::list<int>::iterator originalITend;
           std::list<int> originalVector;
           for(int i = 0; i < 10; i+=2)
               originalVector.push_back(i);
           originalIT = originalVector.begin();
           originalITend = originalVector.end();
           while(originalIT != originalITend ) {
               std::cout << "OriginalIT = " << *originalIT << "\n";
               originalIT++;
           }

//            std::list<int>::reverse_iterator originalITReverse;
//            std::list<int>::reverse_iterator originalITEndReverse;
//            originalITReverse = originalVector.rbegin();
//            originalITEndReverse = originalVector.rend();
//            while(originalITReverse != originalITEndReverse) {
//                std::cout << "originalITReverse = " << *originalITReverse << "\n";
//                originalITReverse++;
//            }

        }

 /**********	Capacity **********/
 
 {
    std::cout <<Y "My capasity\n" D;

            ft::list<int> myList(5);
            std::cout << "Size = " << myList.size() << "\n";
            std::cout << "Max size = " << myList.max_size() << "\n";
            
            std::cout << "myList empty = " << myList.empty() << "\n";
            ft::list<int> newMy;
            std::cout << "newMy empty = " << newMy.empty() << "\n";
            std::cout << "Size = " << newMy.size() << "\n";
           

            std::cout <<Y "Original capasity\n" D;

            std::list<int> originalList(5);
            std::cout << "Size = " << originalList.size() << "\n";
            std::cout << "Max size = " << originalList.max_size() << "\n";
            
            std::cout << "originalList empty = " << originalList.empty() << "\n";
            std::list<int> newOriginal;
            std::cout << "newOriginal empty = " << newOriginal.empty() << "\n";
            std::cout << "Size = " << newOriginal.size() << "\n";

            

 }


        /******* Element access ******/

        {

                std::cout <<Y "My element access\n" D;



                std::cout <<Y "Origin element access\n" D;


                std::list<double> origlist;
                for(double i = 1.1; i < 4; i += 1.1) {
                    origlist.push_back(i);
                }                   
                std::cout << "front = " << origlist.front() << '\n';
                std::cout << "back = " << origlist.back() << '\n';

        }



    {

//        std::list<int> orlist;
//        orlist.assign(5,7);
//        std::list<int>::iterator it1 = orlist.begin();
//        std::list<int>::iterator it2 = orlist.end();
//        while (it1 != it2) {
//            std::cout << *it1 << "\n";
//            it1++;
        }






    }
    catch(const char * e)
    {
        std::cerr << e << '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

return 0;
}

