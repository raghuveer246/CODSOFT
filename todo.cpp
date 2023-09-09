#include <iostream>
#include <vector>
#include <string>

class Task {
public:
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};

class TodoListManager {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& desc) {
        tasks.push_back(Task(desc));
        std::cout << "Task added: " << desc << std::endl;
    }

    void viewTasks() {
        if (tasks.empty()) {
            std::cout << "No tasks in the list." << std::endl;
        } else {
            std::cout << "Task List:" << std::endl;
            for (size_t i = 0; i < tasks.size(); ++i) {
                std::cout << i + 1 << ". ";
                if (tasks[i].completed) {
                    std::cout << "[Completed] ";
                }
                std::cout << tasks[i].description << std::endl;
            }
        }
    }

    void markTaskCompleted(int index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks[index - 1].completed = true;
            std::cout << "Task marked as completed: " << tasks[index - 1].description << std::endl;
        } else {
            std::cout << "Invalid task index." << std::endl;
        }
    }

    void removeTask(int index) {
        if (index >= 1 && index <= tasks.size()) {
            std::cout << "Task removed: " << tasks[index - 1].description << std::endl;
            tasks.erase(tasks.begin() + index - 1);
        } else {
            std::cout << "Invalid task index." << std::endl;
        }
    }
};

int main() {
    TodoListManager manager;
    int choice;

    do {
        std::cout << "To-Do List Manager\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cin.ignore();  // Clear the newline character
                std::cout << "Enter task description: ";
                std::string description;
                std::getline(std::cin, description);
                manager.addTask(description);
                break;
            }
            case 2:
                manager.viewTasks();
                break;
            case 3: {
                int index;
                std::cout << "Enter task index to mark as completed: ";
                std::cin >> index;
                manager.markTaskCompleted(index);
                break;
            }
            case 4: {
                int index;
                std::cout << "Enter task index to remove: ";
                std::cin >> index;
                manager.removeTask(index);
                break;
            }
            case 5:
                std::cout << "Exiting." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please enter a valid option." << std::endl;
        }
    } while (choice != 5);

    return 0;
}
