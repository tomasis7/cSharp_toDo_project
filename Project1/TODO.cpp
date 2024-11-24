#include <iostream>
#include <vector>
#include <string>

// Class to represent a TODO item
class TodoItem {
public:
    TodoItem(const std::string& description) : description(description), completed(false) {}

    void markCompleted() {
        completed = true;
    }

    std::string getDescription() const {
        return description;
    }

    bool isCompleted() const {
        return completed;
    }

private:
    std::string description;
    bool completed;
};

// Class to manage the list of TODO items
class TodoList {
public:
    void addItem(const std::string& description) {
        items.push_back(TodoItem(description));
    }

    void markItemCompleted(int index) {
        if (index >= 0 && index < items.size()) {
            items[index].markCompleted();
        }
        else {
            std::cerr << "Invalid index\n";
        }
    }

    void printItems() const {
        for (size_t i = 0; i < items.size(); ++i) {
            std::cout << (items[i].isCompleted() ? "[x] " : "[ ] ") << items[i].getDescription() << "\n";
        }
    }

private:
    std::vector<TodoItem> items;
};

int main() {
    TodoList todoList;
    int choice;
    std::string description;
    int index;

    while (true) {
        std::cout << "1. Add TODO item\n";
        std::cout << "2. Mark TODO item as completed\n";
        std::cout << "3. Show TODO list\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter description: ";
            std::cin.ignore();
            std::getline(std::cin, description);
            todoList.addItem(description);
            break;
        case 2:
            std::cout << "Enter item index to mark as completed: ";
            std::cin >> index;
            todoList.markItemCompleted(index - 1); // Convert to zero-based index
            break;
        case 3:
            todoList.printItems();
            break;
        case 4:
            return 0;
        default:
            std::cerr << "Invalid choice\n";
        }
    }
}