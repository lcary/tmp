void stackoverflow();

int main()
{
    // Stack overflow is [a] cause of the resulting segmentation fault.
    stackoverflow();
    return 0;
}

void stackoverflow() {
    stackoverflow();
}
