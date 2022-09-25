class MyCircularQueue {
vector<int> v;
	int head = 0, tail = 0, size = 0, sizeV;

public:
	MyCircularQueue(int k)
	{
		v = vector<int>(k, -1);
        sizeV = k;
	}

	bool enQueue(int value)
	{
		if (isFull()) return false;

		if (isEmpty())
		{
			head = tail = 0;
			v[head] = value;
			++size;
			return true;
		}

		tail = (tail + 1) % sizeV;
		v[tail] = value;
		++size;
		return true;
    }

	bool deQueue()
	{
		if (isEmpty()) return false;
		v[head] = -1;
		head = (head + 1) % sizeV;
		--size;
		return true;
	}

	int Front()
	{
		return v[head];
	}

	int Rear()
	{
		return v[tail];
	}

	bool isEmpty()
	{
		return size == 0;
	}

	bool isFull()
	{
		return size == sizeV;
	}
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */