#include "queue.hpp"
#include <queue>
#include <list>
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

            std::deque<int> mydeck (3,100);        // deque with 3 elements
            std::list<int> mylist (2,200);         // list with 2 elements

            ft::queue<int> first1;                 // empty queue
            ft::queue<int, std::deque<int> > second1 (mydeck);       // queue initialized to copy of deque

            ft::queue<int,std::list<int> > third1; // empty queue with list as underlying container
            ft::queue<int,std::list<int> > fourth1 (mylist);

            std::cout << "size of first: " << first1.size() << '\n';
            std::cout << "size of second: " << second1.size() << '\n';
            std::cout << "size of third: " << third1.size() << '\n';
            std::cout << "size of fourth: " << fourth1.size() << '\n';


            std::cout << Y"Original constructor\n"D;

            std::deque<int> origdeck (3,100);        // deque with 3 elements
            std::list<int> origlist (2,200);         // list with 2 elements

            std::queue<int> first;                 // empty queue
            std::queue<int> second (origdeck);       // queue initialized to copy of deque

            std::queue<int,std::list<int> > third; // empty queue with list as underlying container
            std::queue<int,std::list<int> > fourth (origlist);

            std::cout << "size of first: " << first.size() << '\n';
            std::cout << "size of second: " << second.size() << '\n';
            std::cout << "size of third: " << third.size() << '\n';
            std::cout << "size of fourth: " << fourth.size() << '\n';

        }

        {
            std::cout << Y"\nMy member function\n"D;

            std::queue<std::string> myQueue;          
            myQueue.push("Hello");
            myQueue.push("World");
            myQueue.push("!!!");
            std::cout << "size of myQueue: " <<  myQueue.size() << '\n';
            while(!myQueue.empty()) {
                std::cout << myQueue.front() << " ";
                myQueue.pop();
            }
            std::cout << "\n";
            std::cout << "size of myQueue: " <<  myQueue.size() << '\n';

            myQueue.push("Aer");
            myQueue.push("Terra");
            myQueue.push("Ignis");
            myQueue.push("Aqua");
            std::cout << "size of myQueue: " <<  myQueue.size() << '\n';
            while(!myQueue.empty()) {
                std::cout << myQueue.back() << " ";
                myQueue.pop();
            }
            std::cout << "\n";
            std::cout << "size of myQueue: " <<  myQueue.size() << '\n';



            std::cout << Y"Original member function\n"D;

            std::queue<std::string> origQueue;
            origQueue.push("Hello");
            origQueue.push("World");
            origQueue.push("!!!");
            std::cout << "size of origQueue: " <<  origQueue.size() << '\n';
            while(!origQueue.empty()) {
                std::cout << origQueue.front() << " ";
                origQueue.pop();
            }
            std::cout << "\n";
            std::cout << "size of origQueue: " <<  origQueue.size() << '\n';

            origQueue.push("Aer");
            origQueue.push("Terra");
            origQueue.push("Ignis");
            origQueue.push("Aqua");
            std::cout << "size of origQueue: " <<  origQueue.size() << '\n';
            while(!origQueue.empty()) {
                std::cout << origQueue.back() << " ";
                origQueue.pop();
            }
            std::cout << "\n";
            std::cout << "size of origQueue: " <<  origQueue.size() << '\n';


        }

        {
            std::cout <<Y "My non-member function\n" D;

            ft::queue<int> myQueue1;
            myQueue1.push(5);
            ft::queue<int> myQueue2;
            myQueue1.push(3);
            std::cout << "'==' = " << (myQueue1 == myQueue2) << "\n";
            std::cout << "'!=' = " << (myQueue1 != myQueue2) << "\n";
            std::cout << "'>' = " << (myQueue1 > myQueue2) << "\n";
            std::cout << "'>=' = " << (myQueue1 >= myQueue2) << "\n";
            std::cout << "'<' = " << (myQueue1 < myQueue2) << "\n";
            std::cout << "'<=' = " << (myQueue1 == myQueue2) << "\n";


            std::cout <<Y "Original non-member function\n" D;

            std::queue<int> origQueue1;
            origQueue1.push(5);
            std::queue<int> origQueue2;
            origQueue2.push(3);
            std::cout << "'==' = " << (origQueue1 == origQueue2) << "\n";
            std::cout << "'!=' = " << (origQueue1 != origQueue2) << "\n";
            std::cout << "'>' = " << (origQueue1 > origQueue2) << "\n";
            std::cout << "'>=' = " << (origQueue1 >= origQueue2) << "\n";
            std::cout << "'<' = " << (origQueue1 < origQueue2) << "\n";
            std::cout << "'<=' = " << (origQueue1 == origQueue2) << "\n";


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