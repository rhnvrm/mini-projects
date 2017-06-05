/*
 * lb.c
 * 
 * transpose of a matrix
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
#include <limits.h>

void swap(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

int transpose(int arr[][10], int l, int b){

	int max = INT_MIN;
	for(int i = 0; i < l; i++){
		for (int j = 0; j < b; j++){
			if(i > j){
				swap(&arr[i][j], &arr[j][i]);
			}
		}
	}


	return max;
}

int main(int argc, char **argv)
{
	int input[10][10];
	
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			scanf("%d", &input[i][j]);
		}
	}
	
	transpose(input,4,4);
	
	for(int i = 0; i< 4; i++){
		printf("\n");
		for(int j = 0; j< 4; j++){
			printf("%d\t", input[i][j]);
		}
	}
	
	return 0;
}

