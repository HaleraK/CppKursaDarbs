// C++ program to perform TimSort. 
#pragma once
#include <string>
#include <vector>
#include <algorithm> 

#include "TimsortDrawing.h"
#include "Drawing.h"
#include "Menu.h"

using std::string;
using std::vector;

// this function sorts array from left index to 
// to right index which is of size atmost RUN 
void insertionSortDrawings(int type, int left, int right) {
	for (int i = left + 1; i <= right; i++) {
		Drawing tmp = drawings()[i];
		int j = i - 1;

		switch (type) {
		case (1): {
			//userNick
			while (drawings()[j].getUserNick() > tmp.getUserNick() && j >= left) {
				drawings()[j + 1] = drawings()[j];
				j--;
			}
			break;
		}
		case (2): {
			//id
			while (drawings()[j].getId() > tmp.getId() && j >= left) {
				drawings()[j + 1] = drawings()[j];
				j--;
			}
			break;
		}
		case (3): {
			//title
			while (drawings()[j].getTitle() > tmp.getTitle() && j >= left) {
				drawings()[j + 1] = drawings()[j];
				j--;
			}
			break;
		}
		case (4): {
			//fileName
			while (drawings()[j].getFileName() > tmp.getFileName() && j >= left) {
				drawings()[j + 1] = drawings()[j];
				j--;
			}
			break;
		}
		case (5): {
			//dataAndTimeOfAdd
			while (drawings()[j].getDateAndTimeOfAdd() > tmp.getDateAndTimeOfAdd() && j >= left) {
				drawings()[j + 1] = drawings()[j];
				j--;
			}
			break;
		}
	}

		drawings()[j + 1] = tmp;
	}
}

// merge function merges the sorted runs 
void mergeDrawings(int type, int l, int m, int r) {
	// original array is broken in two parts 
	// left and right array 
	int len1 = m - l + 1, len2 = r - m;

	vector<Drawing> left(len1);
	vector<Drawing> right(len2);

	for (int i = 0; i < len1; i++)
		left[i] = drawings()[l + i];
	for (int i = 0; i < len2; i++)
		right[i] = drawings()[m + 1 + i];

	int i = 0;
	int j = 0;
	int k = l;

	// after comparing, we merge those two array 
	// in larger sub array 
	while (i < len1 && j < len2) {
		switch (type) {
		case (1): {
			//userNick
			if (left[i].getUserNick() <= right[j].getUserNick()) {
				drawings()[k] = left[i];
				i++;
			}
			else {
				drawings()[k] = right[j];
				j++;
			}
			break;
		}
		case (2): {
			//id
			if (left[i].getId() <= right[j].getId()) {
				drawings()[k] = left[i];
				i++;
			}
			else {
				drawings()[k] = right[j];
				j++;
			}
			break;
		}
		case (3): {
			//title
			if (left[i].getTitle() <= right[j].getTitle()) {
				drawings()[k] = left[i];
				i++;
			}
			else {
				drawings()[k] = right[j];
				j++;
			}
			break;
		}
		case (4): {
			//fileName
			if (left[i].getFileName() <= right[j].getFileName()) {
				drawings()[k] = left[i];
				i++;
			}
			else {
				drawings()[k] = right[j];
				j++;
			}
			break;
		}
		case (5): {
			//dataAndTimeOfAdd
			if (left[i].getDateAndTimeOfAdd() <= right[j].getDateAndTimeOfAdd()) {
				drawings()[k] = left[i];
				i++;
			}
			else {
				drawings()[k] = right[j];
				j++;
			}
			break;
		}
		}
		
		k++;
	}

	// copy remaining elements of left, if any 
	while (i < len1) {
		drawings()[k] = left[i];
		k++;
		i++;
	}

	// copy remaining element of right, if any 
	while (j < len2) {
		drawings()[k] = right[j];
		k++;
		j++;
	}
}

// iterative Timsort function to sort the 
// array[0...n-1] (similar to merge sort) 
void timSortDrawings(int type, int n) {
	// Sort individual subarrays of size RUN 
	for (int i = 0; i < n; i += RUN_d)
		insertionSortDrawings(type, i, min((i + 31), (n - 1)));

	// start merging from size RUN (or 32). It will merge 
	// to form size 64, then 128, 256 and so on .... 
	for (int size = RUN_d; size < n; size = 2 * size)
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
			mergeDrawings(type, left, mid, right);
		}
	}
}