#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
  int n;
  struct node *next;
};
node *first=NULL, *last=NULL;

void disp();
int Create()
{
  int n=0;
  node *local = NULL;
  local = (node *) malloc(sizeof(node));
  if ( !local ) return -1;
  cin >>n ;
  local->n = n;
  local->next = NULL;
  if ( first == NULL)
  {
    first = last = local;
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
  node *ptr = first;
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
  int n;
  cin >> n;
  while(n--){
    if(first) first = first->next;
  }
  //cout << first->n << endl;
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
