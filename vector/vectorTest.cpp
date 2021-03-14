#include "vector.hpp"
#include <vector>

int     main() {
    try {


	vector<int> myVec1;
	vector<int>::iterator myIt;

	std::vector<int> originalVec1;
	std::vector<int>::iterator originalIt;



	//    vector<std::string> v2(5);

	//   std::vector<int> originalVec1;
	//    std::vector<std::string> v2(5);

		std::cout << myVec1.capacity() << std::endl;
		myVec1.push_back(7);
		myVec1.push_back(10);
		myVec1.push_back(20);
		myVec1.push_back(30);
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
		std::cout << "test asign. size = " << myVec1.capacity() << std::endl;
		for (int i = 0; i < myVec1.size(); i++)
			std::cout << i << "= " << myVec1[i] << std::endl;

		
		

		it = myVec1.begin();
		it++;
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
		std::cout << std::endl;
		
		vector<int> v2, v3;
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

		std::cout << "v2 " <<  " = " << v2.max_size()  << std::endl;

		// v2.push_back("sdff");
		// std::cout << v2.size() << std::endl;
		// v2.push_back("sdff");
		// std::cout << v2.size() << std::endl;
		// std::cout << v2[1] << std::endl;
		// std::cout << v2[5] << std::endl;
		// std::cout << v2[8] << std::endl;





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