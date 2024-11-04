#include <stdio.h>
#include <assert.h>

char size(int cms) {
    char sizeName = '\0';
    if(cms < 38) {
        sizeName = 'S';
    } else if(cms > 38 && cms < 42) {
        sizeName = 'M';
    } else if(cms > 42) {
        sizeName = 'L';
    }
    return sizeName;
}

int main() {
    assert(size(36) == 'S');    // should pass
    assert(size(38) == 'M');    // should fail
    assert(size(40) == 'M');    // should pass
    assert(size(42) == 'L');    // should fail
    assert(size(43) == 'L');    // should pass
    printf("All is well (maybe!)\n");
    return 0;
}
