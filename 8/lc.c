/*
 * lc.c
 * 
 * program to implement a 4x4 1 box missing puzzle game
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

int find_zero(int arr[][4], int l, int b)
{
	int pos = 0;
	
	for(int i = 0; i< 4; i++){
		printf("\n");
		for(int j = 0; j< 4; j++){
			printf("%d\t", a[i][j]);
		}
	}
	
	return
}
void clrscr()
{
	for(int i = 0; i < 24; i++){ printf("\n"); }
}

int main(int argc, char **argv)
{
	
	int a[4][4] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,0}};
	
	int exit = 0;
	
	int moves = 0;
	
	char in;
	
	while(exit == 0)
	{
		printf("MOVES: %d\n", moves);
		printf("======================================\n");
		
		for(int i = 0; i< 4; i++){
			printf("\n");
			for(int j = 0; j< 4; j++){
				printf("%d\t", a[i][j]);
			}
		}
		
		printf("\n{w,s,a,d,q}? ");
		scanf("%s", &in);
		
		switch(in){
			case 'w': 
				find_zero(arr)
				break;
			
			case 's': 
				
				break;
			case 'a': 
				
				break;
			case 'd': 
				
				break;
			case 'q': 
				exit = 1;
				break;							
				
		}

	}
	
	return 0;
}

