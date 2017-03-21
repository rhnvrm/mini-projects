/*
 * da.c
 * Input: 25 Numbers stored in a array
 * Output: #Positive, #Negative, #Even, #Odd
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

int main()
{
	
	int input[30];
	
	for(int i = 0; i < 25; i++)
	{
		scanf("%d", &input[i]);
	}
	
	int p = 0, n = 0, o = 0, e = 0;
	
	for(int i = 0; i < 25; i++)
	{
		if(input[i] >= 0) p++;
		else n++;
		if(input[i] % 2 == 0) e++;
		else o++;
	}
	
	printf("#+ : %d\n#- : %d\n#e : %d\n #o : %d\n", p, n ,e, o);
	return 0;
}

