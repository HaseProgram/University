#pragma once

#include <Commdlg.h>

char* get_model_name();
int load_model(struct model* modelSettings, char* filename);

int transfer(struct model* modelSettings, FILE* modelFile);
int read_nodes_and_edges_number(struct model* modelSettings, FILE* modelFile);
int read_nodes(struct model* modelSettings, FILE* modelFile);
int read_edges(struct model* modelSettings, FILE* modelFile);

void close_model(struct model* modelSettings, char** filename);

FILE* open_modelfile(char* modelFileName);
void close_modelfile(FILE* modelFile);

enum load_type
{
	FROM_FILE, FROM_DATABASE
};

static struct stream
{
	enum load_type type;
} Stream;