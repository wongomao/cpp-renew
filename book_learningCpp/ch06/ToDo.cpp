#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

const string FILENAME{ "tasks.txt" };

void display_menu()
{
    cout << "-------------------" << endl;
    cout << "Add a task (a)" << endl;
    cout << "List tasks (l)" << endl;
    cout << "Mark task complete (c)" << endl;
    cout << "Delete a task (d)" << endl;
    cout << "Quit (q)" << endl;
    cout << "-------------------" << endl;
}

void display_tasks(const vector<string> &tasks)
{
    cout << "\tTasks:" << endl;
    for (auto task : tasks)
    {
        cout << "\t\t" << task << endl;
    }
}

void mark_task_as_complete(vector<string> &tasks, int task_number)
{
    cout << "Task " << task_number << " marked as complete" << endl;
    tasks[task_number - 1] += "_COMPLETE";
}

void load_tasks_from_file(vector<string> &tasks)
{
    ifstream input_file{ FILENAME }; // input_file is an ifstream object
    if (!input_file)
    {
        return; // just return, no error message
    }

    string task;
    while (getline(input_file, task))
    {
        tasks.push_back(task);
    }
    input_file.close();
}

void save_tasks_to_file(const vector<string> &tasks)
{
    ofstream output_file{ FILENAME }; // output_file is an ofstream object
    if (!output_file)
    {
        cerr << "Error opening output file" << endl;
        return;
    }

    for (auto task : tasks)
    {
        output_file << task << endl;
    }
    output_file.close();
}

int main()
{
    vector<string> tasks;
    load_tasks_from_file(tasks);
    while (true)
    {
        display_menu();
        char choice;
        cin >> choice;
        if (choice == 'q')
        {
            save_tasks_to_file(tasks);
            break;
        }
        else if (choice == 'a')
        {
            cout << "Enter task: ";
            string task;
            cin >> task;
            tasks.push_back(task);
        }
        else if (choice == 'l')
        {
            display_tasks(tasks);
        }
        else if (choice == 'c')
        {
            cout << "Enter task number: ";
            int task_number;
            cin >> task_number;
            if (task_number < 1 || task_number > tasks.size())
            {
                cout << "Invalid task number" << endl;
            }
            else
            {
                mark_task_as_complete(tasks, task_number);
            }
        }
        else if (choice == 'd')
        {
            cout << "Enter task number: ";
            int task_number;
            cin >> task_number;
            if (task_number < 1 || task_number > tasks.size())
            {
                cout << "Invalid task number" << endl;
            }
            else
            {
                tasks.erase(tasks.begin() + task_number - 1);
            }
        }
        else
        {
            cout << "Invalid choice" << endl;
        }
    }
}
