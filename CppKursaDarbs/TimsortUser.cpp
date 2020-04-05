// C++ program to perform TimSort. 
#pragma once
#include <string>
#include <vector>
#include <algorithm> 

#include "TimsortUser.h"
#include "TimsortDrawing.h"
#include "User.h"
#include "Menu.h"

using std::string;
using std::vector;

// this function sorts array from left index to 
// to right index which is of size atmost RUN 
void insertionSortUsers(int type, int left, int right) {
	for (int i = left + 1; i <= right; i++) {
		User tmp = users()[i];
		int j = i - 1;

		switch (type) {
		case (1): {
			//name
			while (users()[j].getName() > tmp.getName() && j >= left) {
				users()[j + 1] = users()[j];
				j--;
			}
			break;
		}
		case (2): {
			//surname
			while (users()[j].getSurname() > tmp.getSurname() && j >= left) {
				users()[j + 1] = users()[j];
				j--;
			}
			break;
		}
		case (3): {
			//nick
			while (users()[j].getNick() > tmp.getNick() && j >= left) {
				users()[j + 1] = users()[j];
				j--;
			}
			break;
		}
		case (4): {
			//login
			while (users()[j].getLogin() > tmp.getLogin() && j >= left) {
				users()[j + 1] = users()[j];
				j--;
			}
			break;
		}
		case (5): {
			//password
			while (users()[j].getPassword() > tmp.getPassword() && j >= left) {
				users()[j + 1] = users()[j];
				j--;
			}
			break;
		}
		case (6): {
			//dateOfReg
			while (users()[j].getDateOfReg() > tmp.getDateOfReg() && j >= left) {
				users()[j + 1] = users()[j];
				j--;
			}
			break;
		}
	}

		users()[j + 1] = tmp;
	}
}

// merge function merges the sorted runs 
void mergeUsers(int type, int l, int m, int r) {
	// original array is broken in two parts 
	// left and right array 
	int len1 = m - l + 1, len2 = r - m;

	vector<User> left(len1);
	vector<User> right(len2);

	for (int i = 0; i < len1; i++)
		left[i] = users()[l + i];
	for (int i = 0; i < len2; i++)
		right[i] = users()[m + 1 + i];

	int i = 0;
	int j = 0;
	int k = l;

	// after comparing, we merge those two array 
	// in larger sub array 
	while (i < len1 && j < len2) {
		switch (type) {
		case (1): {
			//name
			if (left[i].getName() <= right[j].getName()) {
				users()[k] = left[i];
				i++;
			}
			else {
				users()[k] = right[j];
				j++;
			}
			break;
		}
		case (2): {
			//surname
			if (left[i].getSurname() <= right[j].getSurname()) {
				users()[k] = left[i];
				i++;
			}
			else {
				users()[k] = right[j];
				j++;
			}
			break;
		}
		case (3): {
			//nick
			if (left[i].getNick() <= right[j].getNick()) {
				users()[k] = left[i];
				i++;
			}
			else {
				users()[k] = right[j];
				j++;
			}
			break;
		}
		case (4): {
			//login
			if (left[i].getLogin() <= right[j].getLogin()) {
				users()[k] = left[i];
				i++;
			}
			else {
				users()[k] = right[j];
				j++;
			}
			break;
		}
		case (5): {
			//password
			if (left[i].getPassword() <= right[j].getPassword()) {
				users()[k] = left[i];
				i++;
			}
			else {
				users()[k] = right[j];
				j++;
			}
			break;
		}
		case (6): {
			//dateOfReg
			if (left[i].getDateOfReg() <= right[j].getDateOfReg()) {
				users()[k] = left[i];
				i++;
			}
			else {
				users()[k] = right[j];
				j++;
			}
			break;
		}
		}
		
		k++;
	}

	// copy remaining elements of left, if any 
	while (i < len1) {
		users()[k] = left[i];
		k++;
		i++;
	}

	// copy remaining element of right, if any 
	while (j < len2) {
		users()[k] = right[j];
		k++;
		j++;
	}
}

// iterative Timsort function to sort the 
// array[0...n-1] (similar to merge sort) 
void timSortUsers(int type, int n) {
	// Sort individual subarrays of size RUN 
	for (int i = 0; i < n; i += RUN_u)
		insertionSortUsers(type, i, min((i + 31), (n - 1)));

	// start merging from size RUN (or 32). It will merge 
	// to form size 64, then 128, 256 and so on .... 
	for (int size = RUN_u; size < n; size = 2 * size)
	{
		// pick starting point of left sub array. We 
		// are going to merge arr[left..left+size-1] 
		// and arr[left+size, left+2*size-1] 
		// After every merge, we increase left by 2*size 
		for (int left = 0; left < n; left += 2 * size)
		{
			// find ending point of left sub array 
			// mid+1 is starting point of right sub array 
			int mid = left + size - 1;
			int right = min((left + 2 * size - 1), (n - 1));

			// merge sub array arr[left.....mid] & 
			// arr[mid+1....right] 
			mergeUsers(type, left, mid, right);
		}
	}
}