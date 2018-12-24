#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <string.h>


unsigned int min(unsigned int a, unsigned int b) {
    return a < b ? a : b;
}


size_t ld(char * s, char * t) {
    size_t n = strlen(s);
    size_t m = strlen(t);

    if (n == 0) {
        return m;
    }

    if (m == 0) {
        return n;
    }

    int dist[n + 1][m + 1];

    for (size_t i = 0; i <= n; i++) {
        dist[i][0] = i;
    }

    for (size_t j = 0; j <= n; j++) {
        dist[0][j] = j;
    }

    for (size_t i = 1; i <= n; i++) {
        for (size_t j = 1; j <= m; j++) {
            dist[i][j] = min(
                min(
                    dist[i - 1][j] + 1,
                    dist[i][j - 1] + 1
                ),
                dist[i - 1][j - 1] + (s[i - 1] != t[j - 1] ? 1 : 0)
            );
        }
    }

    return dist[n][m];
}

int main(int argc, char ** argv) {
    FILE * stations_file = fopen("stations", "r");

    char * stations[3000];

    char line[256];
    unsigned int s = 0;
    while (fgets(line, 256, stations_file)) {
        stations[s++] = strndup(line, strlen(line) - 1);
    }

    for (unsigned int i = 0; i < s; i++) {
        for (unsigned int j = i + 1; j < s; j++) {
            printf(
                "%zu\t%s\t%s\n",
                ld(stations[i], stations[j]),
                stations[i],
                stations[j]
            );
        }

    }


}
