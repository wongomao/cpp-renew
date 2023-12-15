#include <iostream>
#include <array>
#include <vector>
#include <fstream>
#include <limits>

int main()
{
    const char FILENAME[] = "todo_list.txt";
    const int MAX_TASKS = 100;
    const char COMPLETED_MARK{ 'X' };

    std::vector<std::array<char, MAX_TASKS>> taskNames;
    std::vector<bool> taskCompleted;

    int taskCount{ 0 };

    std::cout << "Welcome to your to-do list" << std::endl << std::endl;
    std::ifstream file(FILENAME);
    if (file.is_open())
    {
        char line[MAX_TASKS + 2];
        while (file.getline(line, sizeof(line)) && taskCount < MAX_TASKS)
        {
            int pos{ 0 };
            bool bCompleted{ false };
            std::array<char, MAX_TASKS> task;
            while (pos < MAX_TASKS - 1 && line[pos] != '\n' && line[pos] != '\0')
            {
                if (line[pos] == COMPLETED_MARK)
                {
                    bCompleted = true;
                    break;
                }
                else
                {
                    task[pos] = line[pos];
                }


                pos++;
            }
            task[pos] = '\0';
            taskNames.push_back(task);
            taskCompleted.push_back(bCompleted);

            ++taskCount;
        }
        file.close();
        std::cout << "Data loaded from file." << std::endl << std::endl;
    }
    else
    {
        std::cout << "No saved data found." << std::endl << std::endl;
    }

    bool bShouldRun{true};
    while (bShouldRun)
    {
        std::cout << "Please select an option:" << std::endl;
        std::cout << "1. Add an item" << std::endl;
        std::cout << "2. Show me what I need to do" << std::endl;
        std::cout << "3. Mark an item as completed" << std::endl;
        std::cout << "4. Save data to a file" << std::endl;
        std::cout << "5. Exit" << std::endl << std::endl;

        int option;
        std::cout << "Your choice: ";
        std::cin >> option;
        std::cout << "" << std::endl;

        switch (option)
        {
            case 1: // new task
                if (taskCount < MAX_TASKS)
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::array<char, MAX_TASKS> task;
                    std::cout << "Enter a task name: ";
                    std::cin.getline(task.data(), MAX_TASKS);
                    taskNames.push_back(task);
                    taskCompleted.push_back(false);
                    taskCount++;
                    std::cout << "Task added." << std::endl << std::endl;
                }
                else
                {
                    std::cout << "Your to-do list is full." << std::endl;
                }
                break;

            case 2: // show list
                if (taskCount == 0)
                {
                    std::cout << "Your to-do list is empty" << std::endl << std::endl;
                }
                else
                {
                    std::cout << "Your to-do list:" << std::endl;
                    for (int i = 0; i < taskCount; i++)
                    {
                        std::cout << (i + 1) << ". ";
                        for (size_t j = 0; j < MAX_TASKS && taskNames[i][j] != '\0'; j++)
                        {
                            std::cout << taskNames[i][j];
                        }
                        std::cout << " [" << (taskCompleted[i] ? COMPLETED_MARK : ' ') << "]" << std::endl;
                    }
                    std::cout << "" << std::endl;

                }
                break;

            case 3: // mark item as complete
                if (taskCount == 0)
                {
                    std::cout << "Your to-do list is empty." << std::endl << std::endl;
                }
                else
                {
                    std::cout << "Enter the number of the task to mark as complete: ";
                    int index;
                    std::cin >> index;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "" << std::endl;
                    if (index > 0 && index <= taskCount)
                    {
                        taskCompleted[index - 1] = true;
                        std::cout << "Task marked as completed." << std::endl << std::endl;
                    }
                    else
                    {
                        std::cout << "Invalid task number." << std::endl << std::endl;
                    }
                }
                break;
            case 4: // save data to file
                {
                    std::ofstream file(FILENAME);
                    if (file.is_open())
                    {
                        for (size_t i = 0; i < taskCount; i++)
                        {
                            file << taskNames[i].data();
                            file << ' '; // Add a space before the taskComplete status
                            file << (taskCompleted[i] ? COMPLETED_MARK : ' ');
                            file << std::endl;
                        }
                        file.close();
                        std::cout << "Data saved to a file." << std::endl;
                    }
                }
                break;

            case 5: // exit
                std::cout << "Goodbye!" << std::endl;
                bShouldRun = false;
                break;
            default:
                std::cout << "Invalid option" << std::endl;
        }
    }

    return 0;

}