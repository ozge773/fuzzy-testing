#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#define MAX_BUFFER_SIZE 16  

void string_processor(const char *input) 
{
	if (strlen(input) >= MAX_BUFFER_SIZE)
		return;

	if (input[0] >= 32 && input[0] <= 126)
		printf(input);

	if (input[0] >= 48)
	{
		char *dynamic_buffer = (char *)malloc(MAX_BUFFER_SIZE);
		strcpy(dynamic_buffer, input);
		free(dynamic_buffer); 
		printf("Use-after-free: %s\n", dynamic_buffer);
	}
}


int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) 
{
    if (Size <= 1 || Size > 256)
        return 0;  
   
    char *input = (char *)malloc(Size + 1);  
    memcpy(input, Data, Size);
    input[Size] = '\0'; 
    string_processor(input);
    free(input);

    return 0;
}