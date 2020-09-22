#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
  int n;
  struct node *next;
};

node *top=NULL;

void disp();
void push()
{
  int n=0;
  node *local = NULL;
  local = (node *) malloc(sizeof(node));
  if ( !local ) exit(0);
  cin >>n ;
  local->n = n;
  local->next = top;
  top = local;
}

void disp()
{
  node *ptr = top;
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
    if(top) top = top->next;
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
    push() ;
  }
  disp();
}
