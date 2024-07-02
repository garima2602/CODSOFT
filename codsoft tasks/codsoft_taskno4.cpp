#include <iostream>
#include <vector>
#include <string>
class Task 
{
public:
    std::string description;
    bool completed;
    Task(const std::string& desc) : description(desc), completed(false) {}
};
class TodoList 
{
private:
    std::vector<Task> tasks;
public:
    void addTask() 
    {
        std::string description;
        std::cout << "Enter task description: ";
        std::cin.ignore();
        std::getline(std::cin, description);
        tasks.push_back(Task(description));
        std::cout << "Task added.\n";
    }
    void viewTasks() 
    {
        if (tasks.empty()) 
        {
            std::cout << "No tasks in the list.\n";
            return;
        }
        for (size_t i = 0; i < tasks.size(); ++i) 
        {
            std::cout << i + 1 << ". " << tasks[i].description 
                      << " - " << (tasks[i].completed ? "Completed" : "Pending") << "\n";
        }
    }
    void markCompleted() {
        viewTasks();
        if (tasks.empty()) return;
        int index;
        std::cout << "Enter the number of the task to mark as completed: ";
        std::cin >> index;
        if (index > 0 && index <= static_cast<int>(tasks.size())) 
        {
            tasks[index - 1].completed = true;
            std::cout << "Task marked as completed.\n";
        } 
        else 
        {
            std::cout << "Invalid task number.\n";
        }
    }
    void removeTask() 
    {
        viewTasks();
        if (tasks.empty()) return;
        int index;
        std::cout << "Enter the number of the task to remove: ";
        std::cin >> index;
        if (index > 0 && index <= static_cast<int>(tasks.size())) 
        {
            tasks.erase(tasks.begin() + index - 1);
            std::cout << "Task removed.\n";
        } 
        else 
        {
            std::cout << "Invalid task number.\n";
        }
    }
};
int main() 
{
    TodoList todoList;
    int choice;
    while (true) 
    {
        std::cout << "\n--- Todo List Manager ---\n"
                  << "1. Add Task\n"
                  << "2. View Tasks\n"
                  << "3. Mark Task as Completed\n"
                  << "4. Remove Task\n"
                  << "5. Exit\n"
                  << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) 
        {
            case 1: todoList.addTask(); break;
            case 2: todoList.viewTasks(); break;
            case 3: todoList.markCompleted(); break;
            case 4: todoList.removeTask(); break;
            case 5: std::cout << "See you soon!\n"; return 0;
            default: std::cout << "Invalid choice. Try again.\n";
        }
    }
return 0;
}