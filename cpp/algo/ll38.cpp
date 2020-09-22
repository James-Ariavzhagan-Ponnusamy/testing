#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
{
  int n;
  struct Node *next;
};
Node *start=NULL, *last=NULL;

void disp();
int Create()
{
  int n=0;
  Node *local = NULL;
  local = (Node *) malloc(sizeof(Node));
  if ( !local ) return -1;
  cin >>n ;
  local->n = n;
  local->next = NULL;
  if (start==NULL)
  {
    start = last = local;
  }
  else
  {
    last->next = local;
    last = local;
  }
  return 0;
}

void disp()
{
  Node *ptr = start ;
  if ( ptr )
    cout << "Linked List : ->";
  else
    cout <<"Linked List :" << endl;
  while(ptr)
  {
    if ( ptr->next == NULL)
      cout << ptr->n << endl;
    else
      cout << ptr->n << "->";
    ptr = ptr->next;

  }
}
void Delete(){
  int count=0;
  int n;
  int i;
  cin >> n;

  Node *ptr = NULL;
  ptr = start ;

  while(ptr){
    count++;
    cout << "iter : " << ptr->n << endl;
    ptr = ptr->next;
  }
  cout << "The total nodes " << count << endl;
  if (count) count = count - n;
  cout << "After deleted " << count << endl;
  if ( count == 0 ) { start = NULL; return; }
  if ( count < 0 ) exit(0);
  ptr = start ;
  i = 1;
  while(i < count)
  {
    cout << ptr->n << endl;
    ptr = ptr->next;
    i++;
  }
  ptr->next = NULL;
}
int main()
{
  int n;
  int i;
  cin >> n;
  for(i=0;i<n;i++)
  {
    if (Create() == -1) exit(0);
  }
  cout << "Enter the nodes to delete " << endl;
  Delete();
  cout << "After deleteion " << endl;
  disp();
}
