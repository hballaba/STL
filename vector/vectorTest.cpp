#include "ft_vector.hpp"
#include <vector>

int     main() {
    try {


//   ft_vector<int> v1;
//   ft_vector<int>::iterator it;

   std::vector<int> v1;
   std::vector<int>::iterator it;



//    ft_vector<std::string> v2(5);

 //   std::vector<int> v1;
//    std::vector<std::string> v2(5);

    std::cout << v1.capacity() << std::endl;
    v1.push_back(7);
	v1.push_back(10);
	v1.push_back(20);
    v1.push_back(30);
    // std::cout << "test size = " << v1.size() << std::endl;
    // //v1.clear();
    // std::cout << "test resize = " << v1.size() << std::endl;
    
    // v1.resize(5, 5);
    // std::cout << "test resize. size = " << v1.size() << std::endl;
    // for (int i = 0; i < v1.size(); i++)
    //     std::cout << i << "= " << v1[i] << std::endl;
    // v1.reserve(20);
    // std::cout << "test resize. capasity = " << v1.capacity() << std::endl;
    
    // std::cout << "test resize. size = " << v1.size() << std::endl;
    
    // //std::cout << "at index = " << v1.at(5) << std::endl; // проверить на исключение
    // std::cout << "test resize. size = " << v1.size() << std::endl;
    // std::cout << "front index = " << v1.front() << std::endl;
    // std::cout << "back index = " << v1.back() << std::endl;
    // std::cout << "begin index = " << *v1.begin() << std::endl;
    // std::cout << "end index = " << *v1.end() << std::endl;
    // std::cout << "rbegin index = " << *v1.rbegin() << std::endl;
    // std::cout << "rend index = " << *v1.rend() << std::endl;

    
    // v1.assign(4, 5);
    std::cout << "test asign. size = " << v1.capacity() << std::endl;
    for (int i = 0; i < v1.size(); i++)
        std::cout << i << "= " << v1[i] << std::endl;

    
    

    it = v1.begin();
    it++;
    // it = v1.insert(it , 200);
    //v1.insert(it, 2, 300);

    // it++;
    // it++;
    // it = v1.insert(it, v1.begin(), v1.end());

    // std::cout << "test insert. size = " << v1.size() << std::endl;
    // std::cout << "test insert it = " << *it << std::endl;
    // for (int i = 0; i < v1.size(); i++)
    //     std::cout << i << " = " << v1[i] << std::endl;
    

    // it = v1.erase(it);
    // //it = v1.erase(it, v1.end());
    // std::cout << "test erase size = " << v1.size() << std::endl;
    // std::cout << "test erase it = " << *it << std::endl;
    // for (int i = 0; i < v1.size(); i++)
    //     std::cout << i << " = " << v1[i] << std::endl;
	std::cout << std::endl;
    
	ft_vector<int> v2, v3;
	//std::vector<int> v2, v3;

    // v2.resize(3, 1);
    // v3.resize(4, 9);
    // for (int i = 0; i < v2.size(); i++)
    //     std::cout << "v1 " << i << " = " << v2[i] << std::endl;
    // for (int i = 0; i < v3.size(); i++)
    //     std::cout << "v2 " << i << " = " << v3[i] << std::endl;

	// v2.swap(v3);
	// std::cout << std::endl;
	// for (int i = 0; i < v2.size(); i++)
    //     std::cout << "v1 " << i << " = " << v2[i] << std::endl;
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