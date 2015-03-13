/*
 * la.c
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

int max_arr(int arr[][5], int l, int b){

	int max = INT_MIN;
	
	for(int i = 0; i < l; i++){
		for (int j = 0; j < b; j++){
			if(max < arr[i][j]) max = arr[i][j];
		}
	}


	return max;
}

int main(int argc, char **argv)
{
	int input[5][5];
	
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			scanf("%d", &input[i][j]);
		}
	}
	
	printf("\nMAX: %d\n", max_arr(input,5,5));
	
	return 0;
}

