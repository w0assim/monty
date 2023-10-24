#include "monty.h"

bundle_t bundle;
/**
* main - program entry point for monty intepreter
*
* @argc: count of command line args
* @argv: vector of command line args
*
* Return: 0 always
*/
int main(int argc, char **argv)
{
	bundle.status =	bundle.line_number = 0;
	bundle.mode = _stack;
	bundle.stack = bundle.queue = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	bundle.file = fopen(argv[1], "r");

	if (!bundle.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(bundle.line_text, MAX_LINE_CHARS, bundle.file))
		execute();

	shutdown();
	return (0);
}
