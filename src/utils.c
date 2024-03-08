#include "utils.h"

void _input_path(char *path) { scanf("%1023s", path); }

int _validate_path(char *path) {
    FILE *f1 = fopen(path, "r");
    int res = 1;
    if (f1 == NULL) {
        res--;
    } else {
        fclose(f1);
    }
    return res;
}

void _check_duplicates(char *path1, char *path2) {
    FILE *f1 = fopen(path1, "r");
    FILE *f2 = fopen(path2, "r");
    char line1[MAX_STR_LEN] = {0};
    char line2[MAX_STR_LEN] = {0};
    int res = 1;
    while (fgets(line1, MAX_STR_LEN - 1, f1) != NULL || fgets(line2, MAX_STR_LEN - 1, f2) != NULL) {
        if (strcmp(line1, line2) != 0) {
            res--;
        }
    }
    if (res == 1) {
        remove(path2);
    }
    fclose(f1);
    fclose(f2);
}

void exception() {
    fprintf(stderr, "Puck you, Verter!");
    exit(EXIT_FAILURE);
}

void find_duplicates() {
    char path1[MAX_STR_LEN] = {0};
    char path2[MAX_STR_LEN] = {0};
    _input_path(path1);
    _input_path(path2);
    if (!_validate_path(path2) || !_validate_path(path2)) {
        exception();
    } else {
        _check_duplicates(path1, path2);
    }
}