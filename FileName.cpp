#include <iostream>

void show_el(int* array) {
	for (int i = 0; i < 50; i++) {
		std::cout << array[i] << " ";
	}
}

void delete_storage_int(int* array) { 
	delete[] array;
	array = 0;
	std::cout << "Storage is empty" << std::endl;
}

void delete_storage_long(long* array) {
	delete[] array;
	array = 0;
	std::cout << "Storage is empty" << std::endl;
}

void find_pair(int* array, int array_size, int num) {
	for (int i = 0; i < array_size; i++) {
		for (int j = i + 1; j < array_size; j++) {
			if (array[i] + array[j] == num) {
				std::cout << array[i] << " " << array[j] << std::endl;
			}
		}
	}
}

int add_new(int& length, long*& phone, long new_phone) {
	long* new_array = new long[length + 1];

	for (int i = 0; i < length + 1; i++) {
		new_array[i] = phone[i];
	}
	new_array[length + 1] = new_phone;
	length++;

	delete[] phone;
	phone = new_array;

	return 0;
}

int delete_number(int& length, long*& phone, long index) {
	for (long i = index; i < length; ++i) {
		phone[i] = phone[i - 1];
		--length;
	}
	return 0;
}

int update_number(int& length, long*& phone, long index) {
	long new_number = 0;
	std::cout << "Enter new number" << std::endl;
	std::cin >> new_number;

	phone[index] = new_number;
	
	return 0;
}

int show_all(int& length, long*& phone, long a) {
	for (int i = 0; i < length; i++) {
		std::cout << phone[i] << std::endl;
	}
	return 0;
}

int main() {

	//Task 1
	std::cout << "Task 1" << std::endl << std::endl;
	int* array1 = new int [50];

	int num1 = 0;

	for (int i = 0; i < 50; i++) {
		array1[i] = i+1;
	}

	show_el(array1);
	std::cout << std::endl;

	std::cout << "Enter the number" << std::endl;
	std::cin >> num1;

	find_pair(array1, 50, num1);

	delete_storage_int(array1);


	//Task 2
	std::cout << std::endl << "Task 2" << std::endl << std::endl;
	int a = 0;
	int length = 0;

	long* phone = new long[length];

	std::cout << "Enter: 1 - add new; 2 - delete; 3 - update; 4 - show all" << std::endl;
	std::cin >> a;

	int (*fncPtr)(int&, long*&, long) = nullptr;
	int fncOutput = NULL;
	int ind = -1;
	long new_number = 0;

	while (a == 1 || a == 2 || a == 3 || a == 4) {
		switch (a) {
		case 1: 
			std::cout << "Enter new number" << std::endl;
			std::cin >> new_number;
			fncPtr = add_new;
			fncOutput = fncPtr(length,phone,new_number);
			std::cout << fncOutput << std::endl;

			std::cout << "Enter the number of operation" << std::endl;
			std::cin >> a;
			break;
		
		case 2:
			std::cout << "Enter index of the phone number to be deleted" << std::endl;
			std::cin >> ind;
			fncPtr = delete_number;
			fncOutput = fncPtr(length, phone, new_number);
			std::cout << fncOutput << std::endl;

			std::cout << "Enter the number of operation" << std::endl;
			std::cin >> a;
			break;

		case 3:
			std::cout << "Enter index of the phone number to be updated" << std::endl;
			std::cin >> ind;

			fncPtr = update_number;
			fncOutput = fncPtr(length, phone, ind);
			std::cout << fncOutput << std::endl;

			std::cout << "Enter the number of operation" << std::endl;
			std::cin >> a;
			break;

		case 4:
			fncPtr = show_all;
			fncOutput = fncPtr(length, phone, 1);
			std::cout << fncOutput << std::endl;

			std::cout << "Enter the number of operation" << std::endl;
			std::cin >> a;
			break;
		}

	}

	delete_storage_long(phone);

	return 0;
}