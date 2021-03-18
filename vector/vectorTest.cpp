#include "vector.hpp"
#include <vector>
# define G "\e[92m\e[1m"
# define D "\e[39m\e[0m"
# define R "\e[91m"
# define Y "\e[93m"

int     main() {
    try {
    				/****** CONSTRUCTOR  ********/

    	{
			std::cout <<Y "My constructor\n" D;
			ft::vector<int> myVector;
			std::cout << "Default construct, size = " << myVector.size();
			std::cout << "   capacity = " << myVector.capacity() << "\n";
			ft::vector<int> myVector2(5);
			std::cout << "Construct with n elements, size = " << myVector2.size();
			std::cout << "   capacity = " << myVector2.capacity() << "\n";
			myVector2.push_back(5);
			ft::vector<int> myVector3(myVector2);
			std::cout << "Copy constructor, size = " << myVector3.size();
			std::cout << "   capacity = " << myVector3.capacity() << "\n";
			//std::cout << "Range constructor, size = " << myVector3.size();
			
			std::cout << Y"\nOriginal constructor\n"D;
			std::vector<int> original;
			std::cout << "Default construct, size = " << original.size();
			std::cout << "   capacity = " << original.capacity() << "\n";
			std::vector<int> original2(5);
			std::cout << "Construct with n elements, size = " << original2.size();
			std::cout << "   capacity = " << original2.capacity() << "\n";
			ft::vector<int> yVector3(myVector2);
			std::cout << "Copy constructor, ize = " << myVector3.size();
			std::cout << "   capacity = " << myVector3.capacity() << "\n\n";
			//std::cout << "Range constructor, size = " << myVector3.size();

		}
						/****** OPERATOR =  ********/
		{
			std::cout <<Y "My operator =\n" D;
			std::vector<int> Myvector;
			Myvector.push_back(123);
			Myvector.push_back(456);
			std::vector<int> Myvector2 = Myvector;    // =
			for (int i = 0; i < Myvector2.size(); i++)
				std::cout << i << " = " << Myvector2[i] << std::endl;

			std::cout <<Y "Original operator =\n" D;
			std::vector<int> original;
			original.push_back(123);
			original.push_back(456);
			std::vector<int> original2 = original;    // =
			for (int i = 0; i < original2.size(); i++)
				std::cout << i << " = " << original2[i] << std::endl;
		}

					/****** Iterator ********/

		{
			std::cout <<Y "My iterator\n" D;
			ft::vector<int>::iterator  myIT;
			ft::vector<int>::iterator  myITend;
			ft::vector<int> myVector;
			for(int i = 0; i < 10; i+=2)
				myVector.push_back(i);
			myIT = myVector.begin();
			myITend = myVector.end();
//			std::cout << "iterator begin = " << *myIT << std::endl;
//			std::cout << "iterator end = " << *myITend << std::endl;
			//std::cout << "iterator end - 1 = " << *(myITend - 1) << std::endl;
			while(myIT != myITend ) {
				std::cout << *myIT << "\n";
				myIT++;
			}
//			ft::vector<int>::const_iterator  myIT;
//			ft::vector<int>::const_iterator  myITend;
//			myIT = myVector.cbegin();

			std::cout <<Y "Original iterator\n" D;

			std::vector<int>::iterator originalIT;
			std::vector<int>::iterator originalITend;
			std::vector<int> originalVector;
			for(int i = 0; i < 10; i+=2)
				originalVector.push_back(i);
			originalIT = originalVector.begin();
			originalITend = originalVector.end();
//			std::cout << "iterator begin = " << *originalIT << std::endl;
//			std::cout << "iterator end = " << *originalITend << std::endl;
//			std::cout << "iterator end - 1 = " << *(originalITend - 1) << std::endl;
			while(originalIT != originalITend ) {
				std::cout << *originalIT << "\n";
				originalIT++;
			}

			std::vector<int>::const_iterator  constOriginalIT;
			std::vector<int>::const_iterator  constOriginalITend;
			constOriginalIT = originalVector.cbegin();
			constOriginalITend = originalVector.end();
			while(constOriginalIT != constOriginalITend ) {
				std::cout << *constOriginalIT << "\n";
				constOriginalIT++;
			}
		}
				



//    	{
//			std::cout << "\nMy vector\n";
//
//			ft::vector<std::string> myVector;
//			myVector.push_back("0");
//			myVector.push_back("1");
//			myVector.push_back("2");
//			myVector.push_back("3");
//			for (int i = 0; i < myVector.size(); i++)
//				std::cout << i << " = " << myVector[i] << std::endl;
//
//		std::cout << "Original vector\n";
//			std::vector<std::string> original;
//			original.push_back("0");
//			original.push_back("1");
//			original.push_back("2");
//			original.push_back("3");
//			for (int i = 0; i < original.size(); i++)
//				std::cout << i << " = " << original[i] << std::endl;
//		}

	}
	catch(const char * e)
	{
		std::cerr << e << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}




		//    vector<std::string> v2(5);

		//   std::vector<int> originalVec1;
		//    std::vector<std::string> v2(5);

		//std::cout << myVec1.capacity() << std::endl;
//		myVec1.push_back("sf");
//		myVec1.push_back("sdf");
//		myVec1.push_back("sdff");
//		myVec1.push_back("gdfgffg");
//
//		for (int i = 0; i < myVec1.size(); i++)
//			std::cout << i << "= " << myVec1[i] << std::endl;

			
		// std::cout << "test size = " << myVec1.size() << std::endl;
		// //myVec1.clear();
		// std::cout << "test resize = " << myVec1.size() << std::endl;
		
		// myVec1.resize(5, 5);
		// std::cout << "test resize. size = " << myVec1.size() << std::endl;
		// for (int i = 0; i < myVec1.size(); i++)
		//     std::cout << i << "= " << myVec1[i] << std::endl;
		// myVec1.reserve(20);
		// std::cout << "test resize. capasity = " << myVec1.capacity() << std::endl;
		
		// std::cout << "test resize. size = " << myVec1.size() << std::endl;
		
		// //std::cout << "at index = " << myVec1.at(5) << std::endl; // проверить на исключение
		// std::cout << "test resize. size = " << myVec1.size() << std::endl;
		// std::cout << "front index = " << myVec1.front() << std::endl;
		// std::cout << "back index = " << myVec1.back() << std::endl;
		// std::cout << "begin index = " << *myVec1.begin() << std::endl;
		// std::cout << "end index = " << *myVec1.end() << std::endl;
		// std::cout << "rbegin index = " << *myVec1.rbegin() << std::endl;
		// std::cout << "rend index = " << *myVec1.rend() << std::endl;

		
		// myVec1.assign(4, 5);
		//std::cout << "test capacyty = " << myVector.capacity() << std::endl;
//		for (int i = 0; i < myVec1.size(); i++)
//			std::cout << i << "= " << myVec1[i] << std::endl;

		
		

//		myIt = myVec1.begin();
//		myIt++;
		// it = myVec1.insert(it , 200);
		//myVec1.insert(it, 2, 300);

		// it++;
		// it++;
		// it = myVec1.insert(it, myVec1.begin(), myVec1.end());

		// std::cout << "test insert. size = " << myVec1.size() << std::endl;
		// std::cout << "test insert it = " << *it << std::endl;
		// for (int i = 0; i < myVec1.size(); i++)
		//     std::cout << i << " = " << myVec1[i] << std::endl;
		

		// it = myVec1.erase(it);
		// //it = myVec1.erase(it, myVec1.end());
		// std::cout << "test erase size = " << myVec1.size() << std::endl;
		// std::cout << "test erase it = " << *it << std::endl;
		// for (int i = 0; i < myVec1.size(); i++)
		//     std::cout << i << " = " << myVec1[i] << std::endl;
//		std::cout << std::endl;
//
//		ft::vector<int> v2, v3;
		//std::vector<int> v2, v3;

		// v2.resize(3, 1);
		// v3.resize(4, 9);
		// for (int i = 0; i < v2.size(); i++)
		//     std::cout << "myVec1 " << i << " = " << v2[i] << std::endl;
		// for (int i = 0; i < v3.size(); i++)
		//     std::cout << "v2 " << i << " = " << v3[i] << std::endl;

		// v2.swap(v3);
		// std::cout << std::endl;
		// for (int i = 0; i < v2.size(); i++)
		//     std::cout << "myVec1 " << i << " = " << v2[i] << std::endl;
		// for (int i = 0; i < v3.size(); i++)
		//     std::cout << "v2 " << i << " = " << v3[i] << std::endl;

		//std::cout << "v2 " <<  " = " << v2.max_size()  << std::endl;

		// v2.push_back("sdff");
		// std::cout << v2.size() << std::endl;
		// v2.push_back("sdff");
		// std::cout << v2.size() << std::endl;
		// std::cout << v2[1] << std::endl;
		// std::cout << v2[5] << std::endl;
		// std::cout << v2[8] << std::endl;





//}
//catch(const char * e)
//{
//    std::cerr << e << '\n';
//}
//catch(const std::exception& e)
//{
//    std::cerr << e.what() << '\n';
//}



	// ft::vector<ft::vector<std::string> > a1;
	// 		a1.push_back(myVector);
	// 		ft::vector<std::string> myVector2 = a1[0];
	// 		for (int i = 0; i < myVector2.size(); i++)
	// 			std::cout << i << " = " << myVector2[i] << std::endl;

    return 0;
}