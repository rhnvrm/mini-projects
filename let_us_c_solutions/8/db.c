/*
 * db.c
 * Input: 25 Numbers stored in a array
 * Output: Sort using 1. Selection Sort 2. Bubble Sort 3. Insertion Sort
 * 
 * Copyright 2015 Rohan Verma <rohanverma2004@gmail.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include <limits.h>

void swap(int * a, int * b){
	int t = *a;
	*a = *b;
	*b = t;
}

void bubbleSort(int arr[], int size)
{
	for(int i = 0; i < size; i++){
		for(int j = i; j < size; j++){
			if(arr[i] > arr[j]) swap(arr[i], arr[j]);
		}
	}
}

void selectionSort(int arr[], int size)
{
	
}


int main()
{
	
	int input[30];
	int SIZE = 25;
	
	printf("\nInput %d Numbers\n", SIZE);
	
	for(int i = 0; i < SIZE; i++)
	{
		scanf("%d", &input[i]);
	}
	
	printf("%d", INT_MIN);
	
	
	return 0;
}

