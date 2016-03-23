#pragma once

#include <Commdlg.h>

char* get_model_name();
int load_model(struct model* modelSettings);

int transfer(struct model* modelSettings);
int read_nodes_and_edges_number(struct model* modelSettings);
int read_nodes(struct model* modelSettings);
int read_edges(struct model* modelSettings);
void close_model(struct model* modelSettings);
FILE* open_modelfile(char* modelFileName);
void close_modelfile(FILE* modelFile);