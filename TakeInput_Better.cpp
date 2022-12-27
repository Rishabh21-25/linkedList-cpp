#include <iostream>
using namespace std;
#include "Node.cpp"
Node *takeInput_Better()
{
  int data;
  cin >> data;
  Node *head = NULL;
  Node *tail = NULL;
  while (data != -1)
  {
    bool isRun = true;
    Node *newNode = new Node(data);
    if (head == NULL)
    {
      head = newNode;
      tail = newNode;
    }
    else
    {
      tail->next = newNode;
      tail = tail->next;
    }
    cin >> data;
  }
  return head;
}

void print(Node *head)
{
  Node *temp = head;

  while (head != NULL)
  {
    cout << head->data << " ";
    head = head->next;
  }

  cout << "\n";
}

Node* insertNode(Node *head, int i, int data)
{
  Node *newNode = new Node(data);
  int count = 0;
  Node *temp = head;

  if(i == 0) 
  {
    newNode -> next = head;
    head = newNode;
    return head;
  }

  while (temp != NULL && count < i - 1)
  {
    temp = temp->next;
    count++;
  }

  if (temp != NULL)
  {
    Node *a = temp->next;
    temp->next = newNode;
    newNode->next = a;
  }
  return head;
}

int main()
{
  cout << "Enter the elements: ";
  Node *head = takeInput_Better();
  cout << "Elements are: ";
  print(head);
  cout << "Enter position and element to insert: ";
  int i, data;
  cin >> i >> data;
  head = insertNode(head, i, data);
  cout << "Elements are: ";
  print(head);
  return 0;
}