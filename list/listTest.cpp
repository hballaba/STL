#include "list.hpp"
#include <list>
# define G "\e[92m\e[1m"
# define D "\e[39m\e[0m"
# define R "\e[91m"
# define Y "\e[93m"


bool single_digit (const int& value) { return (value<10); }

bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }

bool compare_nocase (const std::string& first, const std::string& second)
{
    unsigned int i=0;
    while ( (i<first.length()) && (i<second.length()) )
    {
        if (tolower(first[i])<tolower(second[i])) return true;
        else if (tolower(first[i])>tolower(second[i])) return false;
        ++i;
    }
    return ( first.length() < second.length() );
}

bool mycomparison (double first, double second)
{ return ( int(first)<int(second) ); }


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


            ft::list<char> myListElement(4, 'C');
            std::cout << "Construct with n element, size = " << myListElement.size() << "\n";
            std::cout << "Front element = " << myListElement.front() << "\n";
            std::cout << "Back element = " << myListElement.back() << "\n";

            myListElement.push_back('Z');
            ft::list<char> myinalIterator(myListElement.begin(), myListElement.end());
            std::cout << "Construct with iterator, size = " << myinalIterator.size() << "\n";
            std::cout << "Front element = " << myinalIterator.front() << "\n";
            std::cout << "Back element = " << myinalIterator.back() << "\n";


            std::cout << Y"\nOriginal constructor\n" << D;

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
           std::list<char> originalIterator(origListElement.begin(), origListElement.end());
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


           std::cout << Y "\nOriginal construct copy and operator '='\n" D;

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
           ft::list<int> myList;
           for(int i = 0; i < 10; i+=2)
               myList.push_back(i);
           myIT = myList.begin();
           myITend = myList.end();
           while(myIT != myITend ) {
               std::cout << "MyIT = " << *myIT << "\n";
               myIT++;
           }

            ft::list<int>::reverse_iterator myITReverse;
            ft::list<int>::reverse_iterator myITEndReverse;
            myITReverse = myList.rbegin();
            myITEndReverse = myList.rend();
            while(myITReverse != myITEndReverse) {
                std::cout << "myITReverse = " << *myITReverse << "\n";
                myITReverse++;
            }

            std::cout <<Y "\nOriginal iterator\n" D;


           std::list<int>::iterator originalIT;
           std::list<int>::iterator originalITend;
           std::list<int> originalList;
           for(int i = 0; i < 10; i+=2)
               originalList.push_back(i);
           originalIT = originalList.begin();
           originalITend = originalList.end();
           while(originalIT != originalITend ) {
               std::cout << "OriginalIT = " << *originalIT << "\n";
               originalIT++;
           }

            std::list<int>::reverse_iterator originalITReverse;
            std::list<int>::reverse_iterator originalITEndReverse;
            originalITReverse = originalList.rbegin();
            originalITEndReverse = originalList.rend();
            while(originalITReverse != originalITEndReverse) {
                std::cout << "originalITReverse = " << *originalITReverse << "\n";
                originalITReverse++;
            }

        }

         /**********	Capacity **********/
 
        {
            std::cout <<Y "\nMy capasity\n" D;

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
                std::cout <<Y "\nMy element access\n" D;

                ft::list<double> mylist;
                for(double i = 1.1; i < 4; i += 1.1) {
                    mylist.push_back(i);
                }
                 std::cout << "Size = " << mylist.size() << "\n";
                std::cout << "front = " << mylist.front() << '\n';
                std::cout << "back = " << mylist.back() << '\n';

                std::cout <<Y "Origin element access\n" D;


                std::list<double> origlist;
                for(double i = 1.1; i < 4; i += 1.1) {
                    origlist.push_back(i);
                }         
                std::cout << "Size = " << origlist.size() << "\n";          
                std::cout << "front = " << origlist.front() << '\n';
                std::cout << "back = " << origlist.back() << '\n';

        }

                /********* MODIFIERS  ***********/


        {

            std::cout << Y"\nMy assign\n"D;

            ft::list<std::string> myList;
            myList.assign(3, "Hello");
            ft::list<std::string>::iterator itSt1 = myList.begin();
            ft::list<std::string>::iterator itFin1 = myList.end();
            std::cout << "size = " << myList.size() << "\n";
            while (itSt1 != itFin1) {
                std::cout << *itSt1 << " ";
                itSt1++;
            }
            std::cout << "\n";

            myList.push_back("World");
            myList.push_back("World");

            ft::list<std::string> myListIT;
            myListIT.assign(myList.begin(), myList.end());
            ft::list<std::string>::iterator itSt2 = myListIT.begin();
            ft::list<std::string>::iterator itFin2 = myListIT.end();

            std::cout << "size = " << myListIT.size() << "\n";
            while (itSt2 != itFin2) {
                std::cout << *itSt2 << " ";
                itSt2++;
            }
            std::cout << "\n";


            std::cout << Y"\nOrigin assign\n"D;

            std::list<std::string> origList;
            origList.assign(3, "Hello");
            std::list<std::string>::iterator itSt = origList.begin();
            std::list<std::string>::iterator itFin = origList.end();
            std::cout << "size = " << origList.size() << "\n";
            while (itSt != itFin) {
                std::cout << *itSt << " ";
                itSt++;
            }
            origList.push_back("World");
            origList.push_back("World");
            std::cout << "\n";

            std::list<std::string> origListIT;
            origListIT.assign(origList.begin(), origList.end());
            std::list<std::string>::iterator itSt0 = origListIT.begin();
            std::list<std::string>::iterator itFin0 = origListIT.end();
            std::cout << "size = " << origListIT.size() << "\n";
            while (itSt0 != itFin0) {
                std::cout << *itSt0 << " ";
                itSt0++;
            }
        }


        {

                std::cout << Y"\nMy push/pop back/front\n"D;

                ft::list<int> myList;
                myList.push_back(11);
                myList.push_back(22);
                myList.push_front(33);
                myList.push_front(44);
                ft::list<int>::iterator itSt = myList.begin();
                ft::list<int>::iterator itFin = myList.end();
                std::cout << "size = " << myList.size() << "\n";
                while (itSt != itFin) {
                    std::cout << *itSt << " ";
                    itSt++;
                }
                std::cout << '\n';

                myList.pop_back();
                myList.pop_front();

                itSt = myList.begin();
                itFin = myList.end();
                std::cout << "size = " << myList.size() << "\n";
                while (itSt != itFin) {
                    std::cout << *itSt << " ";
                    itSt++;
                }
                std::cout << '\n';
                myList.pop_back();
                myList.pop_back();
                std::cout << "size = " << myList.size() << "\n";


                std::cout << Y"\nOriginal push/pop back/front\n"D;


                std::list<int> origList;
                origList.push_back(11);
                origList.push_back(22);
                origList.push_front(33);
                origList.push_front(44);
                std::list<int>::iterator itSt0 = origList.begin();
                std::list<int>::iterator itFin0 = origList.end();
                std::cout << "size = " << origList.size() << "\n";
                while (itSt0 != itFin0) {
                    std::cout << *itSt0 << " ";
                    itSt0++;
                }
                std::cout << '\n';

                origList.pop_back();
                origList.pop_front();

                itSt0 = origList.begin();
                itFin0 = origList.end();
                std::cout << "size = " << origList.size() << "\n";
                while (itSt0 != itFin0) {
                    std::cout << *itSt0 << " ";
                    itSt0++;
                }
                std::cout << '\n';
                origList.pop_back();
                origList.pop_back();
                std::cout << "size = " << origList.size() << "\n";


                std::cout << Y"\nMy insert\n"D;


            for (int i = 1; i < 6; i++)
                myList.push_back(i);
            itFin = myList.end();
            itSt = myList.begin();
            std::cout << "Value myList = ";
            while(itSt != itFin) {
                std::cout << *itSt << " ";
                itSt++;
            }
            std::cout << "\n";
            ft::list<int> myList2;
            for (int i = 11; i < 43; i+= 11)
                myList2.push_back(i);

            itFin = myList2.end();
            itSt = myList2.begin();
            std::cout << "Value myList2 = ";
            while(itSt != itFin) {
                std::cout << *itSt << " ";
                itSt++;
            }
            std::cout << "\n";

            ft::list<int>::iterator place = myList.begin();
            place++;
            itSt = myList2.begin();
            itSt++;
            myList.insert(place, itSt, itFin);
            itSt = myList.begin();
            itFin = myList.end();
            std::cout << "Value myList after insert iterator = ";
            while(itSt != itFin) {
                std::cout << *itSt << " ";
                itSt++;
            }
            std::cout << "\n";

            --itSt;
            myList.insert(itSt, 777);
            itSt = myList.begin();
            std::cout << "Value myList after insert value = ";
            while(itSt != itFin) {
                std::cout << *itSt << " ";
                itSt++;
            }
            std::cout << "\n";
            place++;
            place++;

            myList.insert(place, 3, 888);
            std::cout << "Value origList after insert n element with value = ";

            itSt = myList.begin();
            while(itSt != itFin) {
                std::cout << *itSt << " ";
                itSt++;
            }
            std::cout << "\n";


                std::cout << Y"\nOriginal insert\n"D;



                for (int i = 1; i < 6; i++)
                    origList.push_back(i);
                itFin0 = origList.end();
                itSt0 = origList.begin();
                std::cout << "Value origList = ";
                while(itSt0 != itFin0) {
                    std::cout << *itSt0 << " ";
                    itSt0++;
                }
                std::cout << "\n";
                    std::list<int> origList2;
                    for (int i = 11; i < 43; i+= 11)
                        origList2.push_back(i);

                itFin0 = origList2.end();
                itSt0 = origList2.begin();
                std::cout << "Value origList2 = ";
                while(itSt0 != itFin0) {
                    std::cout << *itSt0 << " ";
                    itSt0++;
                }
                std::cout << "\n";

                std::list<int>::iterator place0 = origList.begin();
                place0++;
                itSt0 = origList2.begin();
                itSt0++;
                origList.insert(place0, itSt0, itFin0);
                itSt0 = origList.begin();
                itFin0 = origList.end();
                std::cout << "Value origList after insert iterator = ";
                while(itSt0 != itFin0) {
                    std::cout << *itSt0 << " ";
                    itSt0++;
                }
                std::cout << "\n";

                itSt0--;
                origList.insert(itSt0, 777);
                itSt0 = origList.begin();
                std::cout << "Value origList after insert value = ";
                while(itSt0 != itFin0) {
                    std::cout << *itSt0 << " ";
                    itSt0++;
                }
                std::cout << "\n";

                place0++;
                place0++;
                origList.insert(place0, 3, 888);
                std::cout << "Value origList after insert n element with value = ";

                itSt0 = origList.begin();
                while(itSt0 != itFin0) {
                    std::cout << *itSt0 << " ";
                    itSt0++;
                }
                std::cout << "\n";
            }


        {

            std::cout << Y"\nMy erase\n"D;

            ft::list<double> myList;
            for(double i = 1.1 ; i < 6; i+=1.1)
                myList.push_front(i);

            ft::list<double>::iterator itSt = myList.begin();
            ft::list<double>::iterator itFin = myList.end();
            std::cout << "Value myList = ";
            while(itSt != itFin) {
                std::cout << *itSt << " ";
                itSt++;
            }
            std::cout << "\n";

            itSt = myList.begin();
            itSt++;
            myList.erase(itSt);

            itSt = myList.begin();
            std::cout << "Value myList after erase = ";
            while(itSt != itFin) {
                std::cout << *itSt << " ";
                itSt++;
            }
            std::cout << "\n";

            itSt = myList.begin();
            itSt++;
            myList.erase(itSt, itFin);
            std::cout << "Size = " << myList.size() << "\n";
            itSt = myList.begin();
            itFin = myList.end();
            std::cout << "Value myList after erase iterator = ";
            while(itSt != itFin) {
                std::cout << *itSt << " ";
                itSt++;
            }
            std::cout << "\n";


            std::cout << Y"\nOriginal erase\n"D;

            std::list<double> origList;
            for(double i = 1.1 ; i < 6; i+=1.1)
                origList.push_front(i);

            std::list<double>::iterator itSt0 = origList.begin();
            std::list<double>::iterator itFin0 = origList.end();
            std::cout << "Value origList = ";
            while(itSt0 != itFin0) {
                std::cout << *itSt0 << " ";
                itSt0++;
            }
            std::cout << "\n";

            itSt0 = origList.begin();
            itSt0++;
            origList.erase(itSt0);

            itSt0 = origList.begin();
            std::cout << "Value origList after erase = ";
            while(itSt0 != itFin0) {
                std::cout << *itSt0 << " ";
                itSt0++;
            }
            std::cout << "\n";

            itSt0 = origList.begin();
            itSt0++;
            origList.erase(itSt0, itFin0);
            std::cout << "Size = " << origList.size() << "\n";
            itSt0 = origList.begin();
            itFin0 = origList.end();
            std::cout << "Value origList after erase iterator = ";
            while(itSt0 != itFin0) {
                std::cout << *itSt0 << " ";
                itSt0++;
            }
            std::cout << "\n";

        }

        {
            std::cout << Y"\nMy swap\n"D;

            ft::list<std::string> myList;
            myList.assign(3, "SCHOOL");
            ft::list<std::string> myList2;
            myList2.assign(2, "21");

            ft::list<std::string>::iterator itSt = myList.begin();
            ft::list<std::string>::iterator itFin = myList.end();
            std::cout << "Value myList = ";
            while(itSt != itFin) {
                std::cout << *itSt << " ";
                itSt++;
            }
            std::cout << "\n";

            itSt = myList2.begin();
            itFin = myList2.end();
            std::cout << "Value myList2 = ";
            while(itSt != itFin) {
                std::cout << *itSt << " ";
                itSt++;
            }
            std::cout << "\n";

            myList.swap(myList2);
            itSt = myList.begin();
            itFin = myList.end();
            std::cout << "Value myList = ";
            while(itSt != itFin) {
                std::cout << *itSt << " ";
                itSt++;
            }
            std::cout << "\n";

            itSt = myList2.begin();
            itFin = myList2.end();
            std::cout << "Value myList2 = ";
            while(itSt != itFin) {
                std::cout << *itSt << " ";
                itSt++;
            }
            std::cout << "\n";


            std::cout << Y"\nOriginal swap\n"D;

            std::list<std::string> origList;
            origList.assign(3, "SCHOOL");
            std::list<std::string> origList2;
            origList2.assign(2, "21");

            std::list<std::string>::iterator itSt0 = origList.begin();
            std::list<std::string>::iterator itFin0 = origList.end();
            std::cout << "Value origList = ";
            while(itSt0 != itFin0) {
                std::cout << *itSt0 << " ";
                itSt0++;
            }
            std::cout << "\n";

            itSt0 = origList2.begin();
            itFin0 = origList2.end();
            std::cout << "Value origList2 = ";
            while(itSt0 != itFin0) {
                std::cout << *itSt0 << " ";
                itSt0++;
            }
            std::cout << "\n";

            origList.swap(origList2);
            itSt0 = origList.begin();
            itFin0 = origList.end();
            std::cout << "Value origList = ";
            while(itSt0 != itFin0) {
                std::cout << *itSt0 << " ";
                itSt0++;
            }
            std::cout << "\n";

            itSt0 = origList2.begin();
            itFin0 = origList2.end();
            std::cout << "Value origList2 = ";
            while(itSt0 != itFin0) {
                std::cout << *itSt0 << " ";
                itSt0++;
            }
            std::cout << "\n";

        }

        {

            std::cout << Y"\nMy resize and clear\n"D;

            ft::list<char> myList;
            myList.push_back('A');
            myList.resize(3);
            myList.resize(5, 'B');
            ft::list<char>::iterator itSt = myList.begin();
            ft::list<char>::iterator itFin = myList.end();
            std:: cout << "Size = " << myList.size() << "\n";
            std::cout << "Value myList = ";
            while(itSt != itFin) {
                std::cout << "|" << *itSt << "| ";
                itSt++;
            }
            std::cout << "\n";

            myList.resize(2, 'B');
            itSt = myList.begin();
            itFin = myList.end();
            std:: cout << "Size = " << myList.size() << "\n";
            std::cout << "Value MyList = ";
            while(itSt != itFin) {
                std::cout << "|" << *itSt << "| ";
                itSt++;
            }
            std::cout << "\n";

            myList.clear();
            itSt = myList.begin();
            itFin = myList.end();
            std:: cout << "Size = " << myList.size() << "\n";
            std::cout << "Value MyList = |";
            while(itSt != itFin) {
                std::cout << "|" << *itSt << "| ";
                itSt++;
            }
            std::cout << "|\n";



            std::cout << Y"\nOriginal resize and clear\n"D;

            std::list<char> origList;
            origList.push_back('A');
            origList.resize(3);
            origList.resize(5, 'B');
            std::list<char>::iterator itSt0 = origList.begin();
            std::list<char>::iterator itFin0 = origList.end();
            std:: cout << "Size = " << origList.size() << "\n";
            std::cout << "Value origList = ";
            while(itSt0 != itFin0) {
                std::cout << "|" << *itSt0 << "| ";
                itSt0++;
            }
            std::cout << "\n";


            origList.resize(2, 'B');
            itSt0 = origList.begin();
            itFin0 = origList.end();
            std:: cout << "Size = " << origList.size() << "\n";
            std::cout << "Value origList = ";
            while(itSt0 != itFin0) {
                std::cout << "|" << *itSt0 << "| ";
                itSt0++;
            }
            std::cout << "\n";

            origList.clear();
            itSt0 = origList.begin();
            itFin0 = origList.end();
            std:: cout << "Size = " << origList.size() << "\n";
            std::cout << "Value origList = |";
            while(itSt0 != itFin0) {
                std::cout << "|" << *itSt0 << "| ";
                itSt0++;
            }
            std::cout << "|\n";

        }
                    /***********  Operations  **************/
        {

            std::cout << Y"\nMy splice\n"D;

            ft::list<int> myList1, myList2;
            ft::list<int>::iterator it1;

            for (int i = 1; i <= 4; ++i)
                myList1.push_back(i);      // mynlist1: 1 2 3 4

            for (int i = 1; i <= 3; ++i)
                myList2.push_back(i * 10);   // mynlist2: 10 20 30


            it1 = myList1.begin();
            ++it1;

            ft::list<int>::iterator first1 = myList2.begin();
            ft::list<int>::iterator last1 = myList2.end();
            first1++;
            myList1.splice(it1, myList2, first1, last1);

            ft::list<int>::iterator itSt = myList1.begin();
            ft::list<int>::iterator itFin = myList1.end();
            std::cout << "Size = " << myList1.size() << "\n";
            std::cout << "Value myList = ";
            while (itSt != itFin) {
                std::cout << *itSt << " ";
                itSt++;
            }
            std::cout << "\n";

            itSt = myList2.begin();
            itFin = myList2.end();
            std::cout << "Size = " << myList2.size() << "\n";
            std::cout << "Value myList2 = ";
            while (itSt != itFin) {
                std::cout << *itSt << " ";
                itSt++;
            }
            std::cout << "\n";

            myList2.push_front(55);
            myList2.push_front(77);
            myList1.splice(myList1.begin(), myList2);

            itSt = myList1.begin();
            itFin = myList1.end();
            std::cout << "Size myList1= " << myList1.size() << "\n";
            std::cout << "Value myList1 = ";
            while (itSt != itFin) {
                std::cout << *itSt << " ";
                itSt++;
            }
            std::cout << "\n";
            std::cout << "Size myList2= " << myList2.size() << "\n";

            myList2.push_front(8);
            myList2.push_front(9);
            itSt = myList1.begin();
            itSt++;
            myList1.splice(itSt, myList2, myList2.begin());
            itSt = myList1.begin();
            itFin = myList1.end();
            std::cout << "Size myList1= " << myList1.size() << "\n";
            std::cout << "Value myList1 = ";
            while (itSt != itFin) {
                std::cout << *itSt << " ";
                itSt++;
            }
            std::cout << "\n";
            std::cout << "Size myList2= " << myList2.size() << "\n";


            std::cout << Y"\nOriginal splice\n"D;

            std::list<int> origList1, origList2;
            std::list<int>::iterator it;

            for (int i = 1; i <= 4; ++i)
                origList1.push_back(i);      // orignlist1: 1 2 3 4

            for (int i = 1; i <= 3; ++i)
                origList2.push_back(i * 10);   // orignlist2: 10 20 30

            it = origList1.begin();
            ++it;

            std::list<int>::iterator first = origList2.begin();
            std::list<int>::iterator last = origList2.end();
            first++;
            origList1.splice(it, origList2, first, last);

            std::list<int>::iterator itSt0 = origList1.begin();
            std::list<int>::iterator itFin0 = origList1.end();
            std::cout << "Size origList1 = " << origList1.size() << "\n";
            std::cout << "Value origList1 = ";
            while (itSt0 != itFin0) {
                std::cout << *itSt0 << " ";
                itSt0++;
            }
            std::cout << "\n";

            itSt0 = origList2.begin();
            itFin0 = origList2.end();
            std::cout << "Size origList2 = " << origList2.size() << "\n";
            std::cout << "Value origList2 = ";
            while (itSt0 != itFin0) {
                std::cout << *itSt0 << " ";
                itSt0++;
            }
            std::cout << "\n";
            origList2.push_front(55);
            origList2.push_front(77);
            origList1.splice(origList1.begin(), origList2);

            itSt0 = origList1.begin();
            itFin0 = origList1.end();
            std::cout << "Size origList1= " << origList1.size() << "\n";
            std::cout << "Value origList1 = ";
            while (itSt0 != itFin0) {
                std::cout << *itSt0 << " ";
                itSt0++;
            }
            std::cout << "\n";
            std::cout << "Size origList2= " << origList2.size() << "\n";

            origList2.push_front(8);
            origList2.push_front(9);
            itSt0 = origList1.begin();
            itSt0++;
            origList1.splice(itSt0, origList2, origList2.begin());
            itSt0 = origList1.begin();
            itFin0 = origList1.end();
            std::cout << "Size origList1= " << origList1.size() << "\n";
            std::cout << "Value origList1 = ";
            while (itSt0 != itFin0) {
                std::cout << *itSt0 << " ";
                itSt0++;
            }
            std::cout << "\n";
            std::cout << "Size origList2= " << origList2.size() << "\n";
        }

            {

                std::cout << Y"\nMY remove and remove_if\n"D;

                ft::list<int> myList;
                for (int i = 0; i < 3; i++) {
                    myList.push_front(5);
                    myList.push_front(77);
                    myList.push_front(33);
                    myList.push_front(1);
                }
                ft::list<int>::iterator itSt = myList.begin();
                ft::list<int>::iterator itFin = myList.end();
                std::cout << "Size myList = " << myList.size() << "\n";
                std::cout << "Value myList = ";
                while (itSt != itFin) {
                    std::cout << *itSt << " ";
                    itSt++;
                }
                std::cout << "\n";
                myList.remove(77);
                itSt = myList.begin();
                itFin = myList.end();
                std::cout << "Size myList after remove = " << myList.size() << "\n";
                std::cout << "Value myList = ";
                while (itSt != itFin) {
                    std::cout << *itSt << " ";
                    itSt++;
                }
                std::cout << "\n";

                myList.remove_if(single_digit);
                itSt = myList.begin();
                itFin = myList.end();
                std::cout << "\nRemove if value single digital\n";
                std::cout << "Size myList after remove_if = " << myList.size() << "\n";
                std::cout << "Value myList = ";
                while (itSt != itFin) {
                    std::cout << *itSt << " ";
                    itSt++;
                }
                std::cout << "\n";


                std::cout << Y"\nOriginal remove and remove_if\n"D;
                std::list<int> origList;
                for (int i = 0; i < 3; i++) {
                    origList.push_front(5);
                    origList.push_front(77);
                    origList.push_front(33);
                    origList.push_front(1);
                }
                std::list<int>::iterator itSt0 = origList.begin();
                std::list<int>::iterator itFin0 = origList.end();
                std::cout << "Size origList = " << origList.size() << "\n";
                std::cout << "Value origList = ";
                while (itSt0 != itFin0) {
                    std::cout << *itSt0 << " ";
                    itSt0++;
                }
                std::cout << "\n";
                origList.remove(77);
                itSt0 = origList.begin();
                itFin0 = origList.end();
                std::cout << "Size origList after remove = " << origList.size() << "\n";
                std::cout << "Value origList = ";
                while (itSt0 != itFin0) {
                    std::cout << *itSt0 << " ";
                    itSt0++;
                }
                std::cout << "\n";
                origList.remove_if(single_digit);
                itSt0 = origList.begin();
                itFin0 = origList.end();
                std::cout << "\nRemove if value single digital\n";
                std::cout << "Size origList after remove_if = " << origList.size() << "\n";
                std::cout << "Value origList = ";
                while (itSt0 != itFin0) {
                    std::cout << *itSt0 << " ";
                    itSt0++;
                }
                std::cout << "\n";
            }

        {

            std::cout << Y"\nmy unique\n"D;

            ft::list<double> myList;
            for (int i = 0; i < 3; i++) {
                myList.push_front(5.0);
                myList.push_front(33.1);
                myList.push_front(33.1);
                myList.push_front(33.8);
                myList.push_front(7.0);
                myList.push_front(33.1);
            }
            ft::list<double>::iterator itSt = myList.begin();
            ft::list<double>::iterator itFin = myList.end();
            std::cout << "Size myList = " << myList.size() << "\n";
            std::cout << "Value myList = ";
            while (itSt != itFin) {
                std::cout << "|" << *itSt << "| ";
                itSt++;
            }
            std::cout << "\n";
//            myList.sort();
            myList.unique();
            itSt = myList.begin();
            itFin = myList.end();
            std::cout << "Size myList after unique = " << myList.size() << "\n";
            std::cout << "Value myList = ";
            while (itSt != itFin) {
                std::cout << "|" << *itSt << "| ";
                itSt++;
            }
            std::cout << "\n";
            myList.unique();
            std::cout << "Size myList after double unique = " << myList.size() << "\n";

            myList.unique(same_integral_part);
            itSt = myList.begin();
            itFin = myList.end();
            std::cout << "Size myList after predicate unique = " << myList.size() << "\n";
            std::cout << "Value myList = ";
            while (itSt != itFin) {
                std::cout << "|" << *itSt << "| ";
                itSt++;
            }
            std::cout << "\n";


            std::cout << Y"\nOriginal unique\n"D;

            std::list<double> origList;
            for (int i = 0; i < 3; i++) {
                origList.push_front(5.0);
                origList.push_front(33.1);
                origList.push_front(33.1);
                origList.push_front(33.8);
                origList.push_front(7.0);
                origList.push_front(33.1);
            }
            std::list<double>::iterator itSt0 = origList.begin();
            std::list<double>::iterator itFin0 = origList.end();
            std::cout << "Size origList = " << origList.size() << "\n";
            std::cout << "Value origList = ";
            while (itSt0 != itFin0) {
                std::cout << "|" << *itSt0 << "| ";
                itSt0++;
            }
            std::cout << "\n";

            origList.unique();
            itSt0 = origList.begin();
            itFin0 = origList.end();
            std::cout << "Size origList after unique = " << origList.size() << "\n";
            std::cout << "Value origList = ";
            while (itSt0 != itFin0) {
                std::cout << "|" << *itSt0 << "| ";
                itSt0++;
            }
            std::cout << "\n";
            origList.unique();
            std::cout << "Size origList after double unique = " << origList.size() << "\n";


            origList.unique(same_integral_part);
            itSt0 = origList.begin();
            itFin0 = origList.end();
            std::cout << "Size origList after predicate unique = " << origList.size() << "\n";
            std::cout << "Value origList = ";
            while (itSt0 != itFin0) {
                std::cout << "|" << *itSt0 << "| ";
                itSt0++;
            }
            std::cout << "\n";

        }


        {

            std::cout << Y"\nMy sort, merge and reverse\n"D;

            ft::list<std::string> myList;
            myList.push_back("one");
            myList.push_back("two");
            myList.push_back("Three");
            myList.push_back("four");
            myList.sort();
            ft::list<std::string>::iterator itSt = myList.begin();
            ft::list<std::string>::iterator itFin = myList.end();
            std::cout << "Size myList = " << myList.size() << "\n";
            std::cout << "Value myList = ";
            while (itSt != itFin) {
                std::cout << "|" << *itSt << "| ";
                itSt++;
            }
            std::cout << "\n";

            myList.sort(compare_nocase);

            itSt = myList.begin();
            itFin = myList.end();
            std::cout << "Size myList after sort compare = " << myList.size() << "\n";
            std::cout << "Value origList = ";
            while (itSt != itFin) {
                std::cout << "|" << *itSt << "| ";
                itSt++;
            }
            std::cout << "\n";

            myList.reverse();
            itSt = myList.begin();
            itFin = myList.end();
            std::cout << "Size myList after reverse = " << myList.size() << "\n";
            std::cout << "Value myList = ";
            while (itSt != itFin) {
                std::cout << "|" << *itSt << "| ";
                itSt++;
            }
            std::cout << "\n";

            ft::list<std::string> myList2;
            myList2.push_back("hello");
            myList2.push_back("world");
            myList2.push_back("school");
            myList2.push_back("21");

            myList.sort();
            myList2.sort();
            myList.merge(myList2);
            itSt = myList.begin();
            itFin = myList.end();
            std::cout << "Size myList after merge = " << myList.size() << "\n";
            std::cout << "Value myList = ";
            while (itSt != itFin) {
                std::cout << "|" << *itSt << "| ";
                itSt++;
            }
            std::cout << "\n";

            itSt = myList2.begin();
            itFin = myList2.end();
            std::cout << "Size myList2 after merge = " << myList2.size() << "\n";
            std::cout << "Value myList2 = ";
            while (itSt != itFin) {
                std::cout << "|" << *itSt << "| ";
                itSt++;
            }
            std::cout << "\n";


            ft::list<double> first1, second1;
            first1.push_back (3.1);
            first1.push_back (2.2);
            first1.push_back (2.9);

            second1.push_back (3.7);
            second1.push_back (7.1);
            second1.push_back (1.4);

            first1.sort();
            second1.sort();
            first1.merge(second1);
            std::cout << "Size first after merge = " << first1.size() << "\n";
            std::cout << "Value myList = ";
            for (ft::list<double>::iterator it=first1.begin(); it!=first1.end(); ++it)
                std::cout << ' ' << *it;
            std::cout << '\n';

            second1.push_back (2.1);
            first1.merge(second1,mycomparison);

            std::cout << "Size first after merge compare = " << first1.size() << "\n";
            std::cout << "Value myList = ";
            for (ft::list<double>::iterator it=first1.begin(); it!=first1.end(); ++it)
                std::cout << ' ' << *it;
            std::cout << '\n';


            std::cout << Y"\nOriginal sort, merge and reverse\n"D;


            std::list<std::string> origList;
            origList.push_back("one");
            origList.push_back("two");
            origList.push_back("Three");
            origList.push_back("four");
            origList.sort();
            std::list<std::string>::iterator itSt0 = origList.begin();
            std::list<std::string>::iterator itFin0 = origList.end();
            std::cout << "Size origList after sort= " << origList.size() << "\n";
            std::cout << "Value origList = ";
            while (itSt0 != itFin0) {
                std::cout << "|" << *itSt0 << "| ";
                itSt0++;
            }
            std::cout << "\n";

            origList.sort(compare_nocase);

            itSt0 = origList.begin();
            itFin0 = origList.end();
            std::cout << "Size origList after sort compare = " << origList.size() << "\n";
            std::cout << "Value origList = ";
            while (itSt0 != itFin0) {
                std::cout << "|" << *itSt0 << "| ";
                itSt0++;
            }
            std::cout << "\n";

            origList.reverse();
            itSt0 = origList.begin();
            itFin0 = origList.end();
            std::cout << "Size origList after reverse = " << origList.size() << "\n";
            std::cout << "Value origList = ";
            while (itSt0 != itFin0) {
                std::cout << "|" << *itSt0 << "| ";
                itSt0++;
            }
            std::cout << "\n";

            std::list<std::string> origList2;
            origList2.push_back("hello");
            origList2.push_back("world");
            origList2.push_back("school");
            origList2.push_back("21");

            origList.sort();
            origList2.sort();
            origList.merge(origList2);
            itSt0 = origList.begin();
            itFin0 = origList.end();
            std::cout << "Size origList after merge = " << origList.size() << "\n";
            std::cout << "Value origList = ";
            while (itSt0 != itFin0) {
                std::cout << "|" << *itSt0 << "| ";
                itSt0++;
            }
            std::cout << "\n";

            itSt0 = origList2.begin();
            itFin0 = origList2.end();
            std::cout << "Size origList2 after merge = " << origList2.size() << "\n";
            std::cout << "Value origList2 = ";
            while (itSt0 != itFin0) {
                std::cout << "|" << *itSt0 << "| ";
                itSt0++;
            }
            std::cout << "\n";

            origList2.push_back("22");

            std::list<double> first, second;
            first.push_back (3.1);
            first.push_back (2.2);
            first.push_back (2.9);

            second.push_back (3.7);
            second.push_back (7.1);
            second.push_back (1.4);

            first.sort();
            second.sort();
            first.merge(second);
            std::cout << "Size first after merge  = " << first.size() << "\n";
            std::cout << "Value origList = ";
            for (std::list<double>::iterator it=first.begin(); it!=first.end(); ++it)
                std::cout << ' ' << *it;
            std::cout << '\n';
            second.push_back (2.1);
            first.merge(second,mycomparison);

            std::cout << "Size first after merge compare = " << first.size() << "\n";
            std::cout << "Value origList = ";
            for (std::list<double>::iterator it=first.begin(); it!=first.end(); ++it)
                std::cout << ' ' << *it;
            std::cout << '\n';
        }

        {
            {
                std::cout <<Y "My non-member function\n" D;

                ft::list<char> myList1(3,'3');
                ft::list<char> myList2(3,'a');
                std::cout << "'==' = " << (myList1 == myList2) << "\n";
                std::cout << "'!=' = " << (myList1 != myList2) << "\n";
                std::cout << "'>' = " << (myList1 > myList2) << "\n";
                std::cout << "'>=' = " << (myList1 >= myList2) << "\n";
                std::cout << "'<' = " << (myList1 < myList2) << "\n";
                std::cout << "'<=' = " << (myList1 == myList2) << "\n";
                myList1.swap(myList2);
                ft::list<char>::iterator itSt = myList1.begin();
                ft::list<char>::iterator itFin = myList1.end();
                std::cout << "Size myList after swap = " << myList1.size() << "\n";
                std::cout << "Value myList1 = ";
                while (itSt != itFin) {
                    std::cout << "|" << *itSt << "| ";
                    itSt++;
                }
                std::cout << "\n";
                itSt = myList2.begin();
                itFin = myList2.end();
                std::cout << "Value myList2 = ";
                while (itSt != itFin) {
                    std::cout << "|" << *itSt << "| ";
                    itSt++;
                }
                std::cout << "\n";



                std::cout <<Y "Original non-member function\n" D;

                std::list<char> origList1(3,'3');
                std::list<char> origList2(3,'a');
                std::cout << "'==' = " << (origList1 == origList2) << "\n";
                std::cout << "'!=' = " << (origList1 != origList2) << "\n";
                std::cout << "'>' = " << (origList1 > origList2) << "\n";
                std::cout << "'>=' = " << (origList1 >= origList2) << "\n";
                std::cout << "'<' = " << (origList1 < origList2) << "\n";
                std::cout << "'<=' = " << (origList1 == origList2) << "\n";
                origList1.swap(origList2);
                std::list<char>::iterator itSt0 = origList1.begin();
                std::list<char>::iterator itFin0 = origList1.end();
                std::cout << "Size origList after swap = " << origList1.size() << "\n";
                std::cout << "Value origList = ";
                while (itSt0 != itFin0) {
                    std::cout << "|" << *itSt0 << "| ";
                    itSt0++;
                }
                std::cout << "\n";

                itSt0 = origList2.begin();
                itFin0 = origList2.end();
                std::cout << "Value origList2 = ";
                while (itSt0 != itFin0) {
                    std::cout << "|" << *itSt0 << "| ";
                    itSt0++;
                }
                std::cout << "\n";
            }
        }

        std::cout << Y"Now you can check memory leaks, with leaks a.out in other terminal" << D"\n";
        std::cout << G"To exit press Enter" << D"\n";
        getchar();
        std::cout << G"Good bye" << D"\n";
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

