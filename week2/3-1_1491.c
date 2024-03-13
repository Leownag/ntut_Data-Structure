double average(int* salary, int salarySize) {
    int min = salary[0];
    int max = salary[0];
    int sum = salary[0];

    for (int i = 1; i < salarySize; i++) {
        int curr = salary[i];
        sum += curr;
        if (curr < min)
            min = curr;
        if (curr > max)
            max = curr;
    }
    return (double)(sum - min - max) / (salarySize - 2);
}