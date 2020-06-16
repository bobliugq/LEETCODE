// rand7() to rand10() uniform random

int rand10() {
    while (true) {
        int rand48 = 7 * (rand7() - 1) + (rand7() - 1);
        if (rand48 < 40) return rand48 % 10 + 1; 
    }
}
