#include<iostream>
using namespace std;

class node {
public:
	string data;
	bool status=0;
	node* next;
};



node* initialize_list() {
	return NULL;
}


bool isempty(node* head) {
	return (head == NULL);
}




node* insert_task(node* head, string val) {
	node* temp, * current;
	temp = new node;
	if (temp == NULL) {
		cout << "error upon creation";
		exit(1);
	}
	temp->data = val;
	temp->next = NULL;
	if (isempty(head)) {
		head = temp;
		return head;
	}
	for (current = head; current->next != NULL; current = current->next);
	current->next = temp;
	return head;
}




void display(node* LIST) {
	node* current;
	if (isempty(LIST)) {
		cout << "empty\n";
		return;
	}
	else current = LIST;
	while (current != NULL) {
		cout << current->data << endl << "It's ";
		if (current->status == 0)cout << "Pending" << endl;
		else cout << "Completed" << endl;
		current = current->next;
	}
}




node* markAsCompleted(node* LIST,string y) {
	node* current;
	if (isempty(LIST)) {
		cout << "empty\n";
		return LIST;
	}
	else current = LIST;
	while (current != NULL) {
		if (current->data == y) {
			current->status = 1; return LIST;
		}
		else current = current->next;
	}
	return LIST;	
}




node* delete_node(node* LIST, string val) {
	node* current, * previous, * temp;
	if (isempty(LIST)) {
		return LIST;
	}
	if (LIST->data == val) {
		temp = LIST->next;
		delete LIST;
		LIST = temp;
		return LIST;
	}
	current = LIST;
	previous = NULL;
	while (current != NULL && current->data != val) {
		previous = current;
		current = current->next;
	}
	if (current == NULL)
		return LIST;
	previous->next = current->next;
	delete current;
	return LIST;
}




void main()
{
	int choice = 0;
	char stay_in_the_app = 'y';

	node* LIST;
	LIST = initialize_list();

	while (stay_in_the_app == 'y')
	{
		cout << "What do you wanna do?" << endl;
		cout << "1- Add a task" << endl;
		cout << "2- Display all the tasks" << endl;
		cout << "3- Mark a task as completed" << endl;
		cout << "4- Remove a task" << endl;

		cin >> choice;
		
		if (choice == 1)
		{
			int nb_tasks;
			cout << "how many tasks you want to enter? ";
			cin >> nb_tasks;
			string task;
			for (int i = 1; i <= n; i++) {
				cout << "enter the new task to do: ";
				cin >> task;
				LIST = insert_task(LIST, task);
			}
			
		}
		else if (choice == 2)
		{
			display(LIST);

		}
		else if (choice == 3)
		{
			string task;
			cout << "enter the task you want to mark as completed: ";
			cin >> task;
			LIST=markAsCompleted	(LIST, task);
		}
		else if (choice == 4)
		{
			string task;
			cout << "enter the task you want to delete: ";
			cin >> task;
			LIST=delete_node(LIST, task);
		}
		else
		{
			cout << "Invalid choice!" << endl;
		}
		cout << "would you like to stay in the app? press y for YES" << endl;
		cin >> stay_in_the_app;

	}
	
}