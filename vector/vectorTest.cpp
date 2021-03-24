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

			ft::vector<int> myVector1;
			std::cout << "Default construct, size = " << myVector1.size();
			std::cout << "   capacity = " << myVector1.capacity() << "\n";

			ft::vector<int> myVector2(5);
			std::cout << "Construct with n elements, size = " << myVector2.size();
			std::cout << "   capacity = " << myVector2.capacity() << "\n";
			myVector2.push_back(5);
            for (int i = 0; i < myVector2.size(); i++)
                std::cout << "index " << i << " = " << myVector2[i] << "\n";

            ft::vector<int> myVector2a(4, 100);
            std::cout << "Construct with n elements and value 100, size = " << myVector2a.size();
            std::cout << "   capacity = " << myVector2a.capacity() << "\n";
            for (int i = 0; i < myVector2a.size(); i++)
                std::cout << myVector2a[i] << "\n";
            myVector2a.push_back(222);
            myVector2a.push_back(333);



			ft::vector<int> myVector3(myVector2a.begin(), myVector2a.end());
			std::cout << "Range constructor, size = " << myVector3.size() << "\n";
            for (int i = 0; i < myVector3.size(); i++)
                std::cout << myVector3[i] << "\n";
            myVector2a.push_back(444);



			ft::vector<int> myVector4(myVector2a);
			std::cout << "Copy constructor, size = " << myVector4.size();
			std::cout << "   capacity = " << myVector4.capacity() << "\n";
            for (int i = 0; i < myVector4.size(); i++)
                std::cout << myVector4[i] << "\n";



			std::cout << Y"Original constructor\n"D;

			std::vector<int> original1;
			std::cout << "Default construct, size = " << original1.size();
			std::cout << "   capacity = " << original1.capacity() << "\n";

            std::vector<int> originalVector2(5);
            std::cout << "Construct with n elements, size = " << originalVector2.size();
            std::cout << "   capacity = " << originalVector2.capacity() << "\n";
            originalVector2.push_back(5);
            for (int i = 0; i < originalVector2.size(); i++)
                std::cout << "index " << i << " = " << originalVector2[i] << "\n";

            std::vector<int> originalVector2a(4, 100);
            std::cout << "Construct with n elements and value 100, size = " << originalVector2a.size();
            std::cout << "   capacity = " << originalVector2a.capacity() << "\n";
            for (int i = 0; i < originalVector2a.size(); i++)
                std::cout << originalVector2a[i] << "\n";
            originalVector2a.push_back(222);
            originalVector2a.push_back(333);

            std::vector<int> originalVector3(originalVector2a.begin(), originalVector2a.end());
            std::cout << "Range constructor, size = " << originalVector3.size() << "\n";
            for (int i = 0; i < originalVector3.size(); i++)
                std::cout << originalVector3[i] << "\n";
            originalVector2a.push_back(444);


            std::vector<int> originalVector4(originalVector2a);
            std::cout << "Copy constructor, size = " << originalVector4.size();
            std::cout << "   capacity = " << originalVector4.capacity() << "\n";
            for (int i = 0; i < originalVector4.size(); i++)
                std::cout << originalVector4[i] << "\n";
		}



						/****** OPERATOR =  ********/



		{
			std::cout <<Y "\nMy operator =\n" D;
			std::vector<int> Myvector;
			Myvector.push_back(123);
			Myvector.push_back(456);
			std::vector<int> Myvector2 = Myvector;
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


					/****** ITERATOR ********/



		{
			std::cout <<Y "\nMy iterator\n" D;
			ft::vector<int>::iterator  myIT;
			ft::vector<int>::iterator  myITend;
			ft::vector<int> myVector;
			for(int i = 0; i < 10; i+=2)
				myVector.push_back(i);
			myIT = myVector.begin();
			myITend = myVector.end();
			while(myIT != myITend ) {
				std::cout << "myIT = " << *myIT << "\n";
				myIT++;
			}
			myIT-=4;
			std::cout << "myIT_-4 = " << myIT[0] << "\n";
			myIT+=2;
			std::cout << "myIT_+2 = " << myIT[0] << "\n";
			
			
			ft::vector<int>::reverse_iterator myITReverse;
			ft::vector<int>::reverse_iterator myITendReverse;
            myITReverse = myVector.rbegin();
            myITendReverse = myVector.rend();
			while(myITReverse != myITendReverse) {
				std::cout << "myITReverse = " << *myITReverse << "\n";
                myITReverse++;
			}


			std::cout <<Y "Original iterator\n" D;

			std::vector<int>::iterator originalIT;
			std::vector<int>::iterator originalITend;
			std::vector<int> originalVector;
			for(int i = 0; i < 10; i+=2)
				originalVector.push_back(i);
			originalIT = originalVector.begin();
			originalITend = originalVector.end();
			while(originalIT != originalITend ) {
				std::cout << "OriginalIT = " << *originalIT << "\n";
				originalIT++;
			}
				originalIT-=4;
				std::cout << "OriginalIT_-4 = " << originalIT[0] << "\n";
				originalIT+=2;
				std::cout << "OriginalIT_+2 = " << originalIT[0] << "\n";


            std::vector<int>::reverse_iterator originalITReverse;
            std::vector<int>::reverse_iterator originalITEndReverse;
            originalITReverse = originalVector.rbegin();
            originalITEndReverse = originalVector.rend();
            while(originalITReverse != originalITEndReverse) {
                std::cout << "originalITReverse = " << *originalITReverse << "\n";
                originalITReverse++;
            }
		}


		            /*********  CAPASITY   **********/

        {
            std::cout <<Y "My capasity\n" D;

            ft::vector<int> myVector(5, 11);
            std::cout << "Size = " << myVector.size() << "\n";
            std::cout << "Max size = " << myVector.max_size() << "\n";
            myVector.resize(3);

            std::cout << "Size = " << myVector.size() << "\n";
            std::cout << "Capacity = " << myVector.capacity() << "\n";
            myVector.resize(6, 44);
            std::cout << "Size = " << myVector.size() << "\n";
            std::cout << "Capacity = " << myVector.capacity() << "\n";
            for (int i = 0; i < myVector.size(); i++)
                std::cout << myVector[i] << "\n";
            std::cout << "myVector empty = " << myVector.empty() << "\n";
            ft::vector<int> newMy;
            std::cout << "newMy empty = " << newMy.empty() << "\n";
            myVector.reserve(15);
            std::cout << "Size = " << myVector.size() << "\n";
            std::cout << "Capacity = " << myVector.capacity() << "\n";
            for (int i = 0; i < myVector.size(); i++)
                std::cout << myVector[i] << "\n";




            std::cout <<Y "Original capasity\n" D;


            std::vector<int> originalVector(5, 11);
            std::cout << "Size = " << originalVector.size() << "\n";
            std::cout << "Max size = " << originalVector.max_size() << "\n";
            originalVector.resize(3);
            std::cout << "Size = " << originalVector.size() << "\n";
            std::cout << "Capacity = " << originalVector.capacity() << "\n";
            originalVector.resize(6, 44);
            std::cout << "Size = " << originalVector.size() << "\n";
            std::cout << "Capacity = " << originalVector.capacity() << "\n";
            for (int i = 0; i < originalVector.size(); i++)
                std::cout << originalVector[i] << "\n";
            std::cout << "originalVector empty = " << originalVector.empty() << "\n";
            std::vector<int> newOriginal;
            std::cout << "newOriginal empty = " << newOriginal.empty() << "\n";
            originalVector.reserve(15);
            std::cout << "Size = " << originalVector.size() << "\n";
            std::cout << "Capacity = " << originalVector.capacity() << "\n";
            for (int i = 0; i < originalVector.size(); i++)
                std::cout << originalVector[i] << "\n";
        }


                /*********  ELEMENT ACCESS   *********/

        {

            std::cout <<Y "My element access\n" D;
            ft::vector<char> myVector(1, 'a');
            myVector.push_back('b');
            myVector.push_back('c');
            myVector.push_back('d');
            std::cout << "index 2 = " << myVector[2] << '\n';
            std::cout << "index 5 = " << myVector[5] << '\n';
            std::cout << "index at 1 = " << myVector.at(1) << '\n';
            //std::cout << "index at 5 = " << myVector.at(5) << '\n';
            std::cout << "my front = " << myVector.front() << '\n';
            std::cout << "my back = " << myVector.back() << '\n';


            std::cout <<Y "Original element access\n" D;

            std::vector<char> originalVector(1, 'a');
            originalVector.push_back('b');
            originalVector.push_back('c');
            originalVector.push_back('d');
            std::cout << "index 2 = " << originalVector[2] << '\n';
            std::cout << "index 5 = " << originalVector[5] << '\n';
            std::cout << "index at 1 = " << originalVector.at(1) << '\n';
            //std::cout << "index at 5 = " << originalVector.at(5) << '\n';
            std::cout << "original front = " << originalVector.front() << '\n';
            std::cout << "original back = " << originalVector.back() << '\n';
        }


                        /******** MODIFIERS   ************/

        {

            std::cout << G "\nAssign\n"D;

            std::cout << Y "My assign\n" D;

            ft::vector<char> myVector(2, 'a');
            myVector.assign(5, 'b');
            std::cout << "Size = " << myVector.size() << "\n";
            std::cout << "Capacity = " << myVector.capacity() << "\n";
            for (int i = 0; i < myVector.size(); i++)
                std::cout << myVector[i] << "\n";
            myVector.assign(3, 'c');
            std::cout << "Size = " << myVector.size() << "\n";
            std::cout << "Capacity = " << myVector.capacity() << "\n";
            for (int i = 0; i < myVector.size(); i++)
                std::cout << myVector[i] << "\n";
            ft::vector<int> my2, my3;
            for (int i = 0; i < 10; i++)
                my2.push_back(i);
            my3.assign(my2.begin() + 2, my2.end() - 2);
            std::cout << "Size = " << my3.size() << "\n";
            std::cout << "Capacity = " << my3.capacity() << "\n";
            for (int i = 0; i < my3.size(); i++)
                std::cout << my3[i] << "\n";


            std::cout << Y "Original assign\n" D;


            std::vector<char> originalVector(2, 'a');
            originalVector.assign(5, 'b');
            std::cout << "Size = " << originalVector.size() << "\n";
            std::cout << "Capacity = " << originalVector.capacity() << "\n";
            for (int i = 0; i < originalVector.size(); i++)
                std::cout << originalVector[i] << "\n";
            originalVector.assign(3, 'c');
            std::cout << "Size = " << originalVector.size() << "\n";
            std::cout << "Capacity = " << originalVector.capacity() << "\n";
            for (int i = 0; i < originalVector.size(); i++)
                std::cout << originalVector[i] << "\n";
            std::vector<int> original2, original3;
            for (int i = 0; i < 10; i++)
                original2.push_back(i);
            original3.assign(original2.begin() + 2, original2.end() - 2);
            std::cout << "Size = " << original3.size() << "\n";
            std::cout << "Capacity = " << original3.capacity() << "\n";
            for (int i = 0; i < original3.size(); i++)
                std::cout << original3[i] << "\n";


            std::cout << G "\npush_back\n"D;

            std::cout << Y "my push_back\n" D;

            ft::vector<double> myVec;
            myVec.push_back(45.456);
            myVec.push_back(-45.456);
            myVec.push_back(0);
            myVec.push_back(123456789.123456789);
            myVec.push_back(-123456789.123456789);
            std::cout << "Size = " << myVec.size() << "\n";
            std::cout << "Capacity = " << myVec.capacity() << "\n";
            for (int i = 0; i < myVec.size(); i++)
                std::cout << myVec[i] << "\n";

            std::cout << Y "Original push_back\n" D;
            std::vector<double> origVec;
            origVec.push_back(45.456);
            origVec.push_back(-45.456);
            origVec.push_back(0);
            origVec.push_back(123456789.123456789);
            origVec.push_back(-123456789.123456789);
            std::cout << "Size = " << origVec.size() << "\n";
            std::cout << "Capacity = " << origVec.capacity() << "\n";
            for (int i = 0; i < origVec.size(); i++)
                std::cout << origVec[i] << "\n";


            std::cout << G "\npop_back\n"D;

            std::cout << Y "my pop_back\n" D;

            myVec.pop_back();
            myVec.pop_back();
            std::cout << "Size = " << myVec.size() << "\n";
            std::cout << "Capacity = " << myVec.capacity() << "\n";
            for (int i = 0; i < myVec.size(); i++)
                std::cout << myVec[i] << "\n";


            std::cout << Y "Original pop_back\n" D;

            origVec.pop_back();
            origVec.pop_back();
            std::cout << "Size = " << origVec.size() << "\n";
            std::cout << "Capacity = " << origVec.capacity() << "\n";
            for (int i = 0; i < origVec.size(); i++)
                std::cout << origVec[i] << "\n";


            std::cout << G "\nInsert\n"D;

            std::cout << Y "My insert\n" D;

            ft::vector<double>::iterator myIT;

            myVec.insert(myVec.begin() + 1, 4, 111.111);

            myIT = myVec.insert(myVec.begin() + 3, 222.222);

            std::cout << "Return value insert " << *myIT << "\n";


            std::cout << "Size = " << myVec.size() << "\n";
            std::cout << "Capacity = " << myVec.capacity() << "\n";
            for (int i = 0; i < myVec.size(); i++)
                std::cout << myVec[i] << "\n";

            ft::vector<double> other1(2, 555.555);
            myVec.insert(myVec.begin() + 1, other1.begin(), other1.end());

            std::cout << "Size = " << myVec.size() << "\n";
            std::cout << "Capacity = " << myVec.capacity() << "\n";
            for (int i = 0; i < myVec.size(); i++)
                std::cout << myVec[i] << "\n";


            std::cout << Y "Original insert\n" D;  //inserting new elements before the element at the specified position

            std::vector<double>::iterator origIT;
            origVec.insert(origVec.begin() + 1, 4, 111.111);

            origIT = origVec.insert(origVec.begin() + 3, 222.222);
            std::cout << "Return value insert " << *origIT << "\n";

            std::cout << "Size = " << origVec.size() << "\n";
            std::cout << "Capacity = " << origVec.capacity() << "\n";
            for (int i = 0; i < origVec.size(); i++)
                std::cout << origVec[i] << "\n";

            std::vector<double> other(2, 555.555);
            origVec.insert(origVec.begin() + 1, other.begin(), other.end());

            std::cout << "Size = " << origVec.size() << "\n";
            std::cout << "Capacity = " << origVec.capacity() << "\n";
            for (int i = 0; i < origVec.size(); i++)
                std::cout << origVec[i] << "\n";

        }


        {
            std::cout << G "\nErase\n"D;

            std::cout <<Y "My erase\n" D;

            ft::vector<float> myVec;
            for (int i = 0; i < 10; i++)
                myVec.push_back(i);
            std::cout << "Size = " << myVec.size() << "\n";
            std::cout << "Capacity = " << myVec.capacity() << "\n";
            for (int i = 0; i < myVec.size(); i++)
                std::cout << myVec[i] << " ";
            std::cout << "\n";
            myVec.erase(myVec.begin() + 5);
            myVec.erase(myVec.begin() + 1);
            std::cout << "Size = " << myVec.size() << "\n";
            std::cout << "Capacity = " << myVec.capacity() << "\n";
            for (int i = 0; i < myVec.size(); i++)
                std::cout << myVec[i] << " ";
            std::cout << "\n";
            myVec.erase(myVec.begin(), myVec.begin() + 3);
            std::cout << "Size = " << myVec.size() << "\n";
            std::cout << "Capacity = " << myVec.capacity() << "\n";
            for (int i = 0; i < myVec.size(); i++)
                std::cout << myVec[i] << " ";
            std::cout << "\n";






            std::cout <<Y "Original erese\n" D;

            std::vector<float> origVec;
            for (int i = 0; i < 10; i++)
                origVec.push_back(i);
            std::cout << "Size = " << origVec.size() << "\n";
            std::cout << "Capacity = " << origVec.capacity() << "\n";
            for (int i = 0; i < origVec.size(); i++)
                std::cout << origVec[i] << " ";
            std::cout << "\n";
            origVec.erase(origVec.begin() + 5);
            origVec.erase(origVec.begin() + 1);
            std::cout << "Size = " << origVec.size() << "\n";
            std::cout << "Capacity = " << origVec.capacity() << "\n";
            for (int i = 0; i < origVec.size(); i++)
                std::cout << origVec[i] << " ";
            std::cout << "\n";
            origVec.erase(origVec.begin(), origVec.begin() + 3);
            std::cout << "Size = " << origVec.size() << "\n";
            std::cout << "Capacity = " << origVec.capacity() << "\n";
            for (int i = 0; i < origVec.size(); i++)
                std::cout << origVec[i] << " ";
            std::cout << "\n";




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