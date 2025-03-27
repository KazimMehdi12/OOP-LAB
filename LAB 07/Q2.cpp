#include <iostream>
using namespace std;

class Product {
	public:
		int productID;
		string productName;
		float price;

		Product(int id, string name, float p) {
			productID = id;
			productName = name;
			price = p;
		}

		virtual void applyDiscount() {}

		virtual float calculateTotalPrice(int quantity) {
			return price * quantity;
		}

		virtual void displayProductInfo() {
			cout << "ID: " << productID << ", Name: " << productName << ", Price: " << price << endl;
		}
};

class Electronics : public Product {
	public:
		string brand;

		Electronics(int id, string name, float p, string b)
			: Product(id, name, p) {
			brand = b;
		}

		void displayProductInfo() {
			cout << "Electronics: " << productName << ", Brand: " << brand << ", Price: " << price << endl;
		}
};

class Clothing : public Product {
	public:
		string size;

		Clothing(int id, string name, float p, string s)
			: Product(id, name, p) {
			size = s;
		}

		void applyDiscount() {
			price = price * 0.9;
		}
};

class FoodItem : public Product {
	public:
		FoodItem(int id, string name, float p)
			: Product(id, name, p) {}

		float calculateTotalPrice(int quantity) {
			if (quantity >= 10) {
				return price * quantity * 0.9;
			}
			return price * quantity;
		}
};

class Book : public Product {
	public:
		string author;

		Book(int id, string name, float p, string a)
			: Product(id, name, p) {
			author = a;
		}

		void displayProductInfo() {
			cout << "Book: " << productName << ", Author: " << author << ", Price: " << price << endl;
		}
};

int main() {
	Electronics e(3, "Phone", 500, "Iphone");
	Clothing c(2, "Shirt", 89, "M");
	FoodItem f(4, "Bread", 3.5);
	Book b(4, "C++", 30, "XYZ");

	c.applyDiscount();

	e.displayProductInfo();
	c.displayProductInfo();
	b.displayProductInfo();

	float total = f.calculateTotalPrice(12);
	cout << "Total for 12 Breads: " << total << endl;

	return 0;
}
