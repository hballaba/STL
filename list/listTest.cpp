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

            ft::list<char> myListElement(4,'C');
            std::cout << "Construct with n element, size = " << myListElement.size() << "\n";
            std::cout << "Front element = " << myListElement.front() << "\n";
            std::cout <<  "Back element = " << myListElement.back() << "\n";

            myListElement.push_back('Z');
            ft::list<char>::iterator myIT = myListElement.begin();
            //ft::list<char> myinalIterator(myIT, myListElement.end());
//            std::cout << "Construct with iterator, size = " << myinalIterator.size() << "\n";
//            std::cout << "Front element = " << myinalIterator.front() << "\n";
//            std::cout <<  "Back element = " << myinalIterator.back() << "\n";



            std::cout << Y"Original constructor\n"D;

            std::list<int> origListDefault;
            std::cout << "Default construct, size = " << origListDefault.size() << "\n";

            std::list<char> origListElement1(6);
            std::cout << "Construct with n element empty, size = " << origListElement1.size() << "\n";
            std::cout << "Front element = |" << origListElement1.front() << "|\n";

            std::list<char> origListElement(4,'C');
            std::cout << "Construct with n element, size = " << origListElement.size() << "\n";
            std::cout << "Front element = " << origListElement.front() << "\n";
            std::cout <<  "Back element = " << origListElement.back() << "\n";

            origListElement.push_back('Z');
            std::list<char>::iterator origIT = origListElement.begin();
            std::list<char> originalIterator(origIT, origListElement.end());
            std::cout << "Construct with iterator, size = " << originalIterator.size() << "\n";
            std::cout << "Front element = " << originalIterator.front() << "\n";
            std::cout <<  "Back element = " << originalIterator.back() << "\n";







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

