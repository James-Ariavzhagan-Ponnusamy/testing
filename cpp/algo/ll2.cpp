#include <iostream>
using namespace std;

struct Node{
  int nData;
  struct Node *next;
};

struct Node *first = NULL;
struct Node *last = NULL;

void disp();
void Create()
{
  int n;
  int v;
  struct Node *ptr;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin >> v;
    ptr = (struct Node *) malloc(sizeof(struct Node));
    if ( ptr == NULL )
    {
      cout << "Memory allocation failure " << endl; exit(0);
     }
    ptr->nData = v;
    ptr->next = NULL;
    if (first == NULL)
    {
      first = last = ptr ;
    }
    else
    {
      last->next = ptr;
      last = ptr ;
    }
    //disp();
  }
}

void add(){
  disp();
  int loc;
  int i;
  int value;
  int added = 0;
  struct Node *ptr = first;
  struct Node *n = NULL;

  cin>>loc;
  cin>>value;
  cout << "location : " << loc << endl;
  cout << "value    : " << value << endl;

  n = (struct Node *) malloc(sizeof(struct Node));
  n->next = NULL;
  n->nData = value;

  if ( loc == 1)
  {
    n->next = first;
    first = n;
    return;
  }
  /*
  if ( loc == 2 )
  {
    n->next = first->next;
    first->next = n ;
  }
  */
  i = 1;

  while(ptr && i < loc ){
    cout << "i:"<<i << endl;
    cout << "loc:"<<loc << endl;
    if ( ptr ->next == NULL) break;
    if (i == (loc-1))
    {
      n->next = ptr->next;
      ptr->next = n;
      added = 1;
    }
    i++;
    ptr = ptr->next;
  }
  cout << "After exit " << endl;
  cout << "i:"<<i << endl;
  cout << "loc:"<<loc << endl;

  if ( added == 0)
  {
    cout << "Invalid position!"<< endl;
  }
}
void Add(){
  int loc;
  int i;
  int value;
  struct Node *ptr = first;
  struct Node *n = NULL;
  cin>>loc;
  cin>>value;


  n = (struct Node *) malloc(sizeof(struct Node));
  n->next = NULL;
  n->nData = value;
  loc--;
  if (loc == 1)
  {
    n->next = first;
    first = n;
    return;
  }
  for(i=1;i<loc;i++)
  {
    if ( ptr )
      ptr = ptr ->next;
    else
      return;
  }
  n->next = ptr->next ;
  ptr ->next = n;
}
void disp(){
  struct Node *ptr = first;
  cout << "Linked List : ->" ;
  while(ptr != NULL){
    if (ptr ->next != NULL )
      cout << ptr->nData << "->";
    else
      cout << ptr->nData;
    ptr = ptr->next;
  }
  cout << endl ;
}
int main(){
  Create();
  add();
  disp();
}
