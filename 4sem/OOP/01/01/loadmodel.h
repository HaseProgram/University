#pragma once

int load_model(struct model* modelSettings, char* filename);

int transfer(struct model* modelSettings, FILE* modelFile);
int read_nodes_and_edges_number(struct model* modelSettings, FILE* modelFile);
void free_edges(struct edge* edgeArray);
int allocate_edges(struct edge* edgeArray);
void free_nodes(struct node* nodeArray);
int allocate_nodes(struct node* nodeArray);
int read_nodes(struct model* modelSettings, FILE* modelFile);
int read_edges(struct model* modelSettings, FILE* modelFile);

int close_model(struct model* modelSettings, char** filename);

FILE* open_modelfile(char* modelFileName);
void close_modelfile(FILE* modelFile);

typedef FILE* LFILE;