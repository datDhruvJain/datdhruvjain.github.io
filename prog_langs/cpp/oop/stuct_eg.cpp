#include <iostream>

namespace struct_eg
{
	struct User
	{
		std::string first_name;
		std::string last_name;
		
		void set_status(std::string st){
			status = st;
		}
		std::string get_status(){
			return status;
		}
	
		private:
			std::string status;
	};

	void struct_eg_main()
	{
		User me;
		me.first_name = "Dhruv";
		me.last_name = "Jain";
		me.set_status("Yeet");	
		std::cout << me.first_name << " " << me.last_name << " " << me.get_status() << std::endl;
	}
}

int main()
{
	struct_eg::struct_eg_main();
	return 0;
}
