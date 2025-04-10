void AtoB() {
    int x = pop(StackA);   // Saca un elemento del stack A
    push(x, StackB);       // Agrega el elemento al stack B
}

void BtoA() {
    int x = pop(StackB);   // Saca un elemento del stack B
    push(x, StackA);       // Agrega el elemento al stack A
}
