// LinkedList.cpp

/************** copy constructor ***********************
performs a deep copy of list2*/
LinkedList::LinkedList(const LinkedList& list2){
       
  if (list2.head == NULL){ // the list to copy is empty
    head = NULL;
    tail = NULL;
  }
  else { // the list to copy isn't empty
    head = new Node;
    head->data = list2.head->data;
    head->next = NULL;
    Node* current1 = head;
    Node* current2 = list2.head->next;
    
    while(current2 != NULL){
      current1->next = new Node;
      current1->next->data = current2->data;
      current1->next->next = NULL;
      current1 = current1->next;
      current2 = current2->next;
    } //end while
    
    tail = current1;
  } //end else

}// end copy constructor


/************** insert ***********************
insert a new node into the list 
 set the data to the argument item */
void LinkedList::insert(int& item){

  Node* newNode = new Node;
  newNode->data = &item;

  //case: the list is empty
  if (head == NULL) {
     head = newNode;
     tail = newNode;
     newNode->next = NULL;
  }
  //insert the newNode at the head of the list
  else{
    newNode->next = head; 
    head = newNode;
  }
} // end insert


/************** find ***********************
finds the node with the data that matches item
returns a pointer to the node previous
if the node is the first node, it will return head
returns NULL if item is not found*/
Node* LinkedList::find(int& item){
    Node* current = head;
    Node* previous = head;
    
    while(current != NULL){
        if (*current->data == item)
          return previous;
        previous = current;
        current = current->next;
    }
    return NULL;
}// end find


/************** remove ***********************
    // deletes the node that matches item,
    // nothing if no nodes match */
void LinkedList::remove(int& item){

  Node* previous = find(item);
  if (previous != NULL){
    
    // delete first node
    if (previous == head){ // could be either the first or second node
      if (*previous->data == item){ //delete the 1st node
        head = head->next;
        delete previous;
      }
      else { // delete the second node
        Node* toDelete = previous->next;
        previous->next = toDelete->next;
        delete toDelete;
      }
    }
    else {
      Node* toDelete = previous->next;
      
        //if deleting the last node, move tail pointer
        if (toDelete->next == NULL)
          tail = previous;
          
        previous->next = toDelete->next;
        delete toDelete;          
    }

  }
  else
    cout << "item: " << item << " was NOT FOUND. " << endl; 
  
}
    


/************** size ***********************
 returns the number of nodes the list has */
int LinkedList::size(){
  Node* current = head;
  int size = 0;
  
  while (current != NULL){
      size++;
      current= current->next;
  }

  return size;
}//end size


/************** append ***********************
attaches a second list to the end of this list */
void LinkedList::append(LinkedList& list2){

  if (list2.head != NULL){
    if (head == NULL){
        head = list2.head;
        tail = list2.tail;
    }
    else {
      tail->next = list2.head;
      tail = list2.tail;
    }
  }

}//end append


/************** print ***********************
prints a the items from head to tail deliniated with a ->
*/
void LinkedList::print(){
  Node* current = head;
  
  if (size() != 0) {
    while (current != tail){
        cout << *current->data << " -> ";
        current= current->next;
    }
    
    // print the last one
    cout << *current->data << endl;
  }

}// end print


/************** clear ***********************
deletes all the nodes in the list.  
sets head and tail to NULL */
void LinkedList::clear(){

   Node* toDelete = head;
  while (head != NULL){
    head = head->next;
    delete toDelete;
    toDelete = head;
  }
  head = NULL;
  tail = NULL;
} //end clear


/************** recursive reverse   ***********************
recursively reverses the list so that the tail is the head and the 
head is the tail and every node in between is reversed
for example: 
input list:  5 4 3 2 1
output list: 1 2 3 4 5     */
void LinkedList::reverseRecursive(){
  // if the list is empty, or has only one node, no need to reverse
  if ((head != NULL) && (head->next != NULL))
    reverseR(head);
}// recursive reverse


// recursive function called by reverseRecursive()
void LinkedList::reverseR(Node* current){

  //base case
  if (current->next->next == NULL) {
    current->next->next = current;
    head = current->next;
  }
  else{  //recurse
    reverseR(current->next);
    current->next->next = current;
  }
  
  //configure tail
  tail = current;
  current->next = NULL;
}// end reverseR



/************** iterative reverse   ***********************
recursively reverses the list so that the tail is the head and the 
head is the tail and every node in between is reversed
for example: 
input list:  5 4 3 2 1
output list: 1 2 3 4 5     */
void LinkedList::reverseIterative(){

  // if the list is empty, or has only one node, no need to reverse
  if ((head != NULL) && (head->next != NULL)){
  
  
/*  head will always be at the head of the first directional list
    behind will keep track of the head of the new directional list
    current will be the node switching direction */
    if (head->next->next != NULL) { // more than 2 nodes
       tail = head;
       Node* current = head->next;
       Node* behind = tail;
       head = head->next->next;
    
       while(head != NULL){
         //switch the direction of the pointer
           current->next = behind;
           
           // advance pointers up one
           behind = current;
           current = head;
           head = head->next;
       }// end while
       
       //configure head and tail
       current->next = behind;
       head = current;
       tail->next = NULL;
    }// end if only 2 nodes
    else {
       tail->next = head;
       head = tail;
       tail = head->next;
       tail->next = NULL;
    }// end only 2 nodes
    
  }// end if list empty or only one node

}//end reverseI