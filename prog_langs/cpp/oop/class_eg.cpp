#include <iostream>
#include <vector>

namespace class_eg
{
	class User
	{
		std::string status = "Gold";

		public:
			std::string first_name;
			std::string last_name;
			
			void set_status(std::string st){
				status = st;
			}
			std::string get_status(){
				return status;
			}

			friend void output_status(User user);

	};

	void output_status(User user)
	{
		std::cout << user.status << std::endl;
	}
	
	int add_user_if_not_exists(std::vector <User> &users, User user)
			// &user here so that we can directly modify the vector and add to it.
		{
			for(int i=0; i<users.size(); i++)
			{
				if(users[i].first_name == user.first_name &&
					users[i].last_name == user.last_name)
				{
					return i;
				}	
			}
			users.push_back(user);
			return users.size() - 1;
		}

	void class_eg_main()
	{
		User me;
		me.first_name = "Dhruv";
		me.last_name = "Jain";
		me.set_status("Yeet");	
		std::cout << me.first_name << " " << me.last_name << " " << me.get_status() << std::endl;
	}

	void class_eg_vector()
	{
		User user2;
		user2.first_name = "Dhru";
		
		std::vector <User> users;
		users.push_back(user2);
		std::cout << users[0].first_name << std::endl;

		users.push_back(User());
		std::cout << users[1].first_name << std::endl;
	}

	void add_user_if_not_exists_test()
	{
		std::vector <User> users2;
		User user3;
		user3.first_name = "Dhruv";
		user3.last_name = "Jain";
		User user4;
		user4.first_name = "Dhruv";
		user4.last_name = "Jain";
		std::cout << add_user_if_not_exists(users2, user3) << std::endl;
		std::cout << add_user_if_not_exists(users2, user4) << std::endl;
	}
}

namespace constructor_eg
{
	class User
	{
		std::string status;

		public:
			std::string first_name;
			std::string last_name;
			
			void set_status(std::string st)
			{
				status = st;
			}
			std::string get_status()
			{
				return status;
			}

			// Here comes the constructor magic
			/*User()
			{
				std::cout << "Hello from the constructor" << std::endl;
			}*/

			User(std::string fn ="John", std::string ln ="Doe")
			{
				std::cout << "Hello from the parameterized constructor" << std::endl;
				first_name = fn;
				last_name = ln;
			}

			~User()
			{
				std::cout << "Hello from the destructor" << std::endl;
			}
	
	};
}

class Teacher : public constructor_eg::User
{
	public:
		std::vector <std::string> classes_teaching;
		void output()
		{
			std::cout << " output " << std::endl;
		}
};

int main()
{
	Teacher t;
	t.output();
	return 0;
}
