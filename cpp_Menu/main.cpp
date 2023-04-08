#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include <limits>

#undef max

class menu 
{

private:
		std::vector<std::string> menuItems;

		void menuContent()
		{
			// Default console text
			std::cout << "1. Add Menu Items" << std::endl;
			std::cout << "2. Remove Menu Items" << std::endl;
			std::cout << "3. print All items name" << std::endl;
			std::cout << "4. exit" << std::endl;
			std::cout << "" << std::endl;
		}
		
		void addMenuItems()
		{
			// Items Name
			std::string items;

			// Get and Add items
			std::cout << "Input item name: ";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::getline(std::cin, items);
			menuItems.push_back(items);

			// Print items name
			std::cout << items << " added to menu" << std::endl;

			// DEBUG Use
			#ifdef DEBUG
				std::cout << "DEBUG: " << items << " added to menu" << std::endl;
			#endif 

		};

		void removeMenuItems()
		{
			// Check if the item list is empty
			if (!menuItems.empty())
			{
				menuItems.pop_back();

				std::cout << "menu Item removed" << std::endl;
			}
			else
			{
				std::cout << "List is Empty!" << std::endl;
			}
		};


		void printAllItems(const std::vector<std::string>& menuItems)
		{
			if (menuItems.empty())
			{
				std::cout << "There is nothing~ Adding something!" << std::endl;
			}
			else
			{
				for (int i = 0; i < menuItems.size(); i++)
				{
					std::cout << i + 1 << ". " << menuItems[i] << std::endl;
				}
			}
			
		
		};

		std::string GetLastErrorAsString()
		{
			//Get the error message ID, if any.
			DWORD errorMessageID = ::GetLastError();
			if (errorMessageID == 0) {
				return std::string(); //No error message has been recorded
			}

			LPSTR messageBuffer = nullptr;

			//Ask Win32 to give us the string version of that message ID.
			//The parameters we pass in, tell Win32 to create the buffer that holds the message for us (because we don't yet know how long the message string will be).
			size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
				NULL, errorMessageID, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&messageBuffer, 0, NULL);

			//Copy the error message into a std::string.
			std::string message(messageBuffer, size);

			//Free the Win32's string's buffer.
			LocalFree(messageBuffer);

			return message;

			// Ref: https://stackoverflow.com/questions/1387064/how-to-get-the-error-message-from-the-error-code-returned-by-getlasterror
		}

		void end()
		{
			std::cout << "Good Bye! See you next time." << std::endl;
			Sleep(1000);
			exit(0);
		}

	
		
public:
	
	void setMenuTitle()
	{
		std::string menuTitle;

		std::cout << "What name you want to set for the menu? " << std::endl;


		std::cout << "Menu Name: ";
		std::getline(std::cin, menuTitle);

		SetConsoleTitleA(menuTitle.c_str());

		std::cout << "Menu name Setted!" << std::endl;

		std::cout << "" << std::endl;

		Sleep(800);

		system("cls");

		#ifdef DEBUG
			std::cout << "DEBUG: [Title Name] -> " << menuTitle << std::endl;
		#endif // DEBUG

	}
	
	// main function
	void runMenu()
	{
		int choice;
		
		
	
		do
		{
			menuContent();
			// Get Choice from user
			std::cout << "Enter your choice: ";
			std::cin >> choice;

			switch (choice)
			{
				
			// Add items
			case 1:
				addMenuItems();
				Sleep(720);
				system("cls");
				break;
			
			// remove items
			case 2:
				removeMenuItems();
				Sleep(650);
				system("cls");
				break;
			
			// Print all items
			case 3:
				printAllItems(menuItems);
				Sleep(1500);
				system("cls");
				break;
				
			// exit 
			case 4:
				end();
				break;
				
			default:
				std::cerr << "Error: " << GetLastErrorAsString() << std::endl;
				break;
			}

		} while (choice != 4);
	}
};

int main()
{
	
	menu menu1;
	menu1.setMenuTitle();
	menu1.runMenu();

	system("pause > 0");
	return 0;
}