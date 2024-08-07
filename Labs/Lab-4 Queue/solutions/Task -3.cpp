#include <iostream>
using namespace std;

class Task {
	public:
		int id;
		string desc;
		string priority;
		string assignedDeveloper;

		Task(int id, string d, string p) : id(id), desc(d), priority(p) {}
};

class Queue {
	private:
		Task* tasks[30];
		int taskCount;

	public:
		Queue() {
			taskCount = 0;
		}

		void addTask(int id, string desc, string priority) {
			Task* newTask = new Task(id, desc, priority);

			if (priority == "High") {
				newTask->assignedDeveloper = "Senior Developer";
			} else if (priority == "Medium") {
				newTask->assignedDeveloper = "Junior Developer";
			} else if (priority == "Low") {
				newTask->assignedDeveloper = "Intern";
			}

			tasks[taskCount] = newTask;
			taskCount++;

			cout << "Task " << id << " added to queue." << endl;
		}

		// Remove a completed task from the task list
		void completeTask(int id) {
			for (int i = 0; i < taskCount; i++) {
				if (tasks[i]->id == id) {
					delete tasks[i];
					for (int j = i; j < taskCount - 1; j++) {
						tasks[j] = tasks[j + 1];
					}
					taskCount--;
					return;
				}
			}

			cout << "Task " << id << " not found in queue." << endl;
		}

		void displayNextTask() {
			cout << "Next tasks:" << endl;

			int highPriorityIndex = -1;
			int mediumPriorityIndex = -1;
			int lowPriorityIndex = -1;

			for (int i = 0; i < taskCount; i++) {
				if (tasks[i]->priority == "High" && (highPriorityIndex == -1 || tasks[i]->id < tasks[highPriorityIndex]->id)) {
					highPriorityIndex = i;
				} else if (tasks[i]->priority == "Medium" && (mediumPriorityIndex == -1 || tasks[i]->id < tasks[mediumPriorityIndex]->id)) {
					mediumPriorityIndex = i;
				} else if (tasks[i]->priority == "Low" && (lowPriorityIndex == -1 || tasks[i]->id < tasks[lowPriorityIndex]->id)) {
					lowPriorityIndex = i;
				}
			}

			if (highPriorityIndex != -1) {
				cout << "Senior Developer: Task " << tasks[highPriorityIndex]->id << " - " << tasks[highPriorityIndex]->desc << endl;
			} else {
				cout << "Senior Developer: No tasks available." << endl;
			}

			if (mediumPriorityIndex != -1) {
				cout << "Junior Developer: Task " << tasks[mediumPriorityIndex]->id << " - " << tasks[mediumPriorityIndex]->desc << endl;
			} else {
				cout << "Junior Developer: No tasks available." << endl;
			}

			if (lowPriorityIndex != -1) {
				cout << "Intern: Task " << tasks[lowPriorityIndex]->id << " - " << tasks[lowPriorityIndex]->desc << endl;
			} else {
				cout << "Intern: No tasks available." << endl;
			}
		}
};

int main() {
	Queue tasks;

	tasks.addTask(1, "Fix bug", "High");
	tasks.addTask(2, "Implement feature", "Medium");
	tasks.addTask(3, "Test feature", "Medium");
	tasks.addTask(4, "Deploy feature", "Medium");
	tasks.addTask(5, "Documentation", "Low");

	tasks.displayNextTask();

	tasks.completeTask(1);
	tasks.completeTask(2);
	tasks.completeTask(3);
	tasks.completeTask(9);

	tasks.displayNextTask();

	return 0;
}

