#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct passenger {
	char passenger_name[20];
	char pClass[10];
	char pNo[10];
} passenger_a;

typedef struct queue_node {
	passenger_a pas;
	struct queue_node *restp;
} queue_node_t;

typedef struct {
	queue_node_t *frontp, *rearp;
	int size;
} queue_t;

// Create the following functions:
void scan_passenger(passenger_a *passp);
void print_passenger(passenger_a pass);
void add_to_q(queue_t *qp, passenger_a ele);
passenger_a remove_from_q(queue_t *qp);
void display_q(queue_t q);

int main(void) {

	// passenger queue - initialized to empty state
	queue_t pass_q = { NULL, NULL, 0 };
	passenger_a next_pass, fst_pass;

	char choice;

	// Processes requests
	do {
		printf("Enter A(dd), R(emove), D(isplay), or Q(uit)> ");
		scanf(" %c", &choice);

		switch (toupper(choice)) {
		case 'A':
			printf("Enter passenger data> ");
			scan_passenger(&next_pass);
			add_to_q(&pass_q, next_pass);
			break;

		case 'R':
			if (pass_q.size > 0) {
				fst_pass = remove_from_q(&pass_q);
				printf("Passenger removed from queue: \n");
				print_passenger(fst_pass);
			} else {
				printf("Queue empty - no one to delete\n");
			}
			break;

		case 'D':
			if (pass_q.size > 0)
				display_q(pass_q);
			else
				printf("Queue is empty\n");
			break;

		case 'Q':
			printf("Leaving passenger queue program with %d \n", pass_q.size);
			printf("passengers in the queue\n");
			break;

		default:
			printf("Invalid choice -- try again\n");
		}
	} while (toupper(choice) != 'Q');

	return 0;
}

void add_to_q(queue_t *qp, passenger_a ele) {
	/* You  student need only to fill in your code
	 in here
	 Any other change in the code will be penalized*/
	queue_node_t *temp;
	temp = (queue_node_t*) malloc(sizeof(queue_node_t));//resizing 
	temp->pas = ele;//give the value
	if (qp->size != 0) {//checking size
		qp->rearp->restp = temp;
		qp->rearp = temp;
	} else {
		qp->frontp = qp->rearp = temp;
	}
	qp->size++;

}

// Removes and frees first node of queue, returning value stored there.
// Pre-condition: queue is not empty
passenger_a remove_from_q(queue_t *qp) {

	//initial queue value which is to be returned
	passenger_a ans;

	/* You  student need only to fill in your code
	 in here
	 Any other change in the code will be penalized*/
	queue_node_t *temp;
	temp = (queue_node_t*) malloc(sizeof(queue_node_t));
	temp = qp->frontp;
	ans = temp->pas;

	qp->frontp = qp->frontp->restp;
	qp->size--;
	free(temp);

	return ans;
}

// display all passengers info. in the queue
void display_q(queue_t q) {

	/* You  student need only to fill in your code
	 in here
	 Any other change in the code will be penalized*/
	if (q.size == 0) {//checking queue is not empty
		printf("Empty Queue.\n");
	} else {
		queue_node_t *temp;
		temp = (queue_node_t*) malloc(sizeof(queue_node_t));//resize
		temp = q.frontp;//get the 1st node
		int size = q.size;//for loop start point
		int i=0;
		for(i=size;i>0;--i){//for loop for printing
			printf("Name: %s, Class: %s, Ticket NO: %s\n",
					temp->pas.passenger_name, temp->pas.pClass, temp->pas.pNo);
			temp = temp->restp;
			
		}
		
	}
}

// load passenger data
void scan_passenger(passenger_a *passp) {

	/* You  student need only to fill in your code
	 in here
	 Any other change in the code will be penalized*/
	char name[20] = "\0", class[10] = "\0", number[10] = "\0";//list for data
	printf("Enter passenger name: ");//getting data from user
	scanf("%s", name);
	strcpy(passp->passenger_name, name);
	printf("Enter passenger class: ");
	scanf("%s", class);
	strcpy(passp->pClass, class);
	printf("Enter passenger number: ");
	scanf("%s", number);
	strcpy(passp->pNo, number);

}

// print the info. of the removed passenger from the queue
void print_passenger(passenger_a pass) {

	/* You  student need only to fill in your code
	 in here
	 Any other change in the code will be penalized*/
	printf("Name: %s, Class: %s, Ticket NO: %s\n", pass.passenger_name,//just printing the passenger info
			pass.pClass, pass.pNo);

}
