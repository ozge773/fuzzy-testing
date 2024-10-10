#include "afl-fuzz.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct custom_mutator_state 
{
	afl_state_t *afl;
	uint8_t *buf;
	size_t buf_size;
	size_t bits_flipped;
} custom_mutator_state_t;


custom_mutator_state_t *afl_custom_init(afl_state_t *afl, unsigned int seed) 
{
	srand(seed);
	custom_mutator_state_t *state = calloc(1, sizeof(custom_mutator_state_t));
  
	if (!state) 
		return NULL;
  
	state->buf = malloc(MAX_FILE);
	if (!state->buf) 
	{
		perror("afl_custom_init alloc");
		free(state);
		return NULL;
	}
	state->buf_size = MAX_FILE;
	state->bits_flipped = 0;
	state->afl = afl;
	return state;
}

size_t afl_custom_fuzz(custom_mutator_state_t *state, uint8_t *buf, size_t buf_size,
                       uint8_t **out_buf, uint8_t *add_buf, size_t add_buf_size,
                       size_t max_size) 
{
  
	if (max_size > state->buf_size) 
	{
		uint8_t *ptr = realloc(state->buf, max_size);
		if (!ptr) 
			return 0;
		state->buf = ptr;
		state->buf_size = max_size;
	}
  
	if (state->bits_flipped == 0)
		memcpy(state->buf, buf, buf_size);
  
	state->buf[(rand() % buf_size)] ^= (1 << (rand() % 8));  
	state->bits_flipped++;
	*out_buf = state->buf;

	return buf_size;
}

void afl_custom_deinit(custom_mutator_state_t *state) 
{
	free(state->buf);
	free(state);
}
