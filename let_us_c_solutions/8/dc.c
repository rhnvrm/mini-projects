/*
 * dc.c
 *
 * Program to implement Sieve of Erastothenes
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

int main(int argc, char **argv)
{

	int sieve[101];

	//init
	for(int i = 1; i < 101; i++) sieve[i] = 1;

	//loop
	for(int i = 2; i < 101; i++){
		if(sieve[i] == 1){
			for(int j = i*i; j < 101; j+=i){
				if(sieve[j]%sieve[i] == 0){
					sieve[j] = 0;
				}
			}
		}
	}

	//output
	for(int i = 1; i < 101; i++)
		if(sieve[i]==1)printf("%d\t", i);


	return 0;
}

