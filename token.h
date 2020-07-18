#pragma once

typedef enum {
	TTINTEGER,
	TTOP,
	TTPARENTHESIS,
} tokenType;

typedef struct {
	tokenType type;
	union {
		char c;
		int integer;
	};
} token;
