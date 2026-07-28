#include <stdio.h>
#include <string.h>

typedef struct {
    const char *name; 
    const char *value; 
} Variable; 

/*
Variable vars[] = { 
    {"time", "09:45 PM"}, 
    {"charge", "87"}, 
    {"status", "Connected"}, 
};*/


const char* lookup(const char *name, Variable vars[], int count)
{
    for (int i = 0; i < count; i++) {
        if (strcmp(name, vars[i].name) == 0)
            return vars[i].value;
    }

    return NULL;
}

void substitute(const char *input, char *output, Variable vars[], int count)
{

    while (*input) {

        if (*input == '(') {

            const char *end = strchr(input, ')');

            if (end != NULL) {

                char key[32];

                size_t len = end - input - 1;
                if(len >= sizeof(key)) len = sizeof(key) - 1;

                memcpy(key, input + 1, len);
                key[len] = '\0';

                const char *value = lookup(key, vars, count);

                if (value) {
                    while (*value)
                        *output++ = *value++;
                } else {
                    /* Unknown placeholder, copy it unchanged */
                    while (input <= end)
                        *output++ = *input++;
                    continue;
                }

                input = end + 1;
                continue;
            }
        }

        *output++ = *input++;
    }

    *output = '\0';
}