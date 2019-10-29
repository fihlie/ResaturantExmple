/*
Student Name:
Student Number:
Project Number: 2
Compile Status: [SUCCESS/FAIL]
Running Status: [SUCCESS/FAIL]
Notes: Anything you want to say about your code that will be helpful in the grading process.
*/
#include "RestaurantOrganizer.h"

using namespace std;

RestaurantOrganizer::RestaurantOrganizer(const vector<int>& tableCapacityInput){
    numberOfTables = tableCapacityInput.size();
    for(int i=0;i<numberOfTables;i++){
        tableCapacity[i] = tableCapacityInput[i];
        heap[i] = i;
        heapUp(i);
    }
}

void RestaurantOrganizer::addNewGroup(int groupSize, ofstream& outFile){
    // IMPLEMENT ME!
    if(tableCapacity[heap[0]]<groupSize){
        outFile<<-1<<endl;
    }
    else{
        tableCapacity[heap[0]]=tableCapacity[heap[0]]-groupSize;
        outFile<<heap[0]<<endl;
        heapDown(0);
    }


}
void swap( int *a, int *b ) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int getLeftChild(int index){
    if(index<50000){
        return 2*index+1;
    }
    else{
        return -1;
    }
}
int getRightChild(int index){
    if(index<49999){
        return 2*index+2;
    }
    else{
        return -1;
    }
}
int getParent(int index){
    return (index-1)/2;
}

void RestaurantOrganizer::heapUp(int index){
    // IMPLEMENT ME!
        if(getParent(index)>=0){
            if(tableCapacity[heap[index]]>tableCapacity[heap[getParent(index)]]){
                swap(&heap[index],&heap[getParent(index)]);
                heapUp(getParent(index));
            }
        }
    }


void RestaurantOrganizer::heapDown(int index){
    // IMPLEMENT ME!
    if(getLeftChild(index)==-1){
    }
    else if(getRightChild(index)==-1){
        if(tableCapacity[heap[index]]<tableCapacity[heap[getLeftChild(index)]]){
            swap(&heap[index],&heap[getLeftChild(index)]);
        }
        else if(tableCapacity[heap[index]]==tableCapacity[heap[getLeftChild(index)]]){
            if(heap[index]>heap[getLeftChild(index)]){
                swap(&heap[index],&heap[getLeftChild(index)]);
            }
        }
    }
    else{
        if(tableCapacity[heap[getLeftChild(index)]]>tableCapacity[heap[getRightChild(index)]]){
            if(tableCapacity[heap[index]]<tableCapacity[heap[getLeftChild(index)]]){
                swap(&heap[index],&heap[getLeftChild(index)]);
                heapDown(getLeftChild(index));

            }
            else if(tableCapacity[heap[index]]==tableCapacity[heap[getLeftChild(index)]]){
                if(heap[index]>heap[getLeftChild(index)]){
                    swap(&heap[index],&heap[getLeftChild(index)]);
                    heapDown(getLeftChild(index));
                }
            }
        }
        else if(tableCapacity[heap[getLeftChild(index)]]<tableCapacity[heap[getRightChild(index)]]){
            if(tableCapacity[heap[index]]<tableCapacity[heap[getRightChild(index)]]){
                swap(&heap[index],&heap[getRightChild(index)]);
                heapDown(getRightChild(index));
            } else if(tableCapacity[heap[index]]==tableCapacity[heap[getRightChild(index)]]){
                if(heap[index]>heap[getRightChild(index)]){
                    swap(&heap[index],&heap[getRightChild(index)]);
                    heapDown(getRightChild(index));
                }
            }
        }
        else if(tableCapacity[heap[getLeftChild(index)]]==tableCapacity[heap[getRightChild(index)]]){
            if(heap[getLeftChild(index)]<heap[getRightChild(index)]){
                if(tableCapacity[heap[index]]<tableCapacity[heap[getLeftChild(index)]]){
                    swap(&heap[index],&heap[getLeftChild(index)]);
                    heapDown(getLeftChild(index));

                }
                else if(tableCapacity[heap[index]]==tableCapacity[heap[getLeftChild(index)]]){
                    if(heap[index]>heap[getLeftChild(index)]){
                        swap(&heap[index],&heap[getLeftChild(index)]);
                        heapDown(getLeftChild(index));
                    }
                }
            }
            if(heap[getRightChild(index)]<heap[getLeftChild(index)]){
                if(tableCapacity[heap[index]]<tableCapacity[heap[getRightChild(index)]]){
                    swap(&heap[index],&heap[getRightChild(index)]);
                    heapDown(getRightChild(index));
                } else if(tableCapacity[heap[index]]==tableCapacity[heap[getRightChild(index)]]){
                    if(heap[index]>heap[getRightChild(index)]){
                        swap(&heap[index],&heap[getRightChild(index)]);
                        heapDown(getRightChild(index));
                    }
                }
            }
        }
        else{
            if(heap[getLeftChild(index)]<heap[index]){
                swap(&heap[index],&heap[getLeftChild(index)]);
                heapDown(getLeftChild(index));
            }
            if(heap[getRightChild(index)]<heap[index]){
                swap(&heap[index],&heap[getRightChild(index)]);
                heapDown(getRightChild(index));
            }

        }
    }

}

void RestaurantOrganizer::printSorted(ofstream& outFile){
 // IMPLEMENT ME!
 for(int i=0;i<numberOfTables;i++){
     outFile<<tableCapacity[heap[0]]<<" ";
     tableCapacity[heap[0]]=0;
     heapDown(0);
 }

}


// YOU CAN ADD YOUR HELPER FUNCTIONS

