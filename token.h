#pragma once

typedef enum {
	TTINTEGER,
	TTOP,
	TTPARENTHESIS,
	TTIDENTIFIER,
} tokenType;

typedef struct {
	tokenType type;
	union {
		char c;
		int integer;
		char* str;
	};
} token;

void cleanToken(token* tok);
