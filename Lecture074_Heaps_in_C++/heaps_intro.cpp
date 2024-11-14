#include <iostream>
#include<queue>
using namespace std;

class heap
{
public:
  int arr[100];
  int size;

  heap()
  {
    arr[0] = -1;
    size = 0;
  }

  void insert(int val)
  {
    size = size + 1;
    int index = size;
    arr[index] = val;

    while (index > 1)
    {
      int parent = index / 2;

      if (arr[parent] < arr[index])
      {
        swap(arr[parent], arr[index]);
        index = parent;
      }
      else
      {
        return;
      }
    }
  }
  void print()
  {
    for (int i = 1; i <= size; i++)
    {
      cout << arr[i] << " ";
    }
    cout << endl;
  }

  void deleteFromHeap()
  {
    if (size == 0)
    {
      cout << "Nothing to Delete" << endl;
      return;
    }
    // step-1-->put last element to first element
    arr[1] = arr[size];
    // step-2--> remove last element
    size--;

    // take root node to its correct positions
    int i = 1;
    while (i < size)
    {
      int leftIndex = 2 * i;
      int rightIndex = 2 * i + 1;

      if (leftIndex < size && arr[leftIndex] > arr[i])
      {
        swap(arr[leftIndex], arr[i]);
        i = leftIndex;
      }
      else if (rightIndex < size && arr[rightIndex] > arr[i])
      {
        swap(arr[rightIndex], arr[i]);
        i = rightIndex;
      }
      else
      {
        return;
      }
    }
  }
};



// For-Max-Heap --> Heapify
void heapify(int arr[], int size, int i)
{
  int largest = i;
  int leftChild = 2 * i;  // 1-based indexing
  int rightChild = 2 * i + 1;

  if (leftChild <= size && arr[largest] < arr[leftChild])
  {
    largest = leftChild;
  }

  if (rightChild <= size && arr[largest] < arr[rightChild])
  {
    largest = rightChild;
  }

  if (largest != i)
  {
    swap(arr[largest], arr[i]);
    heapify(arr, size, largest);
  }
}

// Heap Sort
void heapSort(int arr[], int n)
{
  int size = n;
  while(size > 1)
  {
    swap(arr[size], arr[1]);
    size--;

    heapify(arr, size, 1);
  }
}


int main()
{
  heap h;
  h.insert(50);
  h.insert(55);
  h.insert(53);
  h.insert(52);
  h.insert(54);

  // h.print();

  h.deleteFromHeap();

  // h.print();

  int arr[6] = {-1, 54, 53, 55, 52, 50};
  int n = 5;
  cout << "Printing the Orignal Array" << endl;
  for (int i = 1; i <= n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
  // heap Creation
  for (int i = n / 2; i > 0; i--)
  {
    heapify(arr, n, i);
  }
  cout << "Printing the Array After Heapify" << endl;
  for (int i = 1; i <= n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  // heapSort
  heapSort(arr, n);
  cout << "Printing the Heap Sort" << endl;
  for (int i = 1; i <= n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;


  cout<<"Using Priority Queue Here--->> Max_Heap"<<endl;
  priority_queue<int>pq;   // default--> Max_Heap Created
  
  pq.push(4);
  pq.push(2);
  pq.push(5);
  pq.push(3);

  cout<<"Top Element of Priority Queue-"<<pq.top()<<endl;
  pq.pop();
  cout<<"Top Element of Priority Queue-"<<pq.top()<<endl;
  cout<<"Size of MaxHeap-"<<pq.size()<<endl;

  if(pq.empty())
  {
    cout<<"PQ is Empty"<<endl;
  }
  else{
    cout<<"PQ is Not Empty"<<endl;
  }


  // Min Heap-->STL
  priority_queue<int, vector<int>, greater<int>> minHeap;
  cout<<"Using Priority Queue Here--->> Min_Heap"<<endl;
  
  minHeap.push(4);
  minHeap.push(2);
  minHeap.push(5);
  minHeap.push(3);

  cout<<"Top Element of Priority Queue-"<<minHeap.top()<<endl;
  minHeap.pop();
  cout<<"Top Element of Priority Queue-"<<minHeap.top()<<endl;
  cout<<"Size is-"<<minHeap.size()<<endl;

  if(minHeap.empty())
  {
    cout<<"MinHeap is Empty"<<endl;
  }
  else{
    cout<<"MinHeap is Not Empty"<<endl;
  }

  return 0;
}