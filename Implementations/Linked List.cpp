struct Node
{
	int val;
	struct Node* next;
	struct Node* prev;
};

class Linked_List
{
	public:
		Node* head;
		Node* last;
		int size;
	Linked_List()
	{
		head = (Node*)NULL; last = (Node*)NULL; size = 0;
	}
	void push_back(int n)
	{
		if(head == (Node*)NULL)
		{
			head = new Node;
			head->val = n;
			head->next = (Node*)NULL; head->prev = (Node*)NULL;
			last = head;
		}
		else
		{
			Node* tmp = new Node;
			tmp->val = n;
			tmp->next = (Node*)NULL;
			tmp->prev = last;
			last->next = tmp;
			last = tmp;
		}
		size++;
	}
	void pop(void)
	{
		if(head == (Node*)NULL or last == (Node*)NULL or size == 0)return;
		last = last->prev;
		if(last != (Node*)NULL)
		{
			delete last->next;
			last->next = (Node*)NULL;
		}	
		size--;
	}
	void rotate(int n)
	{
		if(n == 0) return;
		Node* current = head;
		int depth = 0;
		while(depth != n and current->next != (Node*)NULL and depth < size)
		{
			current = current->next;
			depth++;
		}
		last->next = head;
		head->prev = last;
		head = current;
		current->prev->next = (Node*)NULL;
		last = current->prev;
		current->prev = (Node*) NULL;
	}
	void print_to_file(void)
	{
		FILE* out;
		out = fopen("kenobi.out","w");
		fprintf(out, "%d\n", size);
		if(size > 0)
		{
			Node* current = head;
			while(current->next != (Node*)NULL)
			{
				fprintf(out, "%d ", current->val);
				current = current->next;
			}
			fprintf(out, "%d\n", current->val);	
		}	
	}
};
