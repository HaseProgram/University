#pragma once

void modify_model(struct model* modelSettings, struct modification_params modificationSettings);

void rot_xz(struct model* modelSettings, struct modification_params modificationSettings);
void rot_xy(struct model* modelSettings, struct modification_params modificationSettings);
void zoom(struct model* modelSettings, struct modification_params modificationSettings);