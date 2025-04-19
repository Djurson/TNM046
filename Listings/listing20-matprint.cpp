// Print the elements of a matrix m
void mat4print(const std::array<float, 16>& m) {
    printf("Matrix:\n");
    printf("%6.2f %6.2f %6.2f %6.2f\n", m[0], m[4], m[8], m[12]);
    printf("%6.2f %6.2f %6.2f %6.2f\n", m[1], m[5], m[9], m[13]);
    printf("%6.2f %6.2f %6.2f %6.2f\n", m[2], m[6], m[10], m[14]);
    printf("%6.2f %6.2f %6.2f %6.2f\n", m[3], m[7], m[11], m[15]);
    printf("\n");
}
