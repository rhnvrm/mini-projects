/*
 * ha.c
 * 
 * program to modify an array passed to a function
 * 
 * Copyright 2015 Rohan Verma <hello@rohanverma.net>
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


void modify(int arr[], int size){
	
	for(int i = 0; i < size; i++) arr[i] *= 3;

}

int main()
{
	int arr[10];
	
	for(int i = 0; i < 10; i++){
		scanf("%d", &arr[i]);
	}	
	
	modify(arr, 10);
	
	for(int i = 0; i< 10; i++) printf("%d\t", arr[i]);
	
	return 0;
}

