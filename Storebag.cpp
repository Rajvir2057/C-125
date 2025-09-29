#include <iostream>
#include <string>

struct Node {
    std::string data;
    Node* next;

    Node(const std::string& value) : data(value), next(nullptr) {}
};

class Storebag {
protected:
    Node* head;

public:
    Storebag() : head(nullptr) {}

    void insert(const std::string& souvenir) {
        Node* newnode = new Node(souvenir);
        newnode->next = head;
        head = newnode;
    }

    std::string remove() {
        if (!head) return "";

        Node* temp = head;
        std::string value = head->data;
        head = head->next;
        delete temp;
        return value;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void display() const {
        Node* output = head;
        while (output) {
            std::cout << output->data << " ";
            output = output->next;
        }
        std::cout << std::endl;
    }
};

// Child classes
class Fragilebag : public Storebag {};
class Giftbag : public Storebag {};

int main() {
    Storebag bag;
    Fragilebag bag1;
    Giftbag bag2;

    // Insert items
    bag.insert("F_glass");
    bag.insert("X_cloth");

    // Separate items
    while (!bag.isEmpty()) {
        std::string storebag = bag.remove();
        if (storebag[0] == 'F') {
            bag1.insert(storebag);
        } else {
            bag2.insert(storebag);
        }
    }

    // Display
    std::cout << "Fragile Bag: ";
    bag1.display();

    std::cout << "Gift Bag: ";
    bag2.display();

    return 0;
}

