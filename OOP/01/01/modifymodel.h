#pragma once

void modify_model(struct model* modelSettings, struct modification_params modificationSettings);

void rot_xz(struct model* modelSettings, struct modification_params modificationSettings);
void rot_xy(struct model* modelSettings, struct modification_params modificationSettings);
void zoom(struct model* modelSettings, struct modification_params modificationSettings);

enum modification_type
{
	ROTATE_XZ, ROTATE_XY, ZOOM
};

struct modification_params
{
	enum modification_type type;
	double param;
};