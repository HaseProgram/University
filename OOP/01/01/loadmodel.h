#pragma once

#include <Commdlg.h>

char* get_model_name();
int load_model(struct view* View);

int transfer(struct view* View);
int read_scene(struct view* View);
int read_nodes_and_edges_number(struct view* View);
int read_nodes(struct view* View);
int read_edges(struct view* View);
void close_model(struct view* View);
FILE* open_modelfile(char* modelFileName);
void close_modelfile(FILE* modelFile);