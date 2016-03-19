#pragma once

#include <Commdlg.h>

char* get_model_name();
int load_model(char* modelFile);

int transfer(FILE* modelFile);
int read_scene(FILE* modelFile, struct view* View);
int read_nodes_and_edges_number(FILE* modelFile, struct view* View);
FILE* open_model(char* modelFileName);
