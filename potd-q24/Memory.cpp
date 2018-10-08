#include "Memory.h"
#include <iostream>
#include <iomanip>
#include "Node.h"
#include <vector>
#include <utility>

using namespace std;

/**
Frees the given memory address. Returns if the free was successful or not
Be sure to merge adjacent free blocks when possible
*/
bool Memory::free(unsigned address) {
    Node* current = head;
    while (current != NULL) {
        if (current->address == address) {
            // Your code there
///////////////////////////////////////////////////////////////////
            /*current->inUse = false;
            Node* temp = current;
            if(temp->previous == NULL && temp->next->inUse == false){
              temp->next = temp->next->next;
              temp->next->previous = temp->previous;
            }
            else if(temp->next == NULL && temp->previous->inUse == false){
              temp->previous->next = temp->next;
              temp->previous = temp->previous->previous;
            }
            else if(temp->previous->inUse == false && temp->next->inUse == false){

            }
            //while(temp != NULL){
              if(temp->previous == NULL && temp->next->inUse == false){
                temp->next = temp->next->next;
                //temp->next->previous = temp->previous;
                //temp->next->previous = temp;
                //break;
              }
              else if(temp->previous->inUse == true && temp->next->inUse == false){
                temp->next = temp->next->next;
                //temp->next->previous = temp->previous;
                //temp->next->previous = temp;
                //break;
              }
              else if(temp->previous->inUse == false && temp->next->inUse == false){
                Node *temp1 = temp->next;
                temp->previous->next = temp->next->next;
                temp->next = temp->next->next;
                //temp->next->previous = temp->previous->previous;
                temp->next->previous = temp->previous;
                temp1->previous = temp->previous;
                //break;
              }
              else if(temp->next == NULL && temp->previous->inUse == false){
                //temp->previous->next = temp->next;
                //temp->previous = temp->previous->previous;
                temp->previous = temp->previous->previous;
                //temp->previous->next = temp;
                //break;
              }
              else if(temp->next->inUse == true && temp->previous->inUse == false){
                //temp->previous = temp->previous->previous;
                //temp->previous->next = temp->next;
                temp->previous = temp->previous->previous;
                //temp->previous->next = temp;
                //break;
              }
              else if(temp->previous == NULL && temp->next->inUse == true){
                head = temp->next;
                temp->next->previous = NULL;
              }
              else if(temp->next == NULL && temp->previous->inUse == true){
                temp->previous->next = NULL;

              }
            //}*/
///////////////////////////////////////////////////////////////////
            current -> inUse = false;
            if (current -> next != NULL && current -> next -> inUse == false){
              current -> next = current -> next -> next;
              if (current -> next -> next != NULL){
                current -> next -> next -> previous = current;
              }
            }
            if (current -> previous != NULL && current -> previous -> inUse == false){
              current -> previous -> next = current -> next;
              if (current -> next != NULL) current -> next -> previous = current -> previous;
            }
            return true;
        }
        current = current->next;
    }

    return false;
}


/**
Reorganizes memory structure so that all of the allocated memory is grouped at the bottom (0x0000) and there is one large
TempMemory of free memory above.

Note: We do not care about the order of the allocated memory TempMemorys
*/
void Memory::defragment() {
    Node* current = head;
    while (current != NULL) {

        if (current->inUse) {
            // Do nothing
        } else {
            // TODO: Find the next chunk of allocated memory and shift it down to current's address
            // We recommend using the helper function `findNextAllocatedMemoryChunk

            // Your code here
            Node* TempMemory = findNextAllocatedMemoryChunk(current);
            if(TempMemory != NULL){
              size_t chSize = getSize(TempMemory);
              current -> inUse = true;
              current -> next -> address = current -> address + chSize;
              unsigned temp = TempMemory -> address;
              TempMemory -> address = current -> next -> address;
              TempMemory -> inUse = false;
              TempMemory -> previous = current;
              free(temp);
            }
        }

        current = current->next;
    }

    // TODO: Finally merge all of the free blocks of memory together
}
