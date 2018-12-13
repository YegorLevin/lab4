//#include "stdafx.h"
//#include "CppUnitTest.h"
//#include "../lag_lab4/sorting.h"
//#include "../../alg_lab3/alg_lab3/TreeClass.h"
//
//using namespace Microsoft::VisualStudio::CppUnitTestFramework;
//
//namespace UnitTests
//{
//	TEST_CLASS(QuickSortTests)
//	{
//	public:
//
//		size_t size = 10;
//		int * a = new int[size];
//
//		//Тест последовательности с одинаковыми элементами
//		TEST_METHOD(QuickSortEqualElemsTest)
//		{
//			int k = size - 1;
//			for (size_t i = 0; i < size; ++i)
//			{
//				a[i] = k;
//				--k;
//			}
//
//			a[size - 2] = 1;
//			a[size - 1] = 1;
//
//			quickSort(a, 0, size - 1);
//
//			for (size_t i = 2; i < size; ++i)
//				Assert::IsTrue(i == a[i]);
//			Assert::IsTrue(a[0] == 1 && a[1] == 1);
//		}
//
//		//Обычный тест неупорядоченной последовательности
//		TEST_METHOD(QuickSortNormalTest)
//		{
//			int k = size - 1;
//			for (size_t i = 0; i < size; ++i)
//			{
//				a[i] = k;
//				--k;
//			}
//
//			quickSort(a, 0, size - 1);
//
//			for (size_t i = 0; i < size; ++i)
//				Assert::IsTrue(i == a[i]);
//		}
//
//		//Сортировка массива с одним элементом
//		TEST_METHOD(QuickSortOneElemTest)
//		{
//			size = 1;
//			int k = size - 1;
//			for (size_t i = 0; i < size; ++i)
//			{
//				a[i] = k;
//				--k;
//			}
//
//			quickSort(a, 0, size - 1);
//
//			for (size_t i = 0; i < size; ++i)
//				Assert::IsTrue(i == a[i]);
//		}
//
//		//Тест пустой последовательности
//		TEST_METHOD(QuickSortEmptyTest)
//		{
//			try
//			{
//				quickSort(a, 0, size - 1);
//			}
//			catch (const char * exception)
//			{
//				Assert::IsTrue(exception == "TheArrayIsEmpty");
//			}
//		}
//
//		//Тест правая граница меньше левой
//		TEST_METHOD(QuickSortLeftMoreRightTest)
//		{
//			try
//			{
//				delete[] a;
//				quickSort(a, size - 1, 0);
//			}
//			catch (const char * exception)
//			{
//				Assert::IsTrue(exception == "TheArrayIsEmpty");
//			}
//		}
//
//	};
//
//	
//
//	TEST_CLASS(CountingSortTests)
//	{
//	public:
//
//		size_t size = 10;
//		char * a = new char[size];
//
//		//Тест последовательности с одинаковыми элементами
//		TEST_METHOD(CountingSortEqualElemsTest)
//		{
//			int k = size - 1;
//			for (size_t i = 0; i < size; ++i)
//			{
//				a[i] = k;
//				--k;
//			}
//
//			a[size - 2] = 1;
//			a[size - 1] = 1;
//
//			countingSort(a, size);
//
//			for (size_t i = 2; i < size; ++i)
//				Assert::IsTrue(i == a[i]);
//			Assert::IsTrue(a[0] == 1 && a[1] == 1);
//		}
//
//		//Обычный тест неупорядоченной последовательности
//		TEST_METHOD(CountingSortNormalTest)
//		{
//			int k = size - 1;
//			for (size_t i = 0; i < size; ++i)
//			{
//				a[i] = k;
//				--k;
//			}
//
//			countingSort(a, size);
//
//			for (size_t i = 0; i < size; ++i)
//				Assert::IsTrue(i == a[i]);
//		}
//
//		//Сортировка массива с одним элементом
//		TEST_METHOD(CountingSortOneElemTest)
//		{
//			size = 1;
//			int k = size - 1;
//			for (size_t i = 0; i < size; ++i)
//			{
//				a[i] = k;
//				--k;
//			}
//
//			countingSort(a, size);
//
//			for (size_t i = 0; i < size; ++i)
//				Assert::IsTrue(i == a[i]);
//		}
//
//		//Тест пустой последовательности
//		TEST_METHOD(CountingSortEmptyTest)
//		{
//			try
//			{
//				delete[] a;
//				countingSort(a, size);
//			}
//			catch (const char * exception)
//			{
//				Assert::IsTrue(exception == "TheArrayIsEmpty");
//			}
//		}
//
//	};
//
//
//	TEST_CLASS(BinarySearchTests)
//	{
//	public:
//
//		size_t size = 20;
//		int * a = new int[size];
//
//		//Поиск индексов входящих элементов
//		TEST_METHOD(BinarySearchContainedTest)
//		{
//			int k = size - 1;
//			for (size_t i = 0; i < size; ++i)
//			{
//				a[i] = k;
//				--k;
//			}
//
//			quickSort(a, 0, size - 1);
//
//			for (size_t i = 1; i < size; ++i)
//				Assert::IsTrue(binarySearch(size, a, i) == i);
//		}
//
//		//Поиск индексов не входящих элементов
//		TEST_METHOD(BinarySearchNotContainedTest)
//		{
//			int k = size - 1;
//			for (size_t i = 0; i < size; ++i)
//			{
//				a[i] = k;
//				--k;
//			}
//
//			quickSort(a, 0, size - 1);
//
//			try
//			{
//				binarySearch(size, a, size + 1);
//			}
//			catch (const char * exception)
//			{
//				Assert::IsTrue(exception == "ElemNotFound");
//			}
//		}
//
//		//Поиск индекса в последовательности из одного элемента
//		TEST_METHOD(BinarySearchOneElemTest)
//		{
//			size = 1;
//			int k = size - 1;
//			for (size_t i = 0; i < size; ++i)
//			{
//				a[i] = k;
//				--k;
//			}
//
//			quickSort(a, 0, size - 1);
//
//			for (size_t i = 1; i < size; ++i)
//				Assert::IsTrue(binarySearch(size, a, i) == i);
//		}
//
//		//Поиск индекса в пустой последовательности
//		TEST_METHOD(BinarySearchEmptyTest)
//		{
//			try
//			{
//				delete[] a;
//				binarySearch(size, a, size + 1);
//			}
//			catch (const char * exception)
//			{
//				Assert::IsTrue(exception == "ElemNotFound");
//			}
//		}
//	};
//	TEST_CLASS(insertionSortTests)
//	{
//	public:
//		size_t size = 20;
//		int * a = new int[size];
//
//		TEST_METHOD(insertionSortNormalTest)
//		{
//			int k = size - 1;
//			for (size_t i = 0; i < size; ++i)
//			{
//				a[i] = k;
//				--k;
//			}
//
//			insertionSort(a, size);
//
//			for (size_t i = 0; i < size; ++i)
//				Assert::IsTrue(i == a[i]);
//		}
//
//		TEST_METHOD(insertionSortOneElemTest)
//		{
//			size = 1;
//			int k = size - 1;
//			for (size_t i = 0; i < size; ++i)
//			{
//				a[i] = k;
//				--k;
//			}
//
//			insertionSort(a, size);
//
//			for (size_t i = 0; i < size; ++i)
//				Assert::IsTrue(i == a[i]);
//		}
//
//		TEST_METHOD(insertionSortEqualElemsTest)
//		{
//			int k = size - 1;
//			for (size_t i = 0; i < size; ++i)
//			{
//				a[i] = k;
//				--k;
//			}
//
//			a[size - 2] = 1;
//			a[size - 1] = 1;
//
//			insertionSort(a, size);
//
//			for (size_t i = 2; i < size; ++i)
//				Assert::IsTrue(i == a[i]);
//			Assert::IsTrue(a[0] == 1 && a[1] == 1);
//		}
//	};
//
//
//
//	
//	TEST_CLASS(BogoSortTests)
//	{
//	public:
//
//		size_t size = 3;
//		int * a = new int[size];
//
//		//Тест последовательности с одинаковыми элементами
//		
//		TEST_METHOD(BogoSortEqualElemsTest)
//		{
//			int k = size - 1;
//			for (size_t i = 0; i < size; ++i)
//			{
//				a[i] = k;
//				--k;
//			}
//
//			a[size - 2] = 1;
//			a[size - 1] = 1;
//
//			bogoSort(a, size);
//
//			for (size_t i = 2; i < size; ++i)
//				Assert::IsTrue(i == a[i]);
//			Assert::IsTrue(a[0] == 1 && a[1] == 1);
//		}
//		
//		//Обычный тест неупорядоченной последовательности
//		TEST_METHOD(BogoSortNormalTest)
//		{
//			int k = size - 1;
//			for (size_t i = 0; i < size; ++i)
//			{
//				a[i] = k;
//				--k;
//			}
//
//			bogoSort(a, size);
//
//			for (size_t i = 0; i < size; ++i)
//				Assert::IsTrue(i == a[i]);
//		}
//		
//		//Сортировка массива с одним элементом
//		TEST_METHOD(BogoSortOneElemTest)
//		{
//			size = 1;
//			int k = size - 1;
//			for (size_t i = 0; i < size; ++i)
//			{
//				a[i] = k;
//				--k;
//			}
//
//			bogoSort(a, size);
//
//			for (size_t i = 0; i < size; ++i)
//				Assert::IsTrue(i == a[i]);
//		}
//
//		//Тест пустой последовательности
//		TEST_METHOD(BogoSortEmptyTest)
//		{
//			try
//			{
//				delete[] a;
//				bogoSort(a, size);
//			}
//			catch (const char * exception)
//			{
//				Assert::IsTrue(exception == "TheArrayIsEmpty");
//			}
//		}
//
//		
//
//	};
//	/*
//	TEST_CLASS(TreeSortTests)
//	{
//	public:
//
//		size_t size = 5;
//		int * a = new int[size];
//		TreeClass * tree;
//
//		TEST_METHOD_INITIALIZE(SetUp)
//		{
//			tree = new TreeClass;
//			//Iterator * iterator = tree->create_dft_iterator();
//		}
//		TEST_METHOD_CLEANUP(CleanUp)
//		{
//			//delete tree;
//			//delete iterator;
//		}
//
//		//Тест последовательности с одинаковыми элементами
//
//		TEST_METHOD(TreeSortEqualElemsTest)
//		{
//			int k = size - 1;
//			for (size_t i = 0; i < size; ++i)
//			{
//				a[i] = k;
//				--k;
//			}
//
//			a[size - 2] = 1;
//			a[size - 1] = 1;
//
//			for (int i = 0; i < size; i++)
//			{
//				tree->insert(a[i]);
//			}
//			
//		//	treeSortHelper(a, size);
//
//			for (size_t i = 2; i < size; ++i)
//				Assert::IsTrue(i == a[i]);
//			Assert::IsTrue(a[0] == 1 && a[1] == 1);
//		}
//		
//	}; */
//}