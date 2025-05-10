#include<iostream>
#include<exception>
using namespace std;

class QueueOverflowException : public exception{
	public:
		const char* what() const noexcept override{
			return "QueueOverflowException - Queue is full";
		}
};

class QueueUnderflowException : public exception{
	public:
		const char* what() const noexcept override{
			return "QueueUnderflowException - Queue is empty";
		}
};

template <typename T>
class Queue{
	private:
		int capacity;
		int front;
		int rear;
		int count;
		T* data;

	public:
		Queue(int size){
			capacity = size;
			data = new T[capacity];
			front = 0;
			rear = -1;
			count = 0;
		}

		void enqueue(T value){
			if(count == capacity){
				throw QueueOverflowException();
			}
			rear = (rear+1)%capacity;
			data[rear] = value;
			count++;
		}

		T dequeue(){
			if(count == 0){
				throw QueueUnderflowException();
			}
			T value = data[front];
			front = (front+1)%capacity;
			count--;
			return value;
		}

		~Queue(){
			delete[] data;
		}
};

int main(){
	Queue<int> q(2);

	try{
		cout<<"Attempting to enqueue to a full queue"<<endl;
		q.enqueue(10);
		q.enqueue(20);
		q.enqueue(30);
	} catch (const exception& e){
		cout<<"Caught "<<e.what()<<endl;
	}

	try{
		cout<<"\nAttempting to dequeue from an empty queue"<<endl;
		q.dequeue();
		q.dequeue();
		q.dequeue();
	} 
	catch (const exception& e){
		cout<<"Caught "<<e.what()<<endl;
	}

}
