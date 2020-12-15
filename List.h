#pragma once
#include<iostream>

struct Node
{
	int data;
	Node* next;
};
struct List
{
	Node* head;
	Node* tail;
	size_t size;
};
void initList(List&);

void pushBack(List&, int);
void pushFront(List&, int);
void pushPosition(List&, int, size_t);

int popFront(List&);
int popBack(List&);

void removeKey(List&, int);
int removePosition(List&, int);

void printList(const List&);

void addSort(List&, int);
