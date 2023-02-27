#include "deque.h"

deque createDeque(){
    deque deck = (deque)malloc(sizeof(struct Deque));
    if(deck != NULL){
        deck->first = NULL;
        deck->last = NULL;
        return deck;
    }
    return NULL;
}

node createNode(){
    node emptyNode = (node)malloc(sizeof(struct Node));
    if(emptyNode == NULL){
        return NULL;
    }
    emptyNode->data = NULL;
    emptyNode->next = NULL;
    emptyNode->previous = NULL;
    return emptyNode;
}

int emptyDeque(deque deck){
    if(deck->first == NULL && deck->last == NULL){
        return 1;
    }
    return 0;
}

int fullDeque(deque deck){
    if(deck->first != NULL && deck->last != NULL){
        return 1;
    }
    return 0;
}

int pushFront(deque *deck, info input){
    node newNode = createNode();
    if(newNode != NULL){
        newNode->data = input;
        newNode->next = (*deck)->first;
        if(emptyDeque(*deck) == 1){
            (*deck)->last = newNode;
        }else{
            (*deck)->first->previous = newNode;
        }
        (*deck)->first = newNode;
        return 0;
    }
    return 1;
}

int pushBack(deque *deck, info input){
    node newNode = createNode();
    if(newNode != NULL){
        newNode->data = input;
        newNode->previous = (*deck)->last;
        if(emptyDeque(*deck) == 1){
            (*deck)->first = newNode;
        }else{
            (*deck)->last->next = newNode;
        }
        (*deck)->last = newNode;
        return 0;
    }
    return 1;
}

info popFront(deque *deck){
    if(emptyDeque(*deck) != 1){
        info content = (*deck)->first->data;
        node first = (*deck)->first;
        if((*deck)->first == (*deck)->last){
            (*deck)->first = NULL;
            (*deck)->last = NULL;
        }else{
            if((*deck)->first->next == (*deck)->last){
                (*deck)->first = (*deck)->last;
            }else{
                (*deck)->first = (*deck)->first->next;
            }
        }
        free(first);
        return content;
    }
    return NULL;
}

info popBack(deque *deck){
    if(emptyDeque(*deck) != 1){
        info content = (*deck)->last->data;
        node last = (*deck)->last;
        if((*deck)->first == (*deck)->last){
            (*deck)->first = NULL;
            (*deck)->last = NULL;
        }else{
            if((*deck)->last->previous == (*deck)->first){
                (*deck)->last = (*deck)->first;
            }else{
                (*deck)->last = (*deck)->last->previous;
            }
        }
        free(last);
        return content;
    }
    return NULL;
}

void deleteDeque(deque *deck){
    if(emptyDeque(*deck) == 1){
        free(deck);
        return;
    }
    node current = (*deck)->first;
    node next = (*deck)->first;
    while(current != NULL){
        next = current;
        current = current->next;
        free(next);
    }
    free(deck);
    return;
}

int nodesInDeque(deque deck){
    if(emptyDeque(deck) == 1)
        return 0;
    if(deck->first == deck->last){
        return 1;
    }else{
        int counter = 0;
        node holder = deck->first;
        while(holder != NULL){
            ++counter;
            holder = holder->next;
        }
        return counter;
    }
    return -1;
}

info dataFirstNode(deque deck){
    if(emptyDeque(deck) != 1){
        return deck->first->data;
    }else{
        return NULL;
    }
}

info dataLastNodde(deque deck){
    if(emptyDeque(deck) != 1){
        return deck->last->data;
    }else{
        return NULL;
    }
}

