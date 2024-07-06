#include <bits/stdc++.h>
using namespace std;

class Product {
private:
    int id;
    string name;
    int price;
    int quantity;

public:
    Product() : id(0), name(""), price(0), quantity(0) {}

    Product(int id, string name, int price, int quantity) {
        this->id = id;
        this->name = name;
        this->price = price;
        this->quantity = quantity;
    }

    void setId(int id) {
        this->id = id;
    }

    void setName(string name) {
        this->name = name;
    }

    void setPrice(int price) {
        this->price = price;
    }

    void setQuantity(int quantity) {
        this->quantity = quantity;
    }

    int getId() const {
        return id;
    }

    string getName() const {
        return name;
    }

    int getPrice() const {
        return price;
    }

    int getQuantity() const {
        return quantity;
    }
};

class Inventory {
private:
    vector<Product> products;

    int findProductIndex(int id) {
        for (int i = 0; i < products.size(); ++i) {
            if (products[i].getId() == id) {
                return i;
            }
        }
        return -1;
    }

public:
    void addProduct(int id, string name, int price, int quantity) {
        int index = findProductIndex(id);
        if (index != -1) {
            cout << "Product already exists. Updating quantity." << endl;
            products[index].setQuantity(products[index].getQuantity() + quantity);
        } else {
            Product p(id, name, price, quantity);
            products.push_back(p);
        }
    }

    void removeProduct(int id) {
        int index = findProductIndex(id);
        if (index != -1) {
            products.erase(products.begin() + index);
            cout << "Product removed." << endl;
        } else {
            cout << "Product not found." << endl;
        }
    }

    void updateProduct(int id, string name, int price, int quantity) {
        int index = findProductIndex(id);
        if (index != -1) {
            products[index].setName(name);
            products[index].setPrice(price);
            products[index].setQuantity(quantity);
        } else {
            cout << "Product not found." << endl;
        }
    }

    void updateQuantity(int id, int quantity) {
        int index = findProductIndex(id);
        if (index != -1) {
            products[index].setQuantity(products[index].getQuantity() + quantity);
        } else {
            cout << "Product not found." << endl;
        }
    }

    void updatePrice(int id, int price) {
        int index = findProductIndex(id);
        if (index != -1) {
            products[index].setPrice(price);
        } else {
            cout << "Product not found." << endl;
        }
    }

    void displayProducts() const {
        for (int i = 0; i < products.size(); ++i) {
            cout << "ID: " << products[i].getId() << endl;
            cout << "Name: " << products[i].getName() << endl;
            cout << "Price: " << products[i].getPrice() << endl;
            cout << "Quantity: " << products[i].getQuantity() << endl;
            cout << endl;
        }
    }
};

void displayMenu() {
    cout << "-----------------WELCOME TO INVENTORY MANAGEMENT SYSTEM-----------------" << endl;
    cout << "Choose an option:" << endl;
    cout << "1. Add a product" << endl;
    cout << "2. Remove a product" << endl;
    cout << "3. Update a product" << endl;
    cout << "4. Update quantity of a product" << endl;
    cout << "5. Update price of a product" << endl;
    cout << "6. Display all products" << endl;
    cout << "7. Exit" << endl;
    cout << "Note: Any invalid choice will exit the program.\n";
}

int main() {
    Inventory inv;
    int choice;

    do {
        displayMenu();
        cin >> choice;
        cin.ignore();  // To clear the newline character from the input buffer

        if (choice == 1) {
            int id, price, quantity;
            string name;
            cout << "Enter product ID: ";
            cin >> id;
            cin.ignore();  // To clear the newline character from the input buffer
            cout << "Enter product name: ";
            getline(cin, name);
            cout << "Enter product price: ";
            cin >> price;
            cout << "Enter product quantity: ";
            cin >> quantity;
            inv.addProduct(id, name, price, quantity);
        } else if (choice == 2) {
            int id;
            cout << "Enter product ID: ";
            cin >> id;
            inv.removeProduct(id);
        } else if (choice == 3) {
            int id, price, quantity;
            string name;
            cout << "Enter product ID: ";
            cin >> id;
            cin.ignore();  // To clear the newline character from the input buffer
            cout << "Enter product name: ";
            getline(cin, name);
            cout << "Enter product price: ";
            cin >> price;
            cout << "Enter product quantity: ";
            cin >> quantity;
            inv.updateProduct(id, name, price, quantity);
        } else if (choice == 4) {
            int id, quantity;
            cout << "Enter product ID: ";
            cin >> id;
            cout << "Enter quantity to be added: ";
            cin >> quantity;
            inv.updateQuantity(id, quantity);
        } else if (choice == 5) {
            int id, price;
            cout << "Enter product ID: ";
            cin >> id;
            cout << "Enter new price: ";
            cin >> price;
            inv.updatePrice(id, price);
        } else if (choice == 6) {
            inv.displayProducts();
        }
    } while (choice >= 1 && choice <= 6);

    cout << "-----------------THANK YOU FOR USING INVENTORY MANAGEMENT SYSTEM-----------------" << endl;
    return 0;
}

