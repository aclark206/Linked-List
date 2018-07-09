#include "LinkedList.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main () {

  int item1 = rand();
  int item2 = rand();
  int item3 = rand();
  int item4 = rand();
  int item5 = rand();
  int item6 = rand();
  int item7 = rand();
  int item8 = rand();
  int item9 = rand();
  int item10 = rand();
  int item11 = rand();
  int item12 = rand();
  int item13 = rand();
  int item14 = rand();
  int item15 = rand();
  int item16 = rand();
  int item17 = rand();
  int item18 = rand();
  int item19 = rand();
  int item20 = rand();
  int item21 = rand();
  int item22 = rand();
  int item23 = rand();
  int item24 = rand();

  LinkedList list;

  cout << " * * * * * * * * * * * * * * * * * * * * " << endl;
  cout << " * * * * * * * * * * * * * * * * * * * * " << endl;
/*************** insert   ***********************/
  cout << endl << endl;
  cout << " * * * * * * * * * * * * * * * * * * * * " << endl;
  cout << "Testing insert(). " << endl;
  cout << "Size before insertions should be 0." << endl;
  cout << "Size = " << list.size() << endl;
  list.insert(item1);
  list.insert(item2);
  list.insert(item3);
  list.insert(item4);
  list.insert(item5);
  list.insert(item6);
  list.insert(item7);
  list.insert(item8);
  list.insert(item9);
  list.insert(item10);
  list.insert(item11);
  list.insert(item12);
  list.insert(item13);
  list.insert(item14);
  list.insert(item15);
  
  cout << "Size after insertions should be 15." << endl;
  cout << "Size = " << list.size() << endl;
  
/*************** print()   ***********************/ 
  cout << endl << endl;
  cout << " * * * * * * * * * * * * * * * * * * * * " << endl;
  cout << "Testing print(). List:" << endl; 
  list.print();
  cout << "Print an empty list." << endl << "List2: "; 
  LinkedList list2;
  list2.print();
  cout << endl;
  
  
/**********  delete test cases *****************/
  cout << endl << endl;
  cout << " * * * * * * * * * * * * * * * * * * * * " << endl;
  cout << "Testing remove(). " << endl;
  //deleting the head
  cout << "deleting the head.  List: " << endl;
  list.remove(item15);
  cout << "size: " << list.size() << endl;
  list.print();
  
  //deleting a node in the middle
  cout << endl;
  cout << "deleting a node in the middle.  List: " << endl;
  list.remove(item10);
  cout << "size: " << list.size() << endl;
  list.print();
  
  //deleting the tail
  cout << endl;
   cout << "deleting the tail.   List: " << endl;
  list.remove(item1);
  cout << "size: " << list.size() << endl;
  list.print();
  
  //deleteing a node that doesn't exist
  cout << endl;
  cout << "Attempting to delete a node that doesn't exist."<< endl;
  list.remove(item16);
  cout << "size: " << list.size() << endl;
  list.print();
  

/********** append test cases*****************/  
  // append an empty list
  cout << endl << endl;
  cout << " * * * * * * * * * * * * * * * * * * * * " << endl;
  cout << "Testing append(). " << endl;
  cout << "list size before appending an empty list " << list.size() << endl;
  list.append(list2);
  cout << "list size after appending an empty list " << list.size() << endl;
  list.print();

  // append a non-empty list
  list2.insert(item17);
  list2.insert(item18);
  list2.insert(item19);
  list2.insert(item20);
  cout << endl;
  cout << "Inserted items into list2.  List2 size: "  << list2.size() << endl;
  cout << "List2: " << endl;
  list2.print();

  cout << "Appending List2 onto List: "  << endl;
  list.append(list2);
  cout << "list size: " << list.size() << endl;
  cout << "list: " << endl;
  list.print();

/********** copy constructor ****************/
  cout << endl << endl;
  cout << " * * * * * * * * * * * * * * * * * * * * " << endl;
  cout << "Testing copy constructor(). " << endl;
  cout << "List3 copy constructed from list. " << endl;
  LinkedList list3(list);
  cout << "list3 size: " << list3.size() << endl;
  list3.print();
  
  //copy an empty list
  cout << endl;
  cout << "List5 copy constructed from an empty list. " << endl;
  LinkedList list4;
  LinkedList list5(list4);
  cout << "list5 size: " << list5.size() << endl;
  list5.print();
  
  
/************  Reverse  ********************/
  cout << endl << endl;
  cout << " * * * * * * * * * * * * * * * * * * * * " << endl;
  cout << "Testing reverseRecursive. Reversing list." << endl;
  cout << "list before reverseRecursive: " << endl;
  list.print();
  list.reverseRecursive();
  cout << "list after reverseRecursive: " << endl;
  list.print();
  
  cout << endl;
  cout << "Testing reverseIterative. Reversing list back." << endl;
  cout << "list before reverseIterative: " << endl;
  list.print();
  list.reverseIterative();
  cout << "list after reverseIterative: " << endl;
  list.print();

  
/************  clear  ********************/
  cout << endl << endl;
  cout << " * * * * * * * * * * * * * * * * * * * * " << endl;
  cout << "Testing clear()" << endl;
  list.clear();
  list2.clear();
  list3.clear();
  list4.clear();
  list5.clear();
  
  cout << "list size: " << list.size() << endl;
  cout << "list2 size: " << list2.size() << endl;
  cout << "list3 size: " << list3.size() << endl;
  cout << "list4 size: " << list4.size() << endl;
  cout << "list5 size: " << list5.size() << endl;
 
cout << endl << endl;
cout << "That's all folks! " << endl;
cout << "Good luck and Good night! "<< endl;

  
  
}