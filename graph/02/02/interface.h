#pragma once

HWND createTable(HWND hWnd);
BOOL addColumn(HWND hwndTable, int columnAmount, WCHAR** columnName);
BOOL addItem(HWND hwndTable, int amountColumns, WCHAR** item);
BOOL searchItem(HWND hwndTable, int amountColumns, WCHAR** item);
void deleteItem(HWND hwndTable);

void fillRandom(HWND hwndTable);

void createUI(HWND hWnd);