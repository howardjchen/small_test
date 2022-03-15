/*********************************************************************
 *                               Apache License
 *                          Version 2.0, January 2004
 *                       http://www.apache.org/licenses/ 
 * test_mem_leak.c
 *
 * Copyright 2022 Copyright Howard Chen
 * Author: Howard Chen (s880367@gmail.com)
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 **********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void assign(char **f) {
	char *b = "123";

	for(int i = 0; i < 10; i++) {
		f[i] = strdup(b); //4 bytes
		printf("%p : addr of f[%d]: %p with val: %s\n", &f[i], i, f[i], f[i]);
	}
}

int main(){
	int i = 0;	
	char **f, **g;

	f = malloc(10 * sizeof(f));
	g = malloc(10 * sizeof(g));

	for(i = 0; i < 10; i++) {
		printf("%p : addr of f[%d]: %p with val: %s\n", &f[i], i, f[i], f[i]);
	}

	printf("assign....\n");
	assign(f);	

	for (i = 0; i < 10; i++){
    	g[i] = f[i];
	}

	printf("after assign...\n");
	for(int j = 0; j < 10; j++){
		printf("%p : addr of g[%d]: %p with val: %s\n", &g[j], j, g[j], g[j]);
	}

	printf("after free\n");
	free(f);

	for(i = 0; i < 10; i++){
		free(f[i]);
		printf("addr of g[%d]: %p with val: %s\n", i, g[i], g[i]);
	}
	free(g);
	
	return 0;

}
