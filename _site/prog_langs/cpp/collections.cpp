#include<iostream>
#include<vector>
#include<array>

namespace collection_utilz
{
	void see_vector(){
		std::vector<int> data = {1,2,3};
		data.push_back(124);
		std::cout << data[data.size() - 1] << std::endl;
		
		// Remove from the end of the list
		data.pop_back();
		std::cout << data.size();
	
	}
	
	void see_STL_Arrays(){
		std::array <int,5> data = {1,2,3};
		std::cout << data[0] << std::endl;
	}
	
	int see_random()
	{
		int random = rand();
		std::cout << random << std::endl;
		std::cout << "Hello" << std::endl;
		return random;
	}
}
int main(){
	collection_utilz::see_random();
}
