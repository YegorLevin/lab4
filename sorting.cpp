#include "pch.h"
#include "sorting.h"
#include <random>
#include <ctime>
#include "../../alg_lab3/alg_lab3/TreeClass.h"
#include "../../alg_lab3/alg_lab3/QueueClass.h"
#include "../../alg_lab3/alg_lab3/Iterator.h"
#include "../../alg_lab3/alg_lab3/TreeNode.h"


size_t binarySearch(size_t arraySize, int * array, int elem) //�������� �����
{
	
	size_t first = 0;//������ ������� �������
	
	size_t size = arraySize; //������ �������

	
	if (array == nullptr || arraySize == 0) //���� ������ ����
		throw "TheArrayIsEmpty";
	
	else if (array[0] > elem || array[arraySize - 1] < elem) //���� ������� ������� ������ ��� ������ ���� ��������� ������� 
		throw "ElemNotFound";

	
	


	
	while (first < size) //����� � ����������� ���������
	{
		
		size_t mid = first + (size - first) / 2; //�������� ���������

		if (elem <= array[mid])
			size = mid;
		else
			first = mid + 1;
	}

	if (array[size] == elem)
		return size;
	else
		throw "ElemNotFound";
}




void quickSort(int * array, size_t left, size_t right) //������� ����������
{
	
	if (array == nullptr || left > right) //���� ������ ����
		throw "TheArrayIsEmpty";

	int pivot; // ����������� �������
	size_t l_hold = left; // ����� �������
	size_t r_hold = right; // ������ �������
	pivot = array[left];

	while (left < right) // ���� ������� �� ���������
	{
		while ((array[right] >= pivot) && (left < right))
			--right; // �������� ������ ������� ���� ������� [right] ������ [pivot]

		if (left != right) // ���� ������� �� ����������
		{
			array[left] = array[right]; // ���������� ������� [right] �� ����� ������������
			++left; // �������� ����� ������� ������ 
		}

		while ((array[left] <= pivot) && (left < right))
			++left; // �������� ����� ������� ���� ������� [left] ������ [pivot]

		if (left != right) // ���� ������� �� ����������
		{
			array[right] = array[left]; // ���������� ������� [left] �� ����� [right]
			--right; // �������� ������ ������� ������ 
		}
	}

	array[left] = pivot; // ������ ����������� ������� �� �����
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot) // ���������� �������� ���������� ��� ����� � ������ ����� �������
		quickSort(array, left, pivot - 1);
	if (right > pivot)
		quickSort(array, pivot + 1, right);
}



void quickSort(int * array, size_t right) //������� ����������
{
	quickSort(array, 0, right);
}

bool is_sorted(int * array, size_t size)
{
	bool is_sorted = 1;
	for (int i = 0; i < size-1; i++)
	{
		if (array[i] > array[i + 1])
			is_sorted = 0;
	}
	return is_sorted;
}

void bogoSort(int* array, size_t size) {
	if (array == nullptr || size == 0)
		throw "Array is empty";

	while (!is_sorted(array, size)) {
		for (int i = 0; i < size; i++) {
			srand(time(0));
			int index1 = rand() % size;
			int index2 = rand() % size;
			int temp = array[index1];
			array[index1] = array[index2];
			array[index2] = temp;
		}
	}
}



void countingSort(char * array, size_t arraySize) { //���������� ���������


	if (array == nullptr || arraySize == 0)	//���� ������ ����
		throw "TheArrayIsEmpty";

	int min, max;
	min = max = array[0];
	for (size_t index = 1; index < arraySize; index++) {
		if (array[index] > max) max = array[index];
		if (array[index] < min) min = array[index];
	}

	int * counter = new int[max - min + 1];

	for (int i = min; i <= max; ++i)
		counter[i - min] = 0;

	for (int i = 0; i < arraySize; ++i)
		++counter[array[i] - min];

	for (int i = min; i <= max; ++i)
		for (int j = counter[i - min]; j--;)
			*array++ = i;

	delete[] counter;
}


void insertionSort(int array[], size_t size) // c��������� ��������� 
{
	for (int i = size-1; i > 0; i--) // ���������� ������������ �������� � ��������� ��� � ������ 
	if (array[i] < array[i - 1])
	{
		int temp = array[i - 1];
		array[i - 1] = array[i];
		array[i] = temp;
	}
			
	// ���������� ��������
	for (int i = 2; i < size; i++)
	{
		int j = i;
		int cur = array[j]; 
		while (array[j - 1] > cur) //���� ����� ���� �������� �������
		{
			array[j] = array[j - 1];
			j--;
		}
		array[j] = cur; // ������� ��������
	}
}



//
//int treeSort(TreeNode * head, int * array1, int number)
//{
//	if (head)
//	{
//		number = treeSort(head->left, array1, number);
//		array1[number++] = head->key; // ���������� �������� � ������
//		number = treeSort(head->right, array1, number);
//	}
//	return number;
//}
//
//void treeSortHelper(int * array1, size_t size)
//{
//	TreeClass * tree = new TreeClass;
//	for (int i = 0; i < size; i++)
//	{
//		tree->insert(array1[i]);
//	}
//	treeSort(tree->head, array1,0);
//}

/*
void treeprint(TreeNode * tree)
{
	if (tree != NULL) {      //���� �� ���������� ������ ����
		treeprint(tree->left);  //����������� ������� ������ ������ ���������
		cout << tree->key << " "; //���������� ������ ������
		treeprint(tree->right); //����������� ������� ������ ������� ���������
	}
}

void TreeSort(int array [], size_t size)
{
	TreeClass * tree = new TreeClass;
	for (int i = 0; i < size; i++)
	{
		tree->insert(array[i]);
	}

	*/


void tree_sort_rec(TreeNode* head, Queue* tree_node_queue)
{
	if (head) { //���� �� ���������� ������ ����
		tree_sort_rec(head->left, tree_node_queue);  //����������� ������� ������ ������ ���������
		tree_node_queue->push_back(head); //������ �������� � ������
		tree_sort_rec(head->right, tree_node_queue); //����������� ������� ������ ������� ���������
	}
}
//���������� ������� � ������� ��������� ������ ������
void Tree_Sort(int* arr, int arr_size) {
	TreeClass* Tree = arr_to_tree(arr, arr_size); //�������� ������
	Queue* tree_node_queue = new Queue(); //�������� �������
	tree_sort_rec(Tree->head, tree_node_queue); //����� ����������� ������� ���������� � �������
	//tree_node_queue->pop_front(); //�������� �� ������� ������� �������� 
	//(����� ������, ������� ��������� ������, �� - �� �������� ������� � ������������ ������ ����������� ������� � ����� � ��� �� ���������)
	for (int i = 0; i < arr_size; i++) //�������� ������ �� ������� � ������
	{
		TreeNode * temp = tree_node_queue->pop_front();
		arr[i] = temp->get_key();
	}
		

	delete Tree;
	delete tree_node_queue;
}
//������� �������� ������ �� �������
TreeClass* arr_to_tree(int* arr, int arr_size) {
	TreeClass* Tree = new TreeClass;
	for (int i = 0; i < arr_size; i++) {
		Tree->insert(arr[i]);
	}
	return Tree;
}