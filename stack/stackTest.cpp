#include "stack.hpp"
#include <stack>
#include <vector>
#include <deque>

# define G "\e[92m\e[1m"
# define D "\e[39m\e[0m"
# define R "\e[91m"
# define Y "\e[93m"

int     main() {
    try {
        /****** CONSTRUCTOR  ********/
        {
            std::cout << Y "My constructor\n" D;

            std::deque<int> mydeque1 (3,100);          // deque with 3 elements
            std::vector<int> myvector1 (2,200);        // vector with 2 elements

            ft::stack<int> first1;                    // empty stack
            ft::stack<int, std::deque<int> > second1(mydeque1);         // stack initialized to copy of deque

            ft::stack<int,std::vector<int> > third1;  // empty stack using vector
            ft::stack<int,std::vector<int> > fourth1 (myvector1);

            std::cout << "size of first: " << first1.size() << '\n';
            std::cout << "size of second: " << second1.size() << '\n';
            std::cout << "size of third: " << third1.size() << '\n';
            std::cout << "size of fourth: " << fourth1.size() << '\n';


            std::cout << Y"Original constructor\n"D;

            std::deque<int> origdeque (3,100);          // deque with 3 elements
            std::vector<int> origvector (2,200);        // vector with 2 elements

            std::stack<int> first;                    // empty stack
            std::stack<int> second (origdeque);         // stack initialized to copy of deque

            std::stack<int,std::vector<int> > third;  // empty stack using vector
            std::stack<int,std::vector<int> > fourth (origvector);

            std::cout << "size of first: " << first.size() << '\n';
            std::cout << "size of second: " << second.size() << '\n';
            std::cout << "size of third: " << third.size() << '\n';
            std::cout << "size of fourth: " << fourth.size() << '\n';

        }


        {

            std::cout << Y"My member function\n"D;

            std::stack<char> myStack;
            std::cout << "myStack empty = " << myStack.empty() << std::endl;
            myStack.push('A');
            myStack.push('B');
            myStack.push('C');
            std::cout << "myStack empty = " << myStack.empty() << std::endl;
            std::cout << "size of myStack: " << myStack.size() << '\n';
            std::cout << "top =  " << myStack.top() << '\n';
            myStack.top() += 5;
            std::cout << "top =  " << myStack.top() << '\n';
            myStack.pop();
            std::cout << "After metod pop\n";
            std::cout << "size of myStack: " << myStack.size() << '\n';

            std::cout << "top =  " << myStack.top() << '\n';
            std::cout << "size of myStack: " << myStack.size() << '\n';


            std::cout << Y"Original member function\n"D;
            std::stack<char> origStack;
            std::cout << "origStack empty = " << origStack.empty() << std::endl;
            origStack.push('A');
            origStack.push('B');
            origStack.push('C');
            std::cout << "origStack empty = " << origStack.empty() << std::endl;
            std::cout << "size of origStack: " << origStack.size() << '\n';
            std::cout << "top =  " << origStack.top() << '\n';
            origStack.top() += 5;
            std::cout << "top =  " << origStack.top() << '\n';
            origStack.pop();
            std::cout << "After metod pop\n";
            std::cout << "size of origStack: " << origStack.size() << '\n';

            std::cout << "top =  " << origStack.top() << '\n';
            std::cout << "size of origStack: " << origStack.size() << '\n';
        }


        {
            std::cout <<Y "My non-member function\n" D;

            ft::stack<int> myStack1;
            myStack1.push(5);
            ft::stack<int> myStack2;
            myStack1.push(3);
            std::cout << "'==' = " << (myStack1 == myStack2) << "\n";
            std::cout << "'!=' = " << (myStack1 != myStack2) << "\n";
            std::cout << "'>' = " << (myStack1 > myStack2) << "\n";
            std::cout << "'>=' = " << (myStack1 >= myStack2) << "\n";
            std::cout << "'<' = " << (myStack1 < myStack2) << "\n";
            std::cout << "'<=' = " << (myStack1 == myStack2) << "\n";


            std::cout <<Y "Original non-member function\n" D;

            std::stack<int> origStack1;
            origStack1.push(5);
            std::stack<int> origStack2;
            origStack2.push(3);
            std::cout << "'==' = " << (origStack1 == origStack2) << "\n";
            std::cout << "'!=' = " << (origStack1 != origStack2) << "\n";
            std::cout << "'>' = " << (origStack1 > origStack2) << "\n";
            std::cout << "'>=' = " << (origStack1 >= origStack2) << "\n";
            std::cout << "'<' = " << (origStack1 < origStack2) << "\n";
            std::cout << "'<=' = " << (origStack1 == origStack2) << "\n";


            std::cout << Y"Now you can check memory leaks, with leaks a.out in other terminal" << D"\n";
            std::cout << G"To exit press Enter" << D"\n";
            getchar();
            std::cout << G"Good bye" << D"\n";

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