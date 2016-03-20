#pragma once

#include <Commdlg.h>

char* get_model_name();
int load_model(struct view* View);

int transfer(struct view* View);
int read_scene(struct view* View);
int read_nodes_and_edges_number(struct view* View);
int read_nodes(struct view* View);
int read_edges(struct view* View);
FILE* open_model(char* modelFileName);
void close_model(FILE* modelFile);